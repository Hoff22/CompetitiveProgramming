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

	vector<long long> h(n+2, 0);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &h[i]);
	}

	vector<int> lastDiff(1000000, 0);
	vector<long long> r(n+2, 0);
	vector<long long> l(n+1, 0);
	for(long long i = 2; i <= n; i++){

		long long dif = max(0ll, h[i-1] - (h[i]-1));

		int j = lastDiff[dif];

		l[i] = l[i-1] + dif * min(i-j+1, h[i]);

		if(dif == 0 and h[i] - h[i-1] > 1){
			lastDiff[h[i] - h[i-1]] = i;
		}
	}
	lastDiff.assign(1000000, n+1);
	for(long long i = n-1; i >= 1; i--){
		long long dif = max(0ll, h[i+1] - (h[i]-1));

		int j = lastDiff[dif];

		r[i] = r[i+1] + dif * min(j-i+1, h[i]);
		
		lastDiff[dif] = i;
	}

	for(int i = 1; i <= n; i++){
		printf("%lld ", l[i]);
	}
	printf("\n");
	for(int i = 1; i <= n; i++){
		printf("%lld ", r[i]);
	}
	printf("\n");

	long long ans = 0x3f3f3f3f3f3f3f3f;

	for(int i = 1; i <= n; i++){

		ans = min(ans, l[i] + r[i] + h[i]);

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