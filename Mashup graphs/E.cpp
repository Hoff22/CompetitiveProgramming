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
int seen[N+1];
// vector<pair<int,int>> g[N+1];
// 563

pair<long long,long long> dfs(int u){
	seen[u] = true;

	pair<long long,long long> r = {(long long)g[u].size(), 1ll};
	for(int v : g[u]){
		if(!seen[v]){
			pair<long long,long long> p = dfs(v);
			r.fi += p.fi;
			r.se += p.se;
		}
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
	int m;

	cin >> n;
	cin >> m;

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		// int w;
		// cin >> w;
		// g[u].push_back({v,w});
	}

	for(int i = 1; i <= n; i++){
		if(!seen[i]){
			pair<long long, long long> r = dfs(i);
			if(r.fi != r.se * (r.se-1)){
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";

    return 0;

}