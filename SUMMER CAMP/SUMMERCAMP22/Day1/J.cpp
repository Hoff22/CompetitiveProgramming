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

int c[N+1];
int g[N+1];

int clrs[N+1];
bool seen[N+1];

int smallInCycle(int u){
	if(seen[u]){
		return c[u];
	}

	seen[u] = true;

	return min(smallInCycle(g[u]), c[u]);
}

int findSmall(int u, int color, int mn){
	mn = min(c[u], mn);

	if(clrs[u] != 0){
		if(clrs[u] == color){
			return smallInCycle(u);
		}
		else{
			return 0;
		}
	}
	clrs[u] = color;

	return findSmall(g[u], color, mn);
}

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", (c+i));
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", (g+i));
	}

	int ans = 0;

	int cur = 1;
	for(int i = 1; i <= n; i++){
		if(clrs[i]) continue;
		int v = findSmall(i, cur, INF);
		ans += v;

		cur++;
	}

	printf("%d\n", ans);

    return 0;

}