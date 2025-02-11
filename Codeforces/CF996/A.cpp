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

constexpr int mod = 998244353;

int inv(int a, int m) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;
}

int mult(int a, int b, int m){
	return (1ll * a * b) % m;
}

int div(int a, int b, int m){
	return mult(a, inv(b, m) % m, m) % m;
}

vector<int> g[N+1];

int cl[N+1];

vector<int> ans;

void dfs2(int u, int p = 0){
	if(g[u].size() == 1 and p){
		cl[u] = 0;
		return;
	}

	cl[u] = 0x3f3f3f3f;

	for(int v : g[u]){
		if(v == p) continue;
		dfs2(v, u);
		cl[u] = min(cl[u], cl[v] + 1);
	}
}	

void dfs(int u, int p = 0, int h = 0, int d = 0){
	ans[u] = mult(ans[h],div(cl[u], (cl[u] + d) % mod, mod),mod) % mod;

	if(g[u].size() == 2 and p){
		int v = g[u][ g[u][0] == p ];
		dfs(v, u, h, d+1);
		return;
	}

	for(int v : g[u]){
		if(v == p) continue;
		dfs(v, u, u, 1);
	}
}

void solve(){
	int n;
	cin >> n;

	ans.assign(n+1,1);
	for(int i = 1; i <= n; i++) g[i].clear();

	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs2(1);
	dfs(1);

	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
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