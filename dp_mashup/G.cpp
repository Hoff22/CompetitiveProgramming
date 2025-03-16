#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define e 2.71828182845904523
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a, b, t, d;
int dp[10*100 + 100 + 1][101];

int solve(int cur, int i){
	if(i >= t){
		if(cur == b) return cur;
		return 0;
	}

	int r = 0;
	if(dp[cur][i] != -1){
		return dp[cur][i];
	}
	else{
		for(int j = -d; j <= d; j++){
			int next = solve(max(1,cur+j), i+1);
			if(next) r = max(r, cur + next);
		}
	}

	return dp[cur][i] = r;
}

void answer(){
	scanf("%d %d", &a, &b);
	scanf("%d %d", &t, &d);

	memset(dp, -1, sizeof(dp));

	printf("%d\n", solve(a, 1));

}

int main(){
	
	answer();

    return 0;

}