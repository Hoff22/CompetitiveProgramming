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

typedef long long ll;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<ll> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	sort(a.begin()+1, a.end());
	
	vector<ll> acc(n+1, 0);
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		acc[i] = acc[i-1] + a[i];
		sum += a[i];
	}

	// for(int i : a) cout << i <<" ";
	// cout << endl;

	ll ans = 0;
	// cout << "sum: " << sum << endl;
	for(int i = 0; i <= k; i++){
		// cout << acc[i*2] << " " << (acc[n] - acc[n-(k-i)]) << " " << sum - (acc[i*2] + (acc[n] - acc[n-(k-i)])) << endl;
		ans = max(ans, sum - (acc[i*2] + (acc[n] - acc[n-(k-i)])));
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}