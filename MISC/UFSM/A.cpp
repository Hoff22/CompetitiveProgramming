#include <bits/stdc++.h>

#define N 100000
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
vector<int> ans;
int seen[N+1];

void dfs(int u){
	seen[u] = 1;
	for(int v : g[u]){
		if(!seen[v]) dfs(v);
	}
	ans.push_back(u);
}

void solve(){
	int n, m, k;

	cin >> n >> m >> k;

	set<pair<int,int>> s;

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		if(s.count({u,v})) continue;
		g[u].push_back(v);
	}

	for(int i = n; i >= 1; i--){
		if(seen[i]) continue;
		dfs(i);
	}
	reverse(ans.begin(), ans.end());

	for(int i : ans) cout << i << " ";
	cout << endl;

	sort(ans.begin(), ans.begin()+k);
	for(int i = 0; i < k; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
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