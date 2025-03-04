#include <bits/stdc++.h>

#define N 300000
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

long long a[N+1];
long long b[N+1];
long long s[N+1];

void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%lld %lld", a + i, b + i);
	for(int i = 0; i < n; i++) s[i] = 0;

	long long ans = 0;
	for(int i = 0; i < n; i++){
		int prev = i - 1;
		if(i == 0) prev = n - 1;

		if(b[prev] < a[i]){
			s[i] = a[i] - b[prev];
		}

		ans += s[i];
	}

	long long mn = INFll;
	for(int i = 0; i < n; i++){
		mn = min(mn, a[i] - s[i]);
	}

	printf("%lld\n", ans + mn);
}

// 5 10  1  4  7  7
// 6  7  7 10  8  2
//    2     9  4  
int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}