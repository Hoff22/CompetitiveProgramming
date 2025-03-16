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
	if((n & x) != x){
		printf("-1\n");
		return;
	}

	unsigned long long p = 0;
	unsigned long long xt = x;
	unsigned long long nt = n;
	
	// debug
	// printf("n_2: ");
	// do{printf("%lld",nt&1);}while(nt/=2);
	// printf("\n");

	// printf("x_2: ");
	// do{printf("%lld",xt&1);}while(xt/=2);
	// printf("\n");
	//

	nt = n;
	xt = x;
	unsigned long long l = -1;
	unsigned long long r = 0;
	unsigned long long g = INF;
	while(xt or nt){
		if((nt%2) and !(xt%2)){
			if(l == -1) l = p;
			r = p;
		}
		if(nt%2 and xt%2 and g == INF){
			g = p;
		}
		xt /= 2;
		nt /= 2;
		p++;
	}
	// printf("\t%lld %lld\n",n, p);
	// printf("\t %lld\n", (n&p));
	// printf("\t %lld\n", (10 & 2));
	//printf("%lld\n", k);
	//printf("l: %lld \nr: %lld \ng: %lld\n", l, r, g);

	if(r+1 < g){
		unsigned long long k = (1ll<<l);

		for(int i = l+1; i <= r; i++){
			k += (1ll<<i) * !((n>>i) & 1ll);
		}

		if(nt == xt){
			printf("%lld\n", n+k);
		}
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
