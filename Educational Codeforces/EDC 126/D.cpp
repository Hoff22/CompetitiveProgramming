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

int main(){
	
	long long n, k;
	scanf("%lld %lld", &n, &k);

	vector<long long> v(n);
	vector<long long> algos(n);
	for(int i = 0; i < n; i++) scanf("%lld", &v[i]);
	for(int i = 0; i < n; i++) algos[i] = 0;

	long long ans = 0;
	long long off = 0;
	long long algo = 0;
	for(long long i = n-1; i > k-1; i--){
		v[i] -= off;
		if(v[i] > 0){
			long long g = (long long)ceil(1.0*v[i] / k);

			ans += g;
			off += k * g;
			algo += g;
			algos[i - k + 1] = g;
			// printf("g: %d: ", g);
		}

		off -= algo;
		algo -= algos[i];
		// for(int j = 0; j < n ; j++){
		// 	printf("%d ", v[j]);
		// }
		// printf("\n");
	}

	// printf("ans: %d\n", ans);

	long long mx = 0;
	for(long long i = k-1; i >= 0; i--){
		v[i] -= off;
		mx = max(mx, (long long)ceil(1.0*v[i] / (i+1)));
		off -= algo;
		algo -= algos[i];
	}

	printf("%lld\n", ans+mx);

    return 0;

}