#include <bits/stdc++.h>

#define N 200000
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

vector<pair<int,int>> g[N+1];
int seen[N+1];
int ans;

void dfs(int u, int t, int r){
	seen[u] = 1;

	ans = max(ans, r);

	if(g[u].empty()) return;

	sort(g[u].begin(), g[u].end());

	for(auto e : g[u]){
		int v = e.se;
		int tn = e.fi;

		if(seen[v]) continue;
		if(tn < t){
			dfs(v, tn, r+1);
		}
		else{
			dfs(v, tn, r);
		}
	}
}


void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		g[i].clear();
		seen[i] = 0;
	}

	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;

		g[u].push_back({i+1, v});
		g[v].push_back({i+1, u});
	}

	ans = 0;
	dfs(1,0,1);

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