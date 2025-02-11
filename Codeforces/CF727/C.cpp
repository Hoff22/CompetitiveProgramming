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

long long a[N+1];

int main(){
	
	long long n, k, x;
	scanf("%lld %lld %lld", &n, &k, &x);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	sort(a, (a+n));

	// for(int i = 0; i < n; i++){
	// 	printf("%lld ", a[i]);
	// }
	// printf("\n");

	vector<long long> cnt;
	for(int i = 0; i < n-1; i++){
		if(a[i+1] - a[i] > x) {
			long long gap = a[i+1] - a[i];
			cnt.push_back(ceil((1.0*gap) / x) - 1);
		}
	}

	// for(int i = 0; i < cnt.size(); i++){
	// 	printf("%lld ", cnt[i]);
	// }
	// printf("\n");

	sort(cnt.begin(), cnt.end());

	long long ans = cnt.size() + 1;
	for(int i = 0; i < cnt.size(); i++){
		if(cnt[i] <= k){
			k -= cnt[i];
			ans--;
		}
	}

	printf("%lld\n", ans);
    return 0;

}