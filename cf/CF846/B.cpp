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
	int n;
	scanf("%d", &n);

	vector<long long> a(n+1);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}

	long long v = 0;
	for(int i = 1; i <= n; i++){
		v += a[i];
		//printf("%d %lld, ", i, sum);
	}

	long long ans = 1;
	long long k = 0;
	for(int i = 1; i < n; i++){
		k += a[i];
		ans = max(ans, gcd(k, v));
	}

	printf("%lld\n", ans);

}
/*
x*a + x*b + x*c = sum

x(a + b + c) = sum



1 1 1 1 10

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