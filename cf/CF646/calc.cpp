#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int n;

long long dp[N+1][N+1];

long long solve(int i, int sum){
	if(i > n){
		return (sum == n-1);
	}

	if(dp[i][sum] != -1) return dp[i][sum];

	int r = 0;
	for(int j = 0; j <= (n-1)-sum; j++){
		r += solve(i+1, sum+j);
	}

	return dp[i][sum] = r;
}

int main(){
	
	
	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));

	printf("%lld\n", solve(1,0));

    
    return 0;
}