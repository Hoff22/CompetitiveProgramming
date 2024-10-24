#include <bits/stdc++.h>

#define N 200
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

void solve(){
	int n, m;
	scanf("%d %d", &n, &m);

	int a[N+1][N+1];
	long long sum1[N+2][N+2];
	long long sum2[N+2][N+2];
	long long tru[N+2][N+2];
	long long tru2[N+2][N+2];

	memset(sum1, 0, sizeof(sum1));
	memset(sum2, 0, sizeof(sum2));
	memset(tru, 0, sizeof(tru));
	memset(tru2, 0, sizeof(tru2));

	for(int i = 1 ; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			tru[i][j] = a[i][j] + tru[i-1][j-1];
			tru2[i][j] = a[i][j] + tru2[i-1][j+1];
		}
	}
	
	for(int i = n ; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			sum1[i][j] = a[i][j] + sum1[i+1][j+1];
			sum2[i][j] = a[i][j] + sum2[i+1][j-1];
			//ans = max(ans, sum1[i][j] + sum2[i][j] - a[i][j]);
		}
	}

	long long ans = 0;	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			long long val1 = tru[i][j] + sum1[i][j] - a[i][j];
			long long val2 = tru2[i][j] + sum2[i][j] - a[i][j];
			ans = max(ans, val1 + val2 - a[i][j]);
		}
	}


	printf("%lld\n", ans);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}