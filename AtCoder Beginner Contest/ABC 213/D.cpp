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

void dfs(int u, int p){

	printf("%d ", u);

	sort(g[u].begin(), g[u].end());
	
	for(int v : g[u]){
		if(p == v) continue;
		dfs(v, u);
	}

	if(p) printf("%d ", p);
}

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);
	printf("\n");

    return 0;

}