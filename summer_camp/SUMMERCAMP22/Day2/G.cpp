#include <bits/stdc++.h>

#define N 500
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
long long b[N+1];
long long used[N+1];
long long cost[N+1];
long long n, l;

void build(){
	for(long long i = 1; i < n; i++){
		if(used[i]) cost[i] = 0;
		else{
			long long next;
			for(next = i+1; next <= n; next++){
				if(used[next] == 0) break;
			}

			long long prev;
			for(prev = i-1; prev >= 0; prev--){
				if(used[prev] == 0) break;
			}
			cost[i] = (a[next] - a[i]) * b[i] - (a[next] - a[i]) * b[prev];
		}
	}
}

int main(){
	long long k;
	scanf("%lld %lld %lld", &n, &l, &k);

	for(long long i = 0; i < n; i++){
		long long x;
		scanf("%lld", &x);
		a[i] = x;
	}
	for(long long i = 0; i < n; i++){
		long long x;
		scanf("%lld", &x);
		b[i] = x;
	}

	a[n] = l;
	b[n] = 0;

	cost[0] = -INF;

	while(k--){
		build();

		// for(long long i = 0; i < n; i++){
		// 	prlong longf("%d ", cost[i]);
		// }
		// prlong longf("\n");

		long long best = 1;
		for(long long i = 1; i < n; i++){
			if(used[i] == 0 and cost[i] >= cost[best]){
				best = i;
			}
		}

		if(cost[best] < 0) break;

		used[best] = 1;
	}

	build();

	long long ans = 0;
	for(long long i = 0; i < n; i++){
		if(used[i]) continue;

		long long next;
		for(next = i+1; next <= n; next++){
			if(used[next] == 0) break;
		}

		ans += (a[next] - a[i]) * b[i];
	}

	printf("%lld\n", ans);

    return 0;

}