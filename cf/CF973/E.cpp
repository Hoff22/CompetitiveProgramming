#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

typedef long long ll;

struct State {
	int u;
	long long d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

vector<pair<int, long long>> g[2*N + 1]; // (Input)
priority_queue<State> pq;
bool in_spt[2*N + 1];
int n,m,h;

/* O(E + E * Log(V)). */
void dijkstra(int u, vector<ll>& dist) {
	// Initializing.
	for(int i = 0; i <= 2*n; i++) in_spt[i] = 0;

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
				long long w = g[u][i].second;

				// If a better path was found to add the vertex v to the Shortest Path Tree.
				if (!in_spt[v]) {
					if(dist[u] + w < dist[v]){
						dist[v] = dist[u] + w;
						pq.push({v, dist[v]});
					}
				}
			}
		}
	}
}

void solve(){
	cin >> n >> m >> h;
	for(int i = 1; i <= n; i++){
		g[i].clear();
		g[i+n].clear();
	}
	for(int i = 1; i <= h; i++){
		int x; cin >> x;
		g[x].push_back({x+n,0});
	}
	for(int i = 0; i < m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		g[u+n].push_back({v+n,w/2});
		g[v+n].push_back({u+n,w/2});
	}

	vector<ll> d1(2*n+1,0x3f3f3f3f3f3f3f3f), d2(2*n+1,0x3f3f3f3f3f3f3f3f);
	dijkstra(1,d1);	
	dijkstra(n,d2);

	ll ans = 0x3f3f3f3f3f3f3f3f;

	for(int i = 1; i <= n; i++){
		ans = min(ans, max(
			min(d1[i], d1[i+n]),
			min(d2[i], d2[i+n])
		));
	}	

	cout << (ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}