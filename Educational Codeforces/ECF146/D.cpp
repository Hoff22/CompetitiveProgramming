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
	int n, k; cin >> n >> k;
	vector<ll> a(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		ll x; cin >> x;
		a[i] *= x;
	}

	sort(a.begin(), a.end());

	for(ll i : a) cout << i << " ";
	cout << endl;

	int ans = INF;
	for(int i = 0; i < n; i++){
		ll ub = a[i] + k;
		auto p = upper_bound(a.begin(), a.end(), ub);
		if(p == a.end()){
			ans = min(ans, i);			
		}
		else{
			ans = min(ans, n - (int)(p - a.begin()) + i);
		}
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