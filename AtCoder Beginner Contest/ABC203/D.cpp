#include <bits/stdc++.h>

#define N 800
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N+1][N+1];
long long dp[N+1][N+1];

int n, k;
bool check(int m){

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + (a[i][j] <= m);
		}
	}

	for(int i = 1; i+k-1 <= n; i++){
		for(int j = 1; j+k-1 <= n; j++){
			if(dp[i+k-1][j+k-1] - dp[i-1][j+k-1] - dp[i+k-1][j-1] + dp[i-1][j-1] >= (k*k+1)/2){
				return 1;
			}
			//if(m == 4)printf("%d %d %d\n", i, j, dp[i+k-1][j+k-1] - dp[i-1][j+k-1] - dp[i+k-1][j-1] + dp[i-1][j-1]);
		}
	}
	return 0;
}

int main(){
	
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	int l = 0;
	int r = 1000000000;
	int m;

	// O(N^2 LogN)
	while(l < r){
		m = l + (r-l) / 2;

		if(check(m)){
			r = m;
		}
		else{
			l = m+1;
		}
	}

	printf("%d\n", l);

    return 0;

}