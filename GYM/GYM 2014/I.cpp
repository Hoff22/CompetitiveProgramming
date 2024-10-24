#include <bits/stdc++.h>

#define N 200000
#define MAX 100000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int dp[N+1];
vector<int> v;
int n,c,a,b;

int solve(int i){
	if(i == n) return 0;

	if(dp[i] != -1) return dp[i];

	int na = upper_bound(v.begin(), v.end(), v[i]+a) - v.begin();
	int nb = upper_bound(v.begin(), v.end(), v[i]+b) - v.begin();

	return dp[i] = min(a+solve(na), b+solve(nb));
}

int main(){
	
	scanf("%d%d%d%d", &n, &c, &a, &b);

	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; i++){
		int f;
		scanf("%d", &f);
		v.push_back(f);
	}

	printf("%d\n", solve(0));
	
    return 0;

}