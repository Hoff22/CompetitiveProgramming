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
	vector<ll> t(33);
	for(int i = 0; i <= 32; i++){
		cin >> t[i];
	}

	map<pair<ll,ll>, ll> cnt;

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		ll a,b,c,d;
		char ign;
		cin >> a >> ign >> b >> ign >> c >> ign >> d;
		ll x = (a<<24) + (b<<16) + (c<<8) + d;

		ll good = 1;
		for(ll k = 0; k <= 32; k++){
			if(cnt[{k,(x>>(32-k))}] == t[k]){
				good = 0;
				// cout << k << " " << (x>>k) << endl;
			}
		}
		if(good){
			for(ll k = 0; k <= 32; k++){
				cnt[{k,(x>>(32-k))}]++;
			}
			cout << "a" << endl;
		}
		else cout << "b" << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
    return 0;
}