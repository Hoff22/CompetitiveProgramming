#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 500;
constexpr int M = 200000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;
 
vector<pair<int, long long>> g[N + 1]; // (Input)
long long dist[N + 1][N + 1];
 
/* O(E + E * Log(V)). */
void floyd(int n) {
	// Initializing.
	memset(dist, 0x3f, sizeof(dist));
 
	for(int i = 1; i <= n; i++){
		dist[i][i] = 0;
		for(auto [v,w] : g[i]){
			dist[i][v] = min(dist[i][v], w);
		}
	}
 
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
 
 
void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	
	for(int i = 0; i < m; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
 
	floyd(n);
 
	while(q--){
		int u, v;
		cin >> u >> v;
		if(dist[u][v] == 4557430888798830399) cout << -1 << endl;
		else{
			cout << dist[u][v] << endl;
		}
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