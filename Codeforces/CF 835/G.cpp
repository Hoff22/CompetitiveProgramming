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

vector<pair<int,int>> g[N+1];
set<int> s;
int distB[N+1];
int n, a, b;

void dfs(int u, int p, int d){
	distB[u] = d;
	if(u != b) s.insert(distB[u]);

	for(auto e : g[u]){
		int v = e.fi;
		int w = e.se;

		if(v == p) continue;

		dfs(v, u, d ^ w);
	}
}

bool dfs2(int u, int p, int d){
	if(s.count(d) or u == b){
		//printf("achou D igual\n");
		return true;
	}

	bool r = false;
	for(auto e : g[u]){
		int v = e.fi;
		int w = e.se;

		if(v == p) continue;
		if(v == b and (d ^ w) != 0) continue;

		r |= dfs2(v, u, d ^ w);
	}

	return r;
}

void solve(){
	scanf("%d %d %d", &n, &a, &b);

	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i <= n; i++) distB[i] = 0;
	s.clear();

	for(int i = 1; i < n; i++){
		int u, v, w;

		scanf("%d %d %d", &u, &v, &w);

		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	dfs(b, b, 0);

	// for(int i = 1; i <= n; i++){
	// 	printf("%d ", distB[i]);
	// }
	// printf("\n");

	if(dfs2(a,a,0)){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}