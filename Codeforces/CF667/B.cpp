#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

void solve(){
	int a, b, x, y, n;
	scanf("%d %d %d %d %d", &a, &b, &x, &y, &n);

	int an, bn;
	if(max(x, a-n) < max(y, b-n)){
		an = max(x, a-n);
		n -= a-an;
		bn = max(y, b-n);
	}
	else{
		bn = max(y, b-n);
		n -= b-bn;
		an = max(x, a-n);
	}

	long long ans = 1ll*an*bn;

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