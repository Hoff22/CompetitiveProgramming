#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

vector<int> v;
int offset[N+1];
int dp[N+1][32];

int solve(int i, int t){

	if(i < 1){
		return 0;
	}

	if(dp[i][t] != -1) return dp[i][t];

	if(t){
		return dp[i][t] = min(1+solve(i-1, t), solve(offset[i], t-1));
	}

	return dp[i][t] = 1+solve(i-1, t);
}

// 27 28 55 55 56 56 60 133 137
//							

int main(){
	
	int n, k;
	scanf("%d %d", &n, &k);

	memset(dp, -1, sizeof(dp));

	v.push_back(0);
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}

	sort(v.begin()+1, v.end());

	for(int i = 1; i <= n; i++){
		offset[i] = (int)(upper_bound(v.begin(), v.end(), v[i]/2) - v.begin() - 1);
	}

	for(int t = 0; t <= 31; t++){
		if(solve(n, t) <= k){
			printf("%d %d\n", t, solve(n, t));
			break;
		}
	}

	// for(int i = 0; i <= n; i++){
	// 	printf("%d ", offset[i]);
	// }
	// printf("\n");


    return 0;

}