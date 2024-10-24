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

long long dp[N+1][10];

void solve(){
	long long n, m;
	scanf("%lld %lld", &n, &m);

	long long ans = 0;
	while(n){
		int x = n % 10;

		ans = (ans + dp[m][x]) % MOD; 

		n /= 10;
	}

	printf("%lld\n", ans);
}

int main(){
	
	for(int i = 0; i <= N; i++){
		for(int d = 0; d < 10; d++){
			if(i == 0) dp[i][d] = 1;	
			else if(d < 9) dp[i][d] = dp[i-1][d+1];
			else{
				dp[i][d] = (dp[i-1][0] + dp[i-1][1])%MOD;
			}
		}
	}

	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}