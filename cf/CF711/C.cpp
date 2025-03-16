#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define L -1
#define R 1

using namespace std;
int n, k;

long long dp[N+1][2][N+1];

long long solve(int cur, int dir, int i){
	//printf("%d %d %d\n", cur, dir, i);

	if((i < 1 and dir == L) or (i > n and dir == R)){
		return 1;
	}

	int dpdir = (dir == 1);

	if(dp[cur][dpdir][i] != -1) return dp[cur][dpdir][i];

	if(cur == 1){
		return dp[cur][dpdir][i] = (solve(cur, dir, i + dir) % MOD);
	}

	return dp[cur][dpdir][i] = ((solve(cur-1, (dir*-1), i + (dir*-1)) + solve(cur, dir, i + dir)) % MOD);
}

void run(){
	scanf("%d%d", &n, &k);

	memset(dp, -1, sizeof(dp));

	printf("%lld\n", solve(k,R,1));

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		run();
	}
    return 0;

}