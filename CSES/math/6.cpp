#include <bits/stdc++.h>

#define fi first
#define se second
#define MOD 1000000007
#define N 1000000

using namespace std;

typedef long long ll;

ll div2(ll a, ll mod){
	return (a * ((mod-1)/2 + 1)) % mod;
}

void solve(){
	ll n;
	cin >> n;

	long long ans1 = 0;
	for(ll i = 1; i * i <= n; i++){
		ll k = (n/i)%MOD;
		ll r = div2((((k*k)%MOD)+k)%MOD, MOD);

		ans1 = (ans1 + r) % MOD;
		// cout << k << " " << r << endl;
	}

	ll sq = (ll)sqrt(n);
	// cout << "ans1: " << ans1 << " sq: " << sq << endl;

	long long ans2 = 0;
	for(ll i = 1; i * i <= n; i++){
		ll amt = ((n/i) * i - (sq*i) % MOD) % MOD;

		ans2 = (ans2 + amt) % MOD;
		// cout << i << " " << amt << endl;
	}

	cout << (ans1+ans2+MOD) % MOD << endl;
}

int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // linear_sieve(1000000);

	int t;
	t = 1;
	while(t--){
		solve();
	}
    return 0;
}
