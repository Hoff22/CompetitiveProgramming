#include <bits/stdc++.h>

#define N 2000
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
int seen[N+1];
int dist[N+1];
int c1, c2;
vector<pair<int,int>> edges;

int dfs(int u, int s, int p){
	seen[u] = 1;
	dist[u] = INF;
	for(int v : g[u]){
		if(seen[v]){
			if(v == s and v != p){	
				return dist[u] = 1;
			}
			continue;
		}

		dist[u] = min(dist[u], dfs(v,s, u)+1);
	}

	return dist[u];
}

void mark(int u, int s, int p){
	seen[u] = 1;
	int y = 0;
	for(int v : g[u]){
		if(seen[v]){
			if(v == s and v != p){
				edges.push_back({u, s});
				c2 = u;
				return;
			}
			continue;
		}
		if(y == 0 or dist[v] < dist[y]) y = v;
	}

	if(u == s) c1 = y;

	edges.push_back({u, y});

	mark(y, s, u);
}

void solve(){
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	edges.clear();

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int u = 1; u <= n; u++){
		if(g[u].size() >= 4){
			memset(seen, 0, sizeof(seen));
			memset(dist, 0x3f, sizeof(dist));
			if(dfs(u, u, u) != INF){
				memset(seen, 0, sizeof(seen));
				mark(u,u,u);
				
				int f1, f2;
				f1 = f2 = 0;
				for(int v : g[u]){
					if(v != c1 and v != c2){
						if(f1){
							f2 = v;
							break;
						}
						f1 = v;
					}
				}

				edges.push_back({u,f1});
				edges.push_back({u,f2});

				cout << "YES" << endl << edges.size() << endl;
 
				for(auto e : edges){
					cout << e.fi << " " << e.se << endl;
				}

				return;
			}
		}
	}

	cout << "NO" << endl;
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