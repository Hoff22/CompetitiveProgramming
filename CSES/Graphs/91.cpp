#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;
 
int n, m;
constexpr int N = 100000;

struct State {
	int u;
	long long d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

vector<pair<int, long long>> g[N + 1]; // (Input)
priority_queue<State> pq;
bool in_spt[N + 1];
long long dist[N + 1];
long long amt[N + 1];
long long mx[N + 1];
long long mn[N + 1];

/* O(E + E * Log(V)). */
void dijkstra(int u) {
	// Initializing.
	memset(dist, 0x3f, sizeof(dist));
	memset(mn, 0x3f, sizeof(mn));
	memset(mx, -1, sizeof(mx));

	// Initializing and pushing source vertex. Cost of adding the first vertex u to Shortest Path Tree is 0.
	dist[u] = 0;
	amt[u] = 1;
	mx[u] = 0;
	mn[u] = 0;
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
				long long w = g[u][i].second;

				// If a better path was found to add the vertex v to the Shortest Path Tree.
				if (!in_spt[v] and dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					amt[v] = amt[u];
					mx[v] = mx[u]+1;
					mn[v] = mn[u]+1;
					pq.push({v, dist[v]});
				}
				else if(!in_spt[v] and dist[u] + w == dist[v]){
					amt[v] = (amt[v] + amt[u]) % MOD;
					mx[v] = max(mx[u]+1, mx[v]);
					mn[v] = min(mn[u]+1, mn[v]);
				}
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }
 	dijkstra(1);
 	cout << dist[n] << " " << amt[n] << " " << mn[n] << " " << mx[n] << "\n";
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