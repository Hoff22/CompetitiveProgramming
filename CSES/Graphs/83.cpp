#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int N = 2500;
constexpr int M = 5000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;

typedef long long ll;

vector<pair<int, ll>> g[N + 1]; // (Input)
ll dist[N + 1];
bool seen[N + 1];
int n; // (Input)

/* O(V * E) - Returns true if there is a negative cycle somewhere in the graph. */
bool bellman_ford(int root) {
    bool converged = false;

    // Initializing.
    memset(dist, 0x3f, sizeof(dist));
    dist[root] = 0;

    // It takes at most n - 1 iterations to converge if there are no negative cycles in the graph.
    for (int i = 1; !converged and i <= n; i++) {
        converged = true;

        // For every vertex u.
        for (int u = 1; u <= n; u++) {
            // For every edge (u, v).
            for (int j = 0; j < g[u].size(); j++) {
                int v = g[u][j].first;
                ll w = g[u][j].second;

                // Trying to relax this edge.
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    converged = false;
                }
            }
        }
    }

    // Returns true if it didn't converge after n - 1 iterations.
    return !converged;
}

void dfs(int u){
	seen[u] = 1;
	for(auto [v,w] : g[u]){
		if(seen[v]) continue;
		dfs(v);
	}
}


void solve(){
	int m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		g[u].push_back({v,-w});
	}

	dfs(1);
	for(int i = 1; i <= n; i++){
		if(seen[i] == 0) g[i].clear();
	}

	for(int u = 1; u <= n; u++){
		for(int i = 1; i <= n; i++) seen[i] = 0;
		dfs(u);
		if(seen[n] == 0) g[u].clear();
	}

	if(bellman_ford(1)){
		cout << -1 << endl;
	}
	else{
		cout << -dist[n] << endl;
	}
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
