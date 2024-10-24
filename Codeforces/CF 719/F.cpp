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

map<pair<int,int>, int> dp;

int q(int l, int r){

	if(dp.count({l, r})){
		return dp[{l, r}];
	}

	int a;
	printf("? %d %d\n", l, r);
	fflush(stdout);
	scanf("%d", &a);
	if(a == -1){
		exit(0);
	}
	return dp[{l, r}] = ((r-l+1) - a);
}

void solve(int l, int r, int k){

	int m = (l + r) / 2;

	if(l == r){
		printf("! %d\n", l);
		fflush(stdout);
	}
	else if(q(l, m) >= k){
		solve(l, m, k);
	}
	else{
		solve(m+1, r, k - q(l, m));
	}

	dp[{l, r}] -= 1;
}

int main(){
	
	int n, t;

	scanf("%d%d", &n, &t);

	while(t--){
		int k;
		scanf("%d", &k);

		solve(1, n, k);
	}

    return 0;
}