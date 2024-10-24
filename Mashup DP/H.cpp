#include <bits/stdc++.h>

#define N 3000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int s[N+1];
int c[N+1];
int dp[N+1][N+1][4];

int n;

int solve(int it, int last, int x){
	if(x >= 3) return c[last];
	if(it > n) return INF;

	if(dp[it][last][x] != -1) return dp[it][last][x];

	if(s[last] < s[it]){
		return dp[it][last][x] = min(c[last]+solve(it+1, it, x+1), solve(it+1, last, x));
	}

	return dp[it][last][x] = solve(it+1, last, x);
}

void run(){
	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));

	for(int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}

	int ans = INF;
	for(int i = 1; i <= n; i++){
		ans = min(ans, solve(i, 0, 0));
	}

	if(ans == INF) ans = -1;
	printf("%d\n", ans);
}

int main(){
	
	run();
    
    return 0;
}