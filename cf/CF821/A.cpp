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
	int n,k;
	scanf("%d %d", &n, &k);

	vector<long long> a(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

	long long ans = 0;
	for(int i = 0; i < k; i++){
		long long mx = 0;
		for(int j = i; j < n; j+=k){
			mx = max(mx, a[j]);
		}
		ans += mx;
	}

	printf("%lld\n", ans);
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