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
	long long k, n, m;
	scanf("%lld %lld %lld", &n, &m, &k);

	int good = 1;
	long long r = n%k;
	if(r == 0) r = k;
	for(int i = 0; i < m; i++){
		long long x;
		scanf("%lld", &x);
		r -= (x == (long long)ceil((1.0*n)/k));
		if(r < 0 or x > (long long)ceil((1.0*n)/k)){
			good = 0;
		}
	}

	if(good) printf("YES\n");
	else printf("NO\n");

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