#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<pair<int,int>> g[N+1];
int col[N+1];
int ans[N+1];

pair<int,int> dfs(int u, int k){
	// cout << " " << u << " = " << col[u] << endl; 
	int a = (col[u] == 0), b = (col[u] == 1);
	for(auto [v,w] : g[u]){
		if(col[v] != -1){
			if((w>>k) & 1){
				if(col[v] == col[u]) return {-1,-1};
			} 
			else{
				if(col[v] != col[u]) return {-1,-1};
			}
		}
		else{
			col[v] = ((w>>k) & 1) ? !col[u] : col[u];
			int ca,cb;
			tie(ca,cb) = dfs(v,k);
			if(ca == -1) return {-1,-1};
			a += ca; b += cb;
		}
	}
	return {a,b};
}

void dfs2(int u, int c, int k){
	if(col[u] == c){
		ans[u] += (1<<k);
	}
	col[u] = 3;
	for(auto [v,ignore] : g[u]){
		if(col[v] == 3) continue;
		dfs2(v,c,k);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	for(int i = 30; i >= 0; i--){
		for(int u = 1; u <= n; u++) col[u] = -1;

		for(int u = 1; u <= n; u++){
			if(col[u] == -1){
				int a,b;
				col[u] = 0;
				tie(a,b) = dfs(u,i);

				if(a == -1){
					cout << -1 << endl;
					return;
				}
				else{
					if(a < b){
						dfs2(u,0,i);
					}
					else{
						dfs2(u,1,i);
					}
				}
			}
		}
	}

	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
    return 0;
}