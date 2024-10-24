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
	ll n, x;
	cin >> n >> x;

	ll ans = 0;
	ll acc = 0;
	map<ll,ll> m;
	vector<int> a(n);

	m[0]++;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		acc += a[i];
		// a[i] - l == x
		ans += (m[acc-x]);
		m[acc]++;
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