#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF (1000000000ll * 200000ll)
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

void solve(){
	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ll l = 0;
	ll r = 1000000000 * n;
	ll ans = 0;

	while(l <= r){
		ll m = l + (r-l) / 2;

		ll cur = 0;
		int cnt = 1;
		for(int i = 0; i < n; i++){
			if(cur + a[i] > m){
				cnt++;
				cur = 0;
			}
			cur += a[i];
			if(cur > m){
				break;
			}
		}

		if(cur > m){
			l = m+1;
			continue;
		}

		if(cnt <= k){
			ans = m;
			r = m-1;
		}
		else{
			l = m+1;
		}
	}

	cout << ans << endl;
}

/*


5 12 - 7+
6 10 - -1
8 15 - -4


*/

int main(){	
	ios_base::sync_with_stdio(false);
	int t;
    cin.tie(NULL);
	t = 1;
	while(t--){
		solve();
	}
    return 0;

}