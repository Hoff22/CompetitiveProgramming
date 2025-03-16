#include <bits/stdc++.h>

#define N 500
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

char a[N+1][N+1];
int dp[N+1][N+1];
int h,w;

bool valid(int i, int j){
	return (i > 0 and i <= h and j > 0 and j <= w);
}

int aroundMin(int x, int y){
	int r = INF;
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			if(i == j) continue;
			if(valid(x+i,y+j)) r = min(r, dp[x+i][y+j]);
		}
	}

	return r;
}

int aroundMin2(int x, int y){
	int r = INF;
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			if(i == 0 and j == 0) continue;
			if(valid(x+i,y+j)) r = min(r, dp[x+i][y+j] + (a[x+i][y+j] != '#'));
		}
	}

	return r;
}

int aroundMin3(int x, int y){
	int r = INF;
	for(int i = 0; i >= -1; i--){
		for(int j = 0; j >= -1; j--){
			if(i == j) continue;
			if(valid(x+i,y+j)) r = min(r, dp[x+i][y+j]);
		}
	}

	return r;
}

int aroundMin4(int x, int y){
	int r = INF;
	for(int i = 0; i >= -1; i--){
		for(int j = 0; j >= -1; j--){
			if(i == 0 and j == 0) continue;
			if(valid(x+i,y+j)) r = min(r, dp[x+i][y+j] + (a[x+i][y+j] != '#'));
		}
	}

	return r;
}

int main(){
	
	scanf("%d %d", &h, &w);

	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			scanf(" %c", &a[i][j]);
			dp[i][j] = INF;
		}
	}

	int ans1, ans2;
	ans1 = ans2 = INF;

	dp[h][w] = 0;
	for(int i = h; i > 0; i--){
		for(int j = w; j > 0; j--){

			if(i == h and j == w){
				continue;
			}

			if(a[i][j] == '.') dp[i][j] = aroundMin(i,j);
			if(a[i][j] == '#') dp[i][j] = aroundMin2(i,j);
		}
	}

	ans1 = dp[1][1];

	//memset(dp, 0x3f, sizeof(dp));

	dp[1][1] = 0;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){

			if(i == 1 and j == 1){
				continue;
			}

			if(a[i][j] == '.') dp[i][j] = aroundMin3(i,j);
			if(a[i][j] == '#') dp[i][j] = aroundMin4(i,j);
		}
	}

	ans2 = dp[h][w];

	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}


	printf("%d\n", min(ans1, ans2));

    return 0;

}