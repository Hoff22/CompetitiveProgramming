#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

struct State {
	int u, d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

vector<pair<int, int>> g[N + 1]; // (Input)
priority_queue<State> pq;
bool in_spt[N + 1];
int dist[N + 1];

/* O(E + E * Log(V)). */
void dijkstra(int u) {
	// Initializing.
	memset(in_spt, false, sizeof(in_spt));
	memset(dist, 0x3f, sizeof(dist));

	// Initializing and pushing source vertex. Cost of adding the first vertex u to Shortest Path Tree is 0.
	dist[u] = 0;
	pq.push({u, 0});

	// While there are vertices to visit.
	while (!pq.empty()) {
		// Retrieving vertex u from current State.
		u = pq.top().u;
		pq.pop();

		// If vertex u still doesn't belong to Shortest Path Tree.
		if (!in_spt[u]) {
			// Vertex u now belongs to Shortest Path Tree.
			in_spt[u] = true;

			// For every vertex v adjacent to u.
			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].first;
				int w = g[u][i].second;

				// If a better path was found to add the vertex v to the Shortest Path Tree.
				if (!in_spt[v] and dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.push({v, dist[v]});
				}
			}
		}
	}
}

int d[N+1][N+1];

int newDist(int a, int b, int u, int v){
	return min(d[a][u] + d[v][b], d[b][u] + d[a][v]);
}

int main(){
	
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	vector<pair<int,int>> e;

	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		e.push_back({u,v});
	}



	for(int i = 1; i <= n; i++){
		dijkstra(i);
		for(int j = 1; j <= n; j++){
			d[i][j] = dist[j];
		}
	}

	vector<pair<int,int>> paths;
	for(int i = 0; i < k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		paths.push_back({a,b});
	}

	int ans = INF;
	for(int i = 0; i < m; i++){
		int cur = 0;
		for(auto p : paths){
			int a = p.first;
			int b = p.second;
			int u = e[i].first;
			int v = e[i].second;

			cur += min(d[a][b], newDist(a, b, u, v));
		}
		ans = min(ans, cur);
	}

	printf("%d\n", ans);

    return 0;

}