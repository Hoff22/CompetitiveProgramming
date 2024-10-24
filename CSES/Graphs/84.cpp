#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int N = 100000;
constexpr int M = 200000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;

typedef long long ll;


struct State {
	int u;
	long long d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

vector<pair<int, long long>> g[2][N + 1]; // (Input)
priority_queue<State> pq;
bool in_spt[2][N + 1];
long long dist[2][N + 1];

/* O(E + E * Log(V)). */
void dijkstra(int u, int p) {
	// Initializing.
	memset(in_spt[p], false, sizeof(in_spt[p]));
	memset(dist[p], 0x3f, sizeof(dist[p]));

	// Initializing and pushing source vertex. Cost of adding the first vertex u to Shortest Path Tree is 0.
	dist[p][u] = 0;
	pq.push({u, 0});

	// While there are vertices to visit.
	while (!pq.empty()) {
		// Retrieving vertex u from current State.
		u = pq.top().u;
		pq.pop();

		// If vertex u still doesn't belong to Shortest Path Tree.
		if (!in_spt[p][u]) {
			// Vertex u now belongs to Shortest Path Tree.
			in_spt[p][u] = true;

			// For every vertex v adjacent to u.
			for (int i = 0; i < g[p][u].size(); i++) {
				int v = g[p][u][i].first;
				long long w = g[p][u][i].second;

				// If a better path was found to add the vertex v to the Shortest Path Tree.
				if (!in_spt[p][v] and dist[p][u] + w < dist[p][v]) {
					dist[p][v] = dist[p][u] + w;
					pq.push({v, dist[p][v]});
				}
			}
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		g[0][u].push_back({v,w});
		g[1][v].push_back({u,w});
	}

	dijkstra(1,0);
	dijkstra(n,1);

	ll ans = 0x3f3f3f3f3f3f3f3f;
	for(int u = 1; u <= n; u++){
		for(auto [v,w] : g[0][u]){
			ans = min(ans, dist[0][u] + dist[1][v] + w/2);
		}
	}

	cout << ans << endl;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}
