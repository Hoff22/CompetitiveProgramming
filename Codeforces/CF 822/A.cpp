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
	int n;
	scanf("%d", &n);

	vector<long long> v(n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
	}

	sort(v.begin(), v.end());

	long long ans = 0x3f3f3f3f3f3f3f3fll;
	for(int i = 0; i <= n-3; i++){
		ans = min(ans, abs(v[i] - v[i+1]) + abs(v[i] - v[i+2]));
		ans = min(ans, abs(v[i+1] - v[i]) + abs(v[i+1] - v[i+2]));
		ans = min(ans, abs(v[i+2] - v[i]) + abs(v[i+2] - v[i+1]));
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