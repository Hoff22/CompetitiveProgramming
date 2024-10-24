#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 100000;
constexpr int M = 200000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;
 
int n, m;
vector<int> g[N+1];
vector<int> ans;
int seen[N+1]; 
int good = 1;

void dfs(int u){
	seen[u] = 1;
	for(int v : g[u]){
		if(seen[v] == 1){
			good = 0;
		}
		if(seen[v]) continue;
		dfs(v);
	}
	seen[u] = 2;
	ans.push_back(u);
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
 
 	for(int i = 1; i <= n; i++){
 		if(seen[i] == 0) dfs(i);
 	}

 	if(!good){
 		cout << "IMPOSSIBLE" << endl;
 		return;
 	}

 	reverse(ans.begin(), ans.end());
 	for(int i : ans) cout << i << " ";
 	cout << endl;
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