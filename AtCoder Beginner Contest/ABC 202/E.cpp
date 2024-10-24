#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

#define N 200000

vector<int> g[N+1];
bool seen[N+1];

int from[N+1];
int to[N+1];

vector<int> depth[N+1];

int timer;

void build(int u, int d){

	seen[u] = true;
	from[u] = ++timer;
	depth[d].push_back(from[u]);

	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];

		if(!seen[v]){
			build(v, d+1);
		}
	}

	to[u] = timer;
}

int solve(int u, int d){
	return upper_bound(depth[d].begin(), depth[d].end(), to[u]) - lower_bound(depth[d].begin(), depth[d].end(), from[u]);
}

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 2; i <= n; i++){
		int x;
		scanf("%d", &x);
		g[x].push_back(i);
	}

	build(1, 0);

	for(int d = 0; d <= n; d++){
		sort(depth[d].begin(), depth[d].end());
	}

	int q;
	scanf("%d", &q);

	while(q--){
		int u, d;
		scanf("%d %d", &u, &d);

		printf("%d\n", solve(u, d));
	}


    return 0;

}