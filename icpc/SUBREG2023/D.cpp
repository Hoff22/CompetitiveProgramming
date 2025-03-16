#include <bits/stdc++.h>

#define N 300
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

vector<int> g[N+1];
int dist[2][N+1][N+1];


bool seen[N+1];
// Discovery Time:
int tin[N+1];
// Lowest tin achivable by node v:
int low[N+1];
// Bridges:
bool bridge[N+1][N+1];

int timer = 0;

// O(N+M);
void tarjan(int u, int p){

	seen[u] = true;

	tin[u] = low[u] = timer++;

	// cout << u << " " << tin[u] << " " << low[u] << endl;

	for(int v : g[u]){
		if(v == p) continue;
		if(!seen[v]){
			//parent[v] = u;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			// u->v is a bridge and u is not a leaf:
			if(low[v] > tin[u] and g[u].size() > 0){
				// cout << u << " " << v << " bridge!" << endl;
				bridge[u][v] = 1;
				bridge[v][u] = 1;
			}
		}// v is a back-edge:
		else{
			low[u] = min(tin[v], low[u]);
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;

	memset(dist, 0x3f, sizeof(dist));

	for(int i = 1; i <= n; i++) dist[0][i][i] = dist[1][i][i] = 0;

	vector<pair<int,int>> ps;

	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;

		ps.push_back({u,v});

		g[u].push_back(v);
		g[v].push_back(u);

		dist[0][u][v] = w;
		dist[0][v][u] = w;
	}

	tarjan(1, 0);

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == k or j == k or i == j) continue;
				if(dist[0][i][k] + dist[0][k][j] <= dist[1][i][j]){
					dist[1][i][j] = dist[0][i][k] + dist[0][k][j];
					cout << i << ">" << k << ">" << j << " " << dist[0][i][k] << " + " << dist[0][k][j] << endl;
				}
				if(dist[0][i][k] + dist[0][k][j] <= dist[0][i][j]){
					dist[0][i][j] = dist[0][i][k] + dist[0][k][j];
				}
			}
		}
	}

	for(auto [u,v] : ps){
		if(bridge[u][v]) cout << -1 << endl;
		else cout << dist[1][u][v] << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    solve();

    return 0;

}