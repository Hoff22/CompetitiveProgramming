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

// 2  3  10  11
// 1  2  7
// 

// 15 1/1 + ceil(15/3)

// 15 16
//int dp[N];
long long a[N+1];
long long b[N+1];

void solve(){

	int n, c;
	scanf("%d %d", &n, &c);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 0; i < n-1; i++){
		scanf("%lld", &b[i]);
	}

	long long k = 0;
	long long ans = INF;
	long long d = 0;
	for(int i = 0; i < n; i++){
		
		ans = min(ans, k + (long long)ceil(1.0*(c-d)*(d<c) / a[i]));

		if(d >= b[i]){
			d -= b[i];
			k += 1;
			continue;
		}

		b[i] -= d;
		k += 1 + (long long)ceil(1.0*b[i] / a[i]);
		d = ((long long)ceil(1.0*b[i] / a[i]) * a[i]) - b[i];

		//printf("%d %d %d %d\n", ans, a[i], b[i], d);
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