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

vector<int> divs[N+1];
long long dp[N+1][N+1];
long long n,K;

long long solve(long long last, long long k){
	if(k == 0){
		return 1;
	}

	if(dp[last][k] != -1) return dp[last][k];

	long long r = 0;
	for(int d : divs[last]){
		r = (r + solve(d, k-1)) % MOD;
	}

	return dp[last][k] = r;
}


int main(){
	
	scanf("%lld %lld", &n, &K);
	for(int i = 1; i <= n; i++){
		for(int d = 1; d * d <= i; d++){
			if(i%d==0){
				divs[i].push_back(d);
				if(d != i/d) divs[i].push_back(i/d);
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		ans = (ans + solve(i, K-1)) % MOD;
	}
	printf("%lld\n", ans);
    
    return 0;
}