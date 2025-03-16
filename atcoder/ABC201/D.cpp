#include <bits/stdc++.h>

#define N 2000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

using namespace std;

int a[N+1][N+1];
int n, m;
int dp[N+1][N+1];
bool seen[N+1][N+1];

bool inside(int i, int j){
	return (i <= n) and (j <= m) and (i > 0) and (j > 0);
}

int solve(int i, int j){
	if(i == n and j == m){
		return 0;
	}

	if(seen[i][j]) return dp[i][j];

	int ans = 0;

	if(inside(i+1, j) and inside(i, j+1)){
		if((i+j)%2 == 0){
			ans = max(solve(i+1, j) + a[i+1][j], solve(i, j+1) + a[i][j+1]);
		}
		else{
			ans = min(solve(i+1, j) - a[i+1][j], solve(i, j+1) - a[i][j+1]);
		}
	}
	else if(inside(i+1, j)){
		if((i+j)%2 == 0){
			ans = solve(i+1, j) + a[i+1][j];
		}
		else{
			ans = solve(i+1, j) - a[i+1][j];
		}
	}
	else if(inside(i, j+1)){
		if((i+j)%2 == 0){
			ans = solve(i, j+1) + a[i][j+1];
		}
		else{
			ans = solve(i, j+1) - a[i][j+1];
		}
	}
	seen[i][j] = true;
	return dp[i][j] = ans;
}

int main(){
	
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c;
			scanf(" %c", &c);
			if(c == '+') a[i][j] = 1;
			else a[i][j] = -1;
		}
	}

	if(solve(1,1) > 0){
		printf("Takahashi\n");
	}
	else if(solve(1,1) < 0){
		printf("Aoki\n");
	}
	else{
		printf("Draw\n");
	}

    return 0;

}