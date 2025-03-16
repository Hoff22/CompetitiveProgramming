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
int n, m;

int dp[N+1];

int main(){
	
	scanf("%d %d", &n, &m);

	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i-1; j++){
			dp[i] = (dp[i] + dp[i-j]) % m;
			if(j>1) dp[i] = (dp[i] + dp[i/j]) % m;
		}
		dp[i] = (dp[i] + dp[1]) % m;
	}

	printf("%d\n", dp[n]);
    return 0;

}