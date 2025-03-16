#include <bits/stdc++.h>

#define N 2000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

long long n, k, p;
long long a[N+1];
long long b[N+1];
long long dp[N+1][N+1];

long long solve(int i, int j){

	if(i == n) return 0;
	if(j == k) return 0x3f3f3f3f3f3f3f3f;

	if(dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = min(solve(i,j+1), max(solve(i+1,j+1) , abs(a[i]-b[j]) + abs(b[j]-p)));

}

int main(){

	memset(dp, -1, sizeof(dp));
	scanf("%lld %lld %lld", &n,&k,&p);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 0; i < k; i++){
		scanf("%lld", &b[i]);
	}

	sort(a, a+n);
	sort(b, b+k);

	printf("%lld\n", solve(0,0));

    return 0;

}