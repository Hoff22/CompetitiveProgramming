#include <bits/stdc++.h>

#define N 1000
#define MAX 10000000000
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

struct edge{
	int u, v, w;

	bool operator < (const edge b) const{
		return w < b.w;
	}
};

vector<int> g[N];
edge e[1000000];
int seen[N];
int n, m;

void dfs(int u, int target){
	seen[u] = true;

	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];

		if(!seen[v]){
			dfs(v, target);
		}
	}
}

int main(){
	
	scanf("%d %d", &n, &m);
	long long ans;

	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);

		e[i] = {u, v, w};
	}

	sort(e, e+m);//M*Log(M)  10^5

	ans = 0;
	for(int i = 0; i < m; i++){ // 10^8
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;

		if(ans != w){
			ans = w;
		}
		
		g[u].push_back(v);
		g[v].push_back(u);

		memset(seen, 0, sizeof(seen));
		dfs(0, n-1);

		if(seen[n-1]) break;
	}

	printf("%lld\n", ans);

	return 0;
}

// 4 3 - 0.75 seg
// 5 2 - 0.20 seg
// 6 1 - 0.16 seg + (0.2 * 5) = 1 + 1 - 1.2 = 0.8

// 4 2.2 - 0.55 seg
// 5 0.0 - 0.00 seg
// 6 0.8 - 0.13 seg