#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

char t[4] = "abc";
char s[N+1];
long long dp[N+1][3][3];
long long p3[N+1];
int n, k;


long long solve(int i, int j, int used){
	if(j == 3) return p3[k-used];
	if(i > n) return 0;

	if(dp[i][j][used] != -1) return dp[i][j][used];

	if(s[i] == t[j] or s[i] == '?'){
		return dp[i][j][used] = (solve(i+1, j, used) + solve(i+1, j+1, used + (s[i] == '?'))) % MOD;
	}	

	return dp[i][j][used] = solve(i+1, j, used);
}

int main(){
	
	scanf("%d", &n);

	p3[0] = 1;
	for(int i = 1; i <= n; i++){
		p3[i] = (p3[i-1]*3) % MOD;
	}

	for(int i = 1; i <= n; i++){
		scanf(" %c", &s[i]);
		if(s[i] == '?') k++;
	}

	memset(dp, -1, sizeof(dp));

	printf("%lld\n", solve(1,0,0));

    return 0;

}