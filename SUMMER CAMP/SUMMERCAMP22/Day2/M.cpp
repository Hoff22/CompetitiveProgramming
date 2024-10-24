#include <bits/stdc++.h>

#define N 100
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

int a[N+1][N+1];
bool seen[N+1][N+1];
int dir[4][2] = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};
int n;

int valid(int i, int j){
	return (i >= 0 and i < n and j >= 0 and j < n);
}

void dfs(int i, int j){
	//printf("%d %d", i, j);
	seen[i][j] = 1;

	for(int d = 0; d < 4; d++){
		int ni = dir[d][0] + i;
		int nj = dir[d][1] + j;
		//printf(" \t%d %d\n", ni, nj);
		if(valid(ni, nj) and !seen[ni][nj] and a[i][j] + 1 == a[ni][nj]){
			dfs(ni, nj);
		}
	}
}

void solve(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 1){
				dfs(i,j);
				//printf("\n");
			}
		}
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		printf("%d ", seen[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!seen[i][j]){
				printf("NO\n");
				return;
			}
		}
	}

	printf("YES\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				seen[i][j] = 0;
			}
		}
		solve();
	}
    return 0;

}