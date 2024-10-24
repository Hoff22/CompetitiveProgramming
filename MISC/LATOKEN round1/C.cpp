#include <bits/stdc++.h>

#define N 400000
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

int a[N+1];
int b[N+1];
int g[N+1];
int seen[N+1];

void dfs(int u){
	seen[u] = 1;
	//printf("%d ", u);
	if(!seen[g[u]])	dfs(g[u]);
}

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) seen[i] = 0;

	for(int i = 0; i < n; i++){
		scanf("%d", a+i);
	} 
	for(int i = 0; i < n; i++){
		scanf("%d", b+i);
	}
	for(int i = 0; i < n; i++){
		g[a[i]] = b[i];
	}

	long long ans = 1;
	for(int i = 0; i < n; i++){
		if(!seen[a[i]]){
			dfs(a[i]);
			ans *= 2;
			ans %= MOD;
		}
	}

	printf("%lld\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}