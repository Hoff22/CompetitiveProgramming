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

long long dp[10][N+1];

long long size(long long n, long long m){
	long long r = 1;

	if(m == 0) return r;

	if(dp[n][m] != -1) return dp[n][m];

	for(int i = 1; i <= m; i++){
		if(n == 9){		
			r = (r + size(1, m-i))%MOD;
		}
		n = (n+1) % 10;
	}
	return dp[n][m] = r%MOD;
}



void solve(){
	long long n, m;
	scanf("%lld %lld", &n, &m);

	memset(dp, -1, sizeof(dp));

	long long ans = 0;
	while(n){
		int x = n % 10;

		ans = (ans + size(x, m))%MOD;

		n /= 10;
	}

	printf("%lld\n", ans);
}

int main(){
	
	// p10[0] = 1;
	// for(int i = 1; i <= 18; i++){
	// 	p10[i] = p10[i-1]*10;
	// }

	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}