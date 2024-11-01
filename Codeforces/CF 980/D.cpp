#include <bits/stdc++.h>

#define N 400000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct State {
	int u;
	long long d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

int n;
vector<pair<int, long long>> g[N + 1]; // (Input)
priority_queue<State> pq;
bool in_spt[N + 1];
long long dist[N + 1];

/* O(E + E * Log(V)). */
void dijkstra(int u) {
	// Initializing.
	for(int i = 0; i <= n; i++){
		in_spt[i] = 0;
		dist[i] = INFll;
	}

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
				if (!in_spt[v] and dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.push({v, dist[v]});
				}
			}
		}
	}
}

void solve(){
	cin >> n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		g[i].clear();
		cin >> a[i];
		if(i > 1) g[i].push_back({i-1,0});
	}
	for(int i = 1; i <= n; i++){
		int b; cin >> b;
		if(b <= i) continue;
		g[i].push_back({b, a[i]});
	}

	dijkstra(1);

	ll sum = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i];
		ans = max(ans, sum - dist[i]);
	}

	cout << ans << endl;
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