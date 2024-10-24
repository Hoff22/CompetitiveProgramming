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

void dfs(int u){
	seen[u] = true;

	for(int v : g[u]){
		if(!seen[v]){
			dfs(v);
		}	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, t;
	// int m;

	cin >> n >> t;
	// cin >> m;

	memset(seen, 0, sizeof(seen));

	for(int i = 1; i <= n-1; i++){
		int v;
		cin >> v;
		g[i].push_back(i+v);
		// g[v].push_back(u);
		// int w;
		// cin >> w;
		// g[u].push_back({v,w});
	}
	dfs(1);
	if(seen[t]){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}

    return 0;

}