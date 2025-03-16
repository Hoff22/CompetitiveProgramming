#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& i : a) cin >> i;

	ll l = 0;
	ll r = 200000;
	ll ans = -1;
	while(l <= r){
		ll m = l + (r-l)/2;

		int good = 1;
		vector<ll> b = a;
		b.push_back(0);
		for(int i = 0 ; i < n; i++){
			if(b[i] <= m) continue;
			if(b[i] >= 2*m){
				good = 0;
				break;
			}
			ll y = b[i]-m;
			ll x = m-y;
			b[i] -= x;
			b[i+1] += b[i];
		}

		if(!good or b[n] > 0){
			l = m+1;
		}
		else{
			ans = m;
			r = m-1;
		}
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
    return 0;
}