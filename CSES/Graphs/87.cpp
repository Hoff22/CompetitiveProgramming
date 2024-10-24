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
int col[N+1];
 
int dfs(int u){
	col[u] = 1;
 
	for(int v : g[u]){
		if(col[v] == 1){
			return v;
		}
		if(col[v] == 2) continue;
		int k = dfs(v);
		if(k) return k;
	}

	col[u] = 2;
 
	return 0;
}
 
int dfs2(int u, int i){
	if(u == i and col[u] == 3){
		ans.push_back(u);
		return 1;
	}
 
	if(col[u] == 3){
		return 0;
	}
	
	col[u] = 3;
 
	for(int v : g[u]){
		if(dfs2(v, i)){
			ans.push_back(u);
			return 1;
		}
	}
 
	return 0;
}
 
void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
 
 
    for(int i = 1; i <= n; i++){
    	if(col[i] == 0){
    		int k = dfs(i);
    		if(k){
    			dfs2(k, k);
    			break;
    		}
    	}
    }
 
    if(ans.empty()){
    	cout << "IMPOSSIBLE" << endl;
    }
    else{
    	cout << ans.size() << endl;
    	reverse(ans.begin(), ans.end());
    	for(int i : ans) cout << i << " ";
    	cout << endl; 
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