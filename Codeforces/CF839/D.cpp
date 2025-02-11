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

	vector<long long> a(n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	long long l = 0;
	long long r = MAX;
	for(int i = 1; i < n; i++){
		if(a[i-1] < a[i]){
			long long of = a[i] - a[i-1];
			r = min(r, a[i-1] + (of)/2);
		}
		// printf("%lld ", r);
	}
	// printf("\n");

	for(int i = 1; i < n; i++){
		if(a[i-1] > a[i]){
			long long of = a[i-1] - a[i];
			l = max(l, a[i] + (of+1)/2);
			// printf("%lld ", l);
		}
	}
	// printf("\n");
// 
	// printf("%lld %lld\n", l ,r);

	if(l <= r){
		printf("%lld\n", l);
	}
	else{
		printf("-1\n");
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