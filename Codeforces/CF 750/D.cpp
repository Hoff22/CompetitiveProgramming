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

long long v[N+1];

long long lcm(long long a, long long b){
	return (a / __gcd(a, b)) * b;
}

long long mmc[N+1];

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
	}

	for(int i = 0; i < n-3; i+=2){
		mmc[i] = mmc[i+1] = lcm(v[i], v[i+1]);
	}

	if(n%2){
		mmc[n-3] = mmc[n-2] = mmc[n-1] = lcm(lcm(v[n-1], v[n-2]), v[n-3]);
		mmc[n-2] *= 2;
	}
	else{
		mmc[n-2] = mmc[n-1] = lcm(v[n-1], v[n-2]);
	}

	//mmc *= 2;

	int s = 1;
	for(int i = 0; i < n; i++){
		long long x = abs(mmc[i] / v[i]);

		if(s == -1){
			if(v[i] > 0) x *= -1;
		}
		else{
			if(v[i] < 0) x *= -1;
		}

		assert((v[i] * x < 0) == (s < 0));

		printf("%lld ", x);
		s *= -1;
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