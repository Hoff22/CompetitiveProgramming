#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

vector<pair<int,int>> g[N+1];
bool seen[N+1];
int n, m;

void dfs(int u, int target, int t){
	seen[u] = true;

	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i].first;
		int w = g[u][i].second;


		if(!seen[v] and w <= t){
			dfs(v, target, t);
		}
	}
}

int main(){
	
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int u,v,w;

		scanf("%d%d%d", &u, &v, &w);

		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	int l, r;
	int mid;

	l = 1;
	r = MAX;

	while(l < r){
		mid = l + (r - l) / 2;

		memset(seen, 0, sizeof(seen));
		dfs(0, n-1, mid);

		if(seen[n-1]){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}

	printf("%d\n", r);

	return 0;
}

// 4 3 - 0.75 seg
// 5 2 - 0.20 seg
// 6 1 - 0.16 seg + (0.2 * 5) = 1 + 1 - 1.2 = 0.8

// 4 2.2 - 0.55 seg
// 5 0.0 - 0.00 seg
// 6 0.8 - 0.13 seg