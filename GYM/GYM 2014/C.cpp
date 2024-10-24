#include <bits/stdc++.h>

#define N 500
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

vector<int> g[N+1];
int m[N+1]; // onde esta no map
int ages[N+1]; // idade de x
int seen[N+1];

int dfs(int u){
	seen[u] = 1;
	int r = ages[m[u]];
	for(int v : g[u]){
		if(!seen[v]){
			r = min(r, dfs(v));
		}
	}
	return r;
}

int main(){
	
	int n, e, t;
	scanf("%d %d %d", &n, &e, &t);

	for(int i = 1; i <= n; i++){
		scanf("%d", &ages[i]);
		m[i] = i;
	}

	for(int i = 0; i < e; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[v].push_back(u);
	}

	for(int i = 0; i < t; i++){
		char q;
		scanf(" %c", &q);
		if(q == 'T'){ // mudanca
			int x, y;
			scanf("%d %d", &x, &y);
			int a = 1;
			for(; a <= n; a++) if(m[a] == x) break;
			int b = 1;
			for(; b <= n; b++) if(m[b] == y) break;
			swap(m[a],m[b]);
		}
		else{ // query
			int x;
			scanf("%d", &x);
			int a = 1;
			for(; a <= n; a++) if(m[a] == x) break;
			if(g[a].size()==0) printf("*\n");
			else{
				memset(seen, 0, sizeof(seen));
				int r = INF;
				for(int v : g[a]){
					r = min(r, dfs(v));
				}
				printf("%d\n", r);
			}
		}
	}

    return 0;

}