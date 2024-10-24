#include <bits/stdc++.h>

#define N 5000
#define MAX 10000000000
#define MOD (1000000000 + 7)
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int n;
int a[N+1];
int dp[N+1][N+1];

int solve(int i, int last_i){
	if(i == n+1){
		return 0;
	}

	if(dp[i][last_i] != -1) return dp[i][last_i];

	if(a[last_i] > a[i]) return dp[i][last_i] = solve(i+1, last_i);

	return dp[i][last_i] = max(solve(i+1, last_i), solve(i+1, i) + 1);
}

int main(){
	
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	memset(dp, -1, sizeof(dp));
	int longest = solve(1,0);

	printf("%d\n", n - longest);
	
	return 0;
}