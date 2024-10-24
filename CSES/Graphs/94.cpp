#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 200000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;

vector<int> g[N+1];
int seen[N+1];
int sz[N+1];

int dfs2(int u, int d){
	int v = g[u][0];
	seen[u] = 2;
	// cout << "\t" << u << endl;
	if(seen[v] == 2) return sz[u] = d;
	return sz[u] = dfs2(v, d+1); 	
}
void dfs(int u){
	int v = g[u][0];
	seen[u] = 1;
	// cout << u << endl;
	if(seen[v] == 1){
		dfs2(v, 1);
	}
	else if(seen[v] == 0) dfs(v);

	seen[u] = 2;

	if(!sz[u]) sz[u] = sz[v] + 1;
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		g[i].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		if(!seen[i]) dfs(i);
	}

	// dfs(3);

	for(int i = 1; i <= n; i++){
		cout << sz[i] << " ";
	}
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