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
	long long ab, a, b, none;
	scanf("%lld %lld %lld %lld", &ab, &a, &b, &none);

	if(ab == 0){
		printf("%d\n", (int)(a > 0 or b > 0 or none > 0));
		return;
	}

	long long ans = ab;

	long long x = ab;
	long long y = ab;

	long long mx = max(a,b);
	long long mn = min(a,b);

	long long rm = mn;

	x += rm;
	y -= rm;
	ans += rm;

	rm = min(x, mx);
	x -= rm;
	y += rm;
	ans += rm;

	mx -= rm;
	ans += min(x+1, mx+none);

	printf("%lld\n", ans);
}

/*

ans = ab + min(ab,x) + min(a, b) + min(a,b) + (x-ab > 0 or a!=b)

*/

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