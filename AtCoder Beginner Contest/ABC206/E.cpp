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

bool radical[N+1];
long long pf[N+1];

int main(){
	
	int l, r;
	scanf("%d %d", &l, &r);

	memset(radical, true, sizeof(radical));

	long long ans = 0;

	for(long long p = 2; p <= r; p++){

		if(pf[p] == 0){
			for(long long i = p; i <= r; i += p) pf[i]++;
			for(long long i = p*p; i <= r; i += p*p) radical[i] = false; 
		}

		long long cur = (r/p) - ((l-1)/p);

		if(radical[p]){
			if(pf[p]%2) ans += cur * (cur - 1);
			else ans -= cur * (cur - 1);
		}
	}

	for(int i = max(l, 2); i <= r; i++){
		ans -= (r-i) / i * 2;
	}

	printf("%lld\n", ans);

    return 0;

}