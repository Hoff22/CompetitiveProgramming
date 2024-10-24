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

long long __lcm(long long x, long long y) {return x/__gcd(x,y) * y;}

void solve(){
	long long n;
	scanf("%lld", &n);

	long long ans = 2*n;
	for(long long i = 2, x = 1; ; i++){
		x = __lcm(x,i);
		if(x > n) break;
		ans += n/x;
		ans %= MOD;
	}
// 3885 sla
	printf("%lld\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
    return 0;

}