#include <bits/stdc++.h>

#define N 500000
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

int main(){
	
	int n;
	scanf("%d", &n);
	
	long long cur = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);

		cur = a[i] - cur;
	}

	int q;
	scanf("%d", &q);

	for(int i = 0; i < q; i++){
		long long l, r, v;
		scanf("%lld %lld %lld", &l, &r ,&v);
// 3 3 = 1 != 0
		if((r-l+1) % 2 == 1){
			if((n-l)%2 == 1){
				cur += -v;
			}
			else{
				cur += v;
			}
		}
		printf("%lld\n", cur);
	}

    return 0;

}