#include <bits/stdc++.h>

#define N 70
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int a[N][N];
int dp[N][N][N][N];
int n, m, k;

int solve(int i, int j, int r, int cnt){
	if(i == n){
		if(r==0) return 0;
		return -INF;
	}

	if(j == m){
		return solve(i+1, 0, r, 0);
	}

	if(dp[i][j][r][cnt] != -1) return dp[i][j][r][cnt];


	if(cnt < m/2){
		return dp[i][j][r][cnt] = max(a[i][j] + solve(i,j+1, (a[i][j]+r)%k, cnt+1), solve(i, j+1, r, cnt));
	}

	return dp[i][j][r][cnt] = solve(i, j+1, r, cnt);
}


int main(){
	

	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0,0,0,0));

   return 0;

}