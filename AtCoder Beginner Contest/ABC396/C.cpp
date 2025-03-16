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
	int n, m;
	cin >> n >> m;
	vector<ll> a, b, neg;

	for(int i = 0; i < n; i++){
		ll x; cin >> x;
		a.push_back(x);
	}

	for(int i = 0; i < m; i++){
		ll x; cin >> x;
		if(x < 0) continue;
		b.push_back(x);
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	
	ll ans = 0;

	while(a.size() < b.size()) b.pop_back();

	while(a.size() > b.size() and a.back() < 0) a.pop_back();

	while(a.size() and b.size() and (a.back() + b.back() < 0)) a.pop_back(), b.pop_back();

	// for(ll i : a){
	// 	cout << i << " ";
	// }
	// cout << endl;
	// for(ll i : b){
	// 	cout << i << " ";
	// }
	// cout << endl;

	for(ll i : a) ans += i;
	for(ll i : b) ans += i;

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