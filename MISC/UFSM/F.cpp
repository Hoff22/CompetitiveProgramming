#include <bits/stdc++.h>

#define N 3000
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

vector<pair<int, long long>> g[N + 1]; // (Input)
long long val[N+1];
long long dist[N + 1];
int n; // (Input)


/* O(V * E) - Returns true if there is a negative cycle somewhere in the graph. */
bool bellman_ford(int u) {
    bool converged = false;

    // Initializing.
    memset(dist, 0x3f, sizeof(dist));
    dist[u] = -val[u];

    // It takes at most n - 1 iterations to converge if there are no negative cycles in the graph.
    for (int i = 1; !converged and i <= n; i++) {
        converged = true;

        // For every vertex u.
        for (int u = 1; u <= n; u++) {
            // For every edge (u, v).
            for (int j = 0; j < g[u].size(); j++) {
                int v = g[u][j].first;
                long long w = g[u][j].second;

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

void solve(){
	cin >> n;

	for(int i = 1; i <= n; i++) cin >> val[i];
	
	for(int i = 1; i <= n; i++){
		int m;
		cin >> m;
		vector<int> aux;
		for(int j = 0; j < m; j++){
			int v; cin >> v;
			aux.push_back(v);
		}
		sort(aux.begin(), aux.end());
		aux.resize(unique(aux.begin(), aux.end()) - aux.begin());
		for(int v : aux) g[i].push_back({v, -val[v]});
	}

	if(bellman_ford(1)){
		cout << "Panteao da felicidade suprema" << endl;
		return;
	}

	vector<long long> best(n+1);
	for(int i = 1; i <= n; i++){
		best[i] = val[i];
	}

	long long ans = -0x3f3f3f3f3f3f3f3f;
	long long mans = 0;

	for(int i = 1; i <= n; i++){
		for(int u = 1; u <= n; u++){
		
			long long res = 0;
			for(auto [v,w] : g[u]){
				res = max(res, best[v]);
			}

			best[u] = res + val[u];

			if(best[u] > ans or (best[u] == ans and u < mans)){
				ans = best[u];
				mans = u;
			}
		}
	}

	cout << mans << " " << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}