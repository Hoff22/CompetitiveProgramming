#include <bits/stdc++.h>

#define N 5000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int dp[N+1][N+1];

int n;

// int solve(int x, int cur){
// 	if(cur > x/2) return cur;

// 	if(dp[x][cur] != -1) return dp[x][cur];

// 	return 1+min(solve(x, cur+1),solve(x, cur+2))

// 	return r;
// }

void go(){
	scanf("%d", &n);

	int ans = INF;
	for(int x = 2; x <= n; x++){
		int cur = 1;
		int last = 1;
		int y = 1;
		while(cur < x){
			last+=2;
			cur+=last;
			y++;
		}
		if(cur == x) ans = min(ans, y+(n/x)); 		
	}

	printf("%d\n", ans);

}

int main(){
	
	int t;
	scanf("%d", &t);
	
	memset(dp, -1, sizeof(dp));

	while(t--){
		go();
	}
    return 0;

}