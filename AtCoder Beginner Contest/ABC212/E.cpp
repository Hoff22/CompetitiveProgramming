#include <bits/stdc++.h>

#define N 5000
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

vector<int> gt[N+1];
int dp[N+1][N+1];
int s[N+1];
int n, m, d;


int main(){

	scanf("%d %d %d", &n, &m, &d);

	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);

		gt[u].push_back(v);
		gt[v].push_back(u);
	}

	dp[0][1] = 1;
	s[0] = dp[0][1];
	for(int k = 1; k <= d; k++){
		for(int u = 1; u <= n; u++){
			dp[k][u] = s[k-1];
			for(int v : gt[u]){
				dp[k][u] = (dp[k][u] - dp[k-1][v]) % MOD;
			}
			dp[k][u] = (dp[k][u] - dp[k-1][u]) % MOD; 
			s[k] = (s[k] + dp[k][u]) % MOD;
			//printf("%d %d: %d\n", k, u, dp[k][u]);
		}
	}

	printf("%d\n", (dp[d][1] + MOD) % MOD);

    return 0;

}