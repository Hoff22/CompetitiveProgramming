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

long long x, y, a, b;

bool check(long long n){
	
	long long r = floorl(1.0l * (x - b*n) / (a-b));
	long long l = ceill(1.0l * (a*n - y) / (a-b));

	return (min(n, r) >= max(0ll, l));
}


void solve(){
	scanf("%lld%lld%lld%lld", &x, &y, &a, &b);

	if(a < b){
		swap(a, b);
	}

	if(a == b){
		printf("%lld\n", min(x,y)/a);
		return;
	}

	long long l = 0;
	long long r = MAX;
	while(r-l > 1){
		long long m = l + (r - l) / 2;

		if(check(m)){
			l = m;
		}
		else{
			r = m;
		}
	}

	printf("%lld\n", l);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}