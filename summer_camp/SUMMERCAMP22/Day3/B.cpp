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
int p = 1;
int dir = 0;
int dist = 0;

int dfs(int u){
	seen[u] = true;

	if(!dist){
		return u;
	}

	for(int v : g[u]){
		if(!seen[v] and v == dir){
			dist--;
			return dfs(dir);
		}
	}

	int cnt = 0;
	for(int v : g[u]){
		if(!seen[v]){
			cnt++;
		}
	}

	if(cnt == 1){
		for(int v : g[u]){
			if(!seen[v]){
				dist--;
				return dfs(v);
			}
		}
	}

	return u;
}

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int u,v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	printf("? 1 %d\n", p);
	fflush(stdout);
	scanf("%d", &dist);
	printf("? 2 %d\n", p);
	fflush(stdout);
	scanf("%d", &dir);

	while(dir and dist){
		// printf("dist:%d\n", dist);
		// printf("dir:%d\n", dir);
		// printf("p:%d\n", p);
		p = dfs(p);

		if(dist == 0) break;

		printf("? 2 %d\n", p);
		fflush(stdout);
		scanf("%d", &dir);
	}

	printf("! %d\n", p);
	fflush(stdout);

    return 0;

}