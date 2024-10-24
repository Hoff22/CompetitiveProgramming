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

	vector<int> v(n+1, 0);

	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);

	sort(v.begin(), v.end());

	if(v[1] == v[n]){
		printf("%lld\n", (long long)n / 2);
		return;
	}

	long long ans = 0;
	for(int i = 1; i <= n; i++){
		if(v[i] != v[i-1]) ans = max(ans, (long long)(i-1) * (n-i+1));
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