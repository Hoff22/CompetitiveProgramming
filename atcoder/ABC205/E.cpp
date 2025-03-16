#include <bits/stdc++.h>

#define N 1000000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

long long sum[N+2];

int main(){
	
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for(int i = n; i >= 0; i--){
		sum[i] = i + sum[i+1] - k;
	}

	// for(int i = 0; i <= n; i++){
	// 	printf("%d ", sum[i]);
	// }

	long long ans = 1;
	for(int i = n; i >= 1; i--){
		ans *= m - sum[i] + 1;
		ans %= MOD;
	}

	printf("%lld\n", ans);

    return 0;

}