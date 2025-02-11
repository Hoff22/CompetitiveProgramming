#include <bits/stdc++.h>

#define N 500
#define MAX 1000000000
#define E 0.00000001
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

long long a[N+1];
long long dp[N+1][N+1];
int n;
// 500000 * 500
long long solve(int i, int d, int x){

	if(i > x and d <= 0) return 0;
	if(i > n) return 1/* * a[x]*/;

	if(dp[i][d] != -1) return dp[i][d];

	if(i == x) return dp[i][d] = solve(i+1, d+1, x) % MOD;
	if(a[i] == -1) return dp[i][d] = (solve(i+1, max(0, d-1), x) + solve(i+1, d, x)) % MOD;
	if(a[i] < a[x]) return dp[i][d] = (solve(i+1, d+1, x) + solve(i+1, d, x)) % MOD;
	if(a[i] == a[x] and i < x) return dp[i][d] = (solve(i+1, d+1, x) + solve(i+1, d, x)) % MOD;
	return dp[i][d] = (solve(i+1, d, x) + solve(i+1, d, x)) % MOD;
}

int main(){
	
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		char f;
		scanf(" %c%*c", &f);
		if(f == '+') scanf("%lld", &a[i]);
		else a[i] = -1;
	}

	//printf("%lld\n", solve(1, 0, 6));

	long long ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > 0){
			memset(dp, -1, sizeof(dp));
			ans = (ans + (solve(1, 0, i) * a[i]) % MOD) % MOD;
			//printf("%lld: %lld\n",a[i], solve(1, 0, i));
		}
	}

	printf("%lld\n", ans);

    return 0;
}