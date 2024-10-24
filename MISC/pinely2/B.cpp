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

void solve(){
	int n;
	cin >> n;

	vector<vector<int>> g(n+1, vector<int>());

	set<int> seen;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		if(seen.count(x-1)){
			g[x-1].push_back(x);
		}
		seen.insert(x);
	}

	vector<int> vis(n+1);
	function<void(int)> dfs = [&](int u){
		vis[u] = 1;
		for(int v : g[u]){
			if(vis[v]) continue;
			dfs(v);
		}
	};

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i] == 0){
			ans++;
			dfs(i);
		}
	}

	cout << ans-1 << endl;
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