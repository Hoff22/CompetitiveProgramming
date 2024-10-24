#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
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

// vector<int> g[N+1];
vector<pair<int,int>> g[N+1];
priority_queue<State> pq;
bool in_spt[N + 1];
int dist[N+1];
set<int> s;

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
				if (!in_spt[v] and max(dist[u], w) < dist[v]) {
					dist[v] = max(dist[u], w);
					pq.push({v, dist[v]});
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
	int m;
	int k;

	cin >> n;
	cin >> m;
	cin >> k;

	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		s.insert(x);
	}

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		// g[u].push_back(v);
		// g[v].push_back(u);
		int w;
		cin >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	memset(dist, 0x3f, sizeof(dist));

	dijkstra(*(s.begin()));

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(s.count(i)){
			ans = max(ans, dist[i]);
		}
	}

	for(int i = 0; i < k; i++){
		cout << ans << " ";
	}
	cout << endl;
	
    return 0;

}