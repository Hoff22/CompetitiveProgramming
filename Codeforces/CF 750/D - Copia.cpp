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

int v[N+1];

long long lcm(long long a, long long b){
	return (a / __gcd(a, b)) * b;
}

void solve(){
	int n;
	scanf("%d", &n);

	long long mmc = 1;


	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);

		mmc = lcm(mmc, v[i]);
	}

	//mmc *= 2;

	long long sum = 0;
	int s = 1;
	for(int i = 0; i < n; i++){

		long long value  = mmc/v[i] * s;
		if((i == 0 or i == 2) and n%2){
			value /= 2;
		}
		printf("%lld ", value);
		s *= -1;

		sum += value * v[i];
	}
	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}