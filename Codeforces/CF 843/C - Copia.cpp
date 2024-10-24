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

void solve(){
	unsigned long long n, x;
	scanf("%lld %lld", &n, &x);

	if(n == x){
		printf("%lld\n", n);
		return;
	}
	if(x == 0){
		unsigned long long ans = 1;
		while(n){
			n /= 2;
			ans *= 2;
		}
		printf("%lld\n", ans);
		return;
	}

	unsigned long long p = 1;
	unsigned long long xt = x;
	unsigned long long nt = n;
	while(xt or nt){
		if((nt%2) and !(xt%2)) break;
		if(xt%2) break;
		xt /= 2;
		nt /= 2;
		p *= 2;
	}
	// printf("\t%lld %lld\n",n, p);
	// printf("\t %lld\n", (n&p));
	// printf("\t %lld\n", (10 & 2));
	if((n & (n+p)) == x){
		printf("%lld\n", n+p);
	}
	else{
		printf("-1\n");
	}

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}