#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int N = 1000;
constexpr int M = 1000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;

#define sum(x) (((x)*(x)+(x))/2)

typedef long long ll;

void solve(){
	ll d;
	cin >> d;

	vector<pair<ll,ll>> ans;

	for(ll k = 1; (k*k + k) / 2 < d; k++){
		if((d - (k*k + k) / 2) % k == 0){
			ll n = (d - (k*k + k) / 2) / k;
			ans.push_back({n, n+k});
		}
	}

	cout << ans.size() << endl;
	for(auto[a,b] : ans){
		cout << a << " " << b << endl;
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}