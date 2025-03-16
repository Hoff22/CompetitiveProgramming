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

	vector<int> a(n+1);
	vector<long long> h(n+1);
	vector<int> v(n+1);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	h[0] = 0;
	for(int i = 1; i <= n; i++){
		h[i] = h[i-1] + a[i];
		v[i] = max(v[i-1], a[i]);
	}

	for(int i = 0; i < q; i++){

		int k;
		scanf("%d", &k);

		int j = (int)(upper_bound(v.begin(), v.end(), k) - v.begin());
		j = max(0, j-1);

		printf("%lld ", h[j]);

	}

	printf("\n");
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