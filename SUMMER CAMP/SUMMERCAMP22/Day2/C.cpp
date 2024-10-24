#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

// If there are lots of parallel edges in the residual graph you can merge them to achieve a better runtime.
constexpr int INF = 0x3f3f3f3f; // Has to be greater or equal to maximum flow.
constexpr int N = 2 * 2000 + 3;
constexpr int FNN = N;

vector<pair<int, int>> g[FNN + 1]; // (Input) Original graph, g[u] stores pairs (v, capacity).
vector<pair<int, int>> r[FNN + 1]; // Residual graph, r[u] stores pairs (v, current capacity).
vector<int> flow[FNN + 1];         // Flow graph, f[u][i] stores the flow going through the edge (u, r[u][i]).
vector<int> rev[FNN + 1];          // Reverse edge mapping, rev[u][i] stores the index j such that u == r[r[u][i].first][j].first.
int level[FNN + 1];                // level[u] stores the distance from the source to u in the residual graph.
int p[FNN + 1]; // p[u] stores the index of the next relevant edge (u, r[u][p[u]].first) for the blocking flow DFS. Multiple pointers technique.
bool seen[FNN + 1];
int fnn; // (Input) Number of vertices in the flow network.

/* O(V + E) - Builds the level graph. */
bool bfs(int s, int t) {
    queue<int> q;

    // Clearing.
    memset(seen, false, sizeof(seen));

    // Initializing.
    level[s] = 0;
    seen[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // For every edge (u, v).
        for (int i = 0; i < r[u].size(); i++) {
            int v = r[u][i].first;
            int c = r[u][i].second; // Current capacity.

            // If it was not visited and we can push a positive amount of flow.
            if (!seen[v] and c > 0) {
                // Updating v.
                level[v] = level[u] + 1;
                seen[v] = true;

                if (v == t) { // Found a path from the source to the sink.
                    // We can already return because we won't use any other vertices from this same level other than the sink.
                    return true;
                }

                // Pushing v into the queue.
                q.push(v);
            }
        }
    }

    return false;
}

/* O(V + E) - Pushes the blocking flow using V pointers. */
int dfs(int u, int t, int f) {
    if (u == t) { // Found sink, pushed f.
        return f;
    }

    // For each edge (u, v).
    for (; p[u] < r[u].size(); p[u]++) {
        int v = r[u][p[u]].first;
        int c = r[u][p[u]].second;
        int pf;

        // If v was seen by the BFS, is in the next layer, the residual capacity is positive and pushed a positive amount of flow.
        if (seen[v] and level[v] == level[u] + 1 and c > 0 and (pf = dfs(v, t, min(f, c)))) {
            int pv = rev[u][p[u]]; // Reverse edge index.

            // Updating capacities in the residual graph.
            r[u][p[u]].second -= pf;
            r[v][pv].second += pf;

            // Updating flow graph.
            flow[u][p[u]] += pf;
            flow[v][pv] -= pf;

            // Returning the flow that was pushed. Next call to the DFS will go straight back to this edge, skipping saturated ones.
            return pf;
        }
    }

    // Didn't push any flow through u.
    return 0;
}

/* O(min(F, V * V) * E) such that F is the maximum flow.
   O(min(V^(2 / 3), sqrt(E)) * E) for networks in which every edge has capacity 1.
   O(sqrt(V) * E) for unit networks, networks in which every edge has an integer capacity and, apart from the sink and the source,
   every vertex has either a single incoming edge of capacity one or a single outgoing edge of capacity one. */
int dinic(int s, int t) {
    int ans, f;

    // Clearing.
    for (int u = 1; u <= fnn; u++) {
        flow[u].clear();
        rev[u].clear();
        r[u].clear();
    }
    memset(seen, false, sizeof(seen));

    // O(V + E) - Creating residual graph, reverse edge pointers and flow graph.
    for (int u = 1; u <= fnn; u++) {
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            int c = g[u][i].second;

            if (u != v) {                      // Ignoring self-loops.
                rev[u].push_back(r[v].size()); // Reverse edge reference.
                rev[v].push_back(r[u].size()); // Reverse edge reference.
                r[u].push_back({v, c});        // Adding edge (u, v).
                r[v].push_back({u, 0});        // Adding reverse edge (v, u).
                flow[u].push_back(0);          // Flow through edge (u, v).
                flow[v].push_back(0);          // Flow through edge (v, u).
            }
        }
    }

    ans = 0;

    // While I can improve the flow.
    while (bfs(s, t)) {
        // Clearing pointers.
        memset(p, 0, sizeof(p));

        // Pushing blocking flow.
        while ((f = dfs(s, t, INF))) {
            ans += f;
        }
    }

    return ans;
}

void solve(){

	int ans = 0;
	int n, m;
	scanf("%d %d", &n, &m);

	for (int u = 1; u <= fnn; u++) {
        g[u].clear();
        r[u].clear();
    }

	fnn = n + m + 2;

	for(int i = 1; i <= n; i++){
		int price;
		scanf("%d", &price);
		g[i+1].push_back({N-1, price});
		ans += price;
	}
	for(int i = 1; i <= m; i++){
		int value;
		scanf("%d", &value);
		g[1].push_back({i+n+1, value});
	}
	for(int i = 1; i <= m; i++){
		int q;
		scanf("%d", &q);
		for(int j = 0; j < q; j++){
			int k;
			scanf("%d", &k);

			g[i+n+1].push_back({k+1, INF});
		}
	}

	ans -= dinic(1, N-1);

	// printf("level:\n");
	// for(int i : level){
	// 	printf("%d\n", i);
	// }

	// printf("flow:\n");

	// for(auto& u : flow){
	// 	for(auto& v : u){
	// 		printf("%d %d : %d\n", &u - &flow[0], &v - &u[0] ,v);
	// 	}
	// }

	// printf("ans:\n%d\n", ans);

	printf("%d\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}