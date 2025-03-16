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

long long gcdSum(long long n){
	long long x = n;
	long long sum = 0;
	while(x){
		sum += x%10;
		x/=10;
	}
	return __gcd(n, sum);
}

void solve(){
	long long n;
	scanf("%lld", &n);

	long long ans = 0;

	if(gcdSum(n) > 1) ans = n;
	else if(gcdSum(n+1) > 1) ans = n+1;
	else if(gcdSum(n+2) > 1) ans = n+2;

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