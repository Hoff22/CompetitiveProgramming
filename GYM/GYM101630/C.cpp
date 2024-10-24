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

vector<int> g[N+1];
vector<int> invg[N+1];
int seen[N+1];

set<pair<int,int>> used_e;

void dfs(int u, int inv){
	seen[u] = 1;

	if(inv){
		for(int v : invg[u]){
			if(!seen[v]){
				used_e.insert({v,u});
				dfs(v, inv);
			}
		}
	}
	else{
		for(int v : g[u]){
			if(!seen[v]){
				used_e.insert({u,v});
				dfs(v, inv);
			}
		}
	}

}

void solve(){
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		g[i].clear();
		invg[i].clear();
	}
	used_e.clear();

	vector<pair<int,int>> edges;

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		invg[v].push_back(u);
		edges.push_back({u,v});
	}

	memset(seen, 0, sizeof(seen));
	dfs(1, 0);
	memset(seen, 0, sizeof(seen));
	dfs(1, 1);

	int of = 2*n - (int)used_e.size();
 
	for(auto e : edges){
		if(used_e.count(e) == 0){
			if(of == 0){
				cout << e.fi << " " << e.se << endl;
			}
			else{
				of--;
			}
		}
	}
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