#include <bits/stdc++.h>

#define N 100
#define MAX 1000000000
#define E 0.00000001
#define MOD 998244353
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;


int n;
long long dp[N+1][N+1][N+1];
vector<pair<int,int>> restrictions[N+1];

long long go(int i, int lz, int lo){

	if(dp[i][lz][lo] != -1) return dp[i][lz][lo];

	for(pair<int,int> r : restrictions[i]){
		if(r.se == 2){
			if(lz < r.fi or lo < r.fi) return 0;
		}
		else if(r.se == 1){
			if(lz >= r.fi and lo >= r.fi) return 0;
		}
	}

	if(i == n) {
		return 1;
	}

	return dp[i][lz][lo] = (go(i+1, i+1, lo) + go(i+1, lz, i+1)) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));

	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int x;
			scanf(" %d", &x);
			restrictions[j].push_back({i,x});
		}
	}

	printf("%lld\n", go(0,0,0));

    return 0;

}