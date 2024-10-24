#include <bits/stdc++.h>

#define MAX 10000000
#define E 0.0000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first
#define pi 3.1415926535897932384626433

using namespace std;

vector<int> g[N+1];
int p[N+1];
int sz[N+1];

void dfs(int u, int par){
	sz[u] = 1;
	for(int v : g[u]){
		if(v == par) continue;
		p[v] = u;
		dfs(v);
		sz[u] += sz[v];
	}
}

long long solve(int u){
	int res = 0;

	for(int v : g[u]){
		if(v == p[u]) continue;

		res += solve(v);
	}

	return min(res, sz[u]);
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);

}