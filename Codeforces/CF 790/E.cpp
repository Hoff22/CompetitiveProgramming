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
	int n, q;
	scanf("%d %d", &n, &q);

	vector<int> a(n);

	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	vector<int> sum(n);
	sum[0] = a[0];
	for(int i = 1; i < n; i++){
		sum[i] = a[i] + sum[i-1];
	}
	for(int i = 0; i < q; i++){
		int x;
		scanf("%d", &x);
		int ans = (lower_bound(sum.begin(), sum.end(), x) - sum.begin());
		if(ans == n) printf("-1\n");
		else printf("%d\n", ans+1);
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