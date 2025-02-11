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

// O(log_2(b))
long long pow2[N+1];

long long dp[N+1][2];

int n, k;

long long go(int d, bool greater){

	if(d == 0) return 1;

	if(dp[d][greater] != -1) return dp[d][greater];

	if(greater) return dp[d][greater] = (go(d-1, 1) * pow2[n]) % MOD;

	return dp[d][greater] = (go(d-1, (n%2 == 0)) + (go(d-1, 0) * (pow2[n-1] - (n%2 == 0)))) % MOD; 

}

void solve(){
	scanf("%d %d", &n, &k);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(k, 0));
}

int main(){
		
	pow2[0] = 1;
	for(int i = 1; i <= N; i++){
		pow2[i] = (pow2[i-1] * 2) % MOD;
	}

	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}

    return 0;

}