#include <bits/stdc++.h>

#define N 5000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

long long dp[N+1][N+1];

int main(){
	
	int n;
	scanf("%d", &n);
	vector<long long> a(n+1);
	vector<long long> b(n+1);
	vector<long long> sum(n+1);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%lld", &b[i]);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i]*b[i];
	}

	for(int d = 0; d <= n; d++){
		for(int l = 1; l+d <= n; l++){
			int r = l+d;
			if(d == 0) dp[l][r] = a[l]*b[l];
			else if(d == 1) dp[l][r] = a[l]*b[r] + a[r]*b[l];
			else{
				dp[l][r] = dp[l+1][r-1] + a[l]*b[r] + a[r]*b[l];
			}
		}
	}
	int maxL = 1;
	int maxR = 1;
	
	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++){
			//printf("%d %d %lld\n", l, r, dp[l][r]);
			if(dp[l][r] - (sum[r] - sum[l-1]) > dp[maxL][maxR] - (sum[maxR] - sum[maxL-1])){
				maxR = r;
				maxL = l;
			}
		}
	}

	reverse(a.begin()+maxL, a.begin()+maxR+1);
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		ans += a[i]*b[i];

	}

	printf("%lld\n", ans);


    return 0;

}