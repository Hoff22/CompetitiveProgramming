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
int c[N+1];
bool seen[N+1];
// vector<pair<int,int>> g[N+1];

int dfs(int u){
	seen[u] = true;

	int r = c[u];
	for(int v : g[u]){
		if(!seen[v]){
			r = min(r, dfs(v));
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

	memset(seen, 0, sizeof(seen));

	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		// int w;
		// cin >> w;
		// g[u].push_back({v,w});
	}

	long long ans = 0;
	for(int i = 1; i <= n; i++){
		if(!seen[i]){
			ans += (long long)dfs(i);
		}
	}

	cout << ans << endl;

    return 0;

}