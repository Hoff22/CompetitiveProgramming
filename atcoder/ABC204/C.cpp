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
bool seen[N+1];
int path[N+1];
set<pair<int,int>> s;

long long solve(int u, int x){

	if(seen[u]){
		return (x - path[u])*(x - path[u]-1)/2;
	}

	seen[u] = true;
	path[u] = x;

	long long r = x;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];

		if(!s.count({u,v})){
			s.insert({u,v});
			r += solve(v, x+1);
		}
	}

	return r;
}

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= m; i++){
		int u, v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
	}

	long long ans = n;
	for(int i = 1; i <= n; i++){
		memset(seen, 0, sizeof(seen));
		ans += solve(i, 0);
	}

	// for(auto a: s){
	// 	printf("%d %d\n", a.first, a.second);
	// }

	printf("%lld\n", ans);

    return 0;

}