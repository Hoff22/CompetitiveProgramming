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

pair<int,int> a[N+1];
int dp[N+1][N+1][N+1];
int n, l;

int solve(int i, int last, int k){
	//printf("%d %d %d\n", a[i].fi , a[i].se, k);
	if(i == n){
		return 0;
	}


	if(dp[i][last][k] != -1) return dp[i][last][k];

	if(k and i != 0){
		return dp[i][last][k] = 
		min(
			solve(i+1, i, k) + (a[i+1].fi - a[i].fi) * a[i].se,
			solve(i+1, last, k-1) + (a[i+1].fi - a[i].fi) * a[last].se
			);
	}
	//printf("%d\n", (a[i+1].fi - a[i].fi) * a[i].se);
	return dp[i][last][k] = solve(i+1, i, k) + (a[i+1].fi - a[i].fi) * a[i].se;
}

int main(){
	int k;
	scanf("%d %d %d", &n, &l, &k);

	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a[i].fi = x;
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a[i].se = x;
	}

	a[n] = {l, 0};

	printf("%d\n", solve(0, 0, k));

    return 0;

}