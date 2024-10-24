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

typedef long long ll;

ll a[N+1];
ll sz[N+1];
ll ans[N+1];
vector<int> g[N+1];

void dfs(int u, int p){
	ans[u] = 0;
	sz[u] = 1;
	for(int v : g[u]){
		if(v == p){
			continue;
		}

		dfs(v, u);
		sz[u] += sz[v];
	}
	for(int v : g[u]){
		if(v == p) continue;
		ans[u] += ans[v] + (a[v] ^ a[u]) * sz[v];
	}
}

void dfs2(int u, int p, int bs){
	if(p) ans[u] = ans[p] + (a[p] ^ a[u]) * bs - (a[p] ^ a[u]) * sz[u];
	for(int v : g[u]){
		if(v == p) continue;
		dfs2(v, u, bs + sz[u] - sz[v]);
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		g[i].clear();
		ans[i] = 0;
	}

	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);
	dfs2(1, 0, 0);

	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
}

/*
1 2 3 5 6 7 8
      4 5 6 7

*/

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