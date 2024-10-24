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
int col[N+1];
    
int dfs(int u, int c){
	col[u] = c;

	for(int v : g[u]){
		if(col[v] == col[u]) return 1;
		if(col[v] == 0) if(dfs(v, c*-1)) return 1;
	}

	return 0;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
    	if(col[i] == 0){
    		if(dfs(i, 1)){
    			cout << "IMPOSSIBLE" << endl;
    			return;
    		}
    	}
    }

    for(int i = 1; i <= n; i++) cout << (col[i] == -1 ? 1 : 2) << " ";
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