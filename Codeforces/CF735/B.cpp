#include <bits/stdc++.h>

#define N 200000
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

long long a[N+1];

long long dp[N+1];

void solve(){
	int n, k;
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}	

	long long ans = -INF;
	for(long long j = 2; j <= n; j++){
		for(int i = 1; i <= k; i++){
			if(j-i <= 0) break;
			ans = max(ans, (j-i) * j - k * (a[(j-i)] | a[j]));
		}
	}

	printf("%lld\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}