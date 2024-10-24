#include <bits/stdc++.h>

#define N 2000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

vector<int> g[N+1];
long long ans = 0;
bool seen[N+1];

void solve(int u){
	seen[u] = 1;
	ans++;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(!seen[v]){
			solve(v);
		}
	}
}

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
	}

	for(int i = 1; i <= n; i++){
		memset(seen, 0, sizeof(seen));
		solve(i);
	}

	// for(auto a: s){
	// 	printf("%d %d\n", a.first, a.second);
	// }

	printf("%lld\n", ans);

    return 0;

}