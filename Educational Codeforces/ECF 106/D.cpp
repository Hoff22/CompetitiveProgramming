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


// c * a * b - d <= x
// cab <= x + d
// a <= (x+d)/c
// b while(a*b <= (x + d)/c)

// c * a - d * a > 0
// a > 0 + (d * a) / c

// c * 

void solve(){
	int c, d, x;
	scanf("%d%d%d", &c, &d, &x);

	long long ans = 0;

	for(int a = 1; c - d*a <= x; a++){
		int b = 1;
		while(c*b - d*b <= x){
			printf("%d %d\n", a, b);
			long long gcd = __gcd(a,b);
			long long lcm = (a*b) / gcd;

			if(c * lcm - d * gcd == x) ans++;

			b++;
		}
	}

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