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

// xA = y10

// 2 2   3 5

// 2 2 5 5

// 1000 = 2 2 2 5 5 5

// n * m

// 15323456457
//           ^
//			^         

void solve(){
	long long n, m;
	scanf("%lld %lld", &n, &m);

	long long x = n * m;

	for(int i = 18; i >= 0; i--){
		long long y = 1;
		for(int j = 0; j < i; j++){
			y *= 10;
		}

		long long g = y / gcd(n, y);

		if(g > m) continue;

		long long cur = m - (m%g);

		printf("%lld\n", cur * n);
		return;
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