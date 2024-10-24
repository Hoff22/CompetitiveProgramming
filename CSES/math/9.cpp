#include <bits/stdc++.h>

#define fi first
#define se second
#define MOD 1000000007
#define N 1000000

using namespace std;

typedef long long ll;

ll mp[N + 1]; // mp[i] stores the minimum prime number which divides i. i is prime if it's not 0 and mp[i] == i.
vector<ll> prs;

/* O(N). */
vector<ll> linear_sieve(ll n) {
    vector<ll> p; // Stores prime numbers.

    for (ll i = 2; i <= n; i++) {
        if (!mp[i]) { // i is prime if we haven't found any smaller factors of it.
            mp[i] = i;
            p.push_back(i);
        }

        // Since every number x can be written as x = i * mp[x] we can iterate over every prime mp[x] (prime[j]).
        for (ll j = 0; j < p.size() and p[j] <= mp[i] and i * p[j] <= n; j++) {
            mp[i * p[j]] = p[j];
        }
    }

    return p;
}

/* O(Log(N)). */
vector<pair<ll, ll>> factor(ll n) {
    vector<pair<ll, ll>> f; // Sorted vector of pairs (prime, exponent).

    // Asserting that linear_sieve was executed before factorizing.
    assert(mp[2] == 2);

    // While there are still prime factors.
    while (n > 1) {
        if (!f.empty() and mp[n] == f.back().first) {
            f.back().second++;
        } else {
            f.push_back({mp[n], 1});
        }

        // Dividing n by its smallest prime factor.
        n /= mp[n];
    }

    return f;
}

/* O(d(N) * Log(d(N))) such that d(N) is the number of divisors of N. */
vector<ll> divisors(ll n) {
    vector<pair<ll, ll>> f = factor(n);
    vector<ll> d = {1};

    // Building the divisors from the prime factors of n.
    for (ll i = 0; i < f.size(); i++) {          // For every prime factor p.
        for (ll j = d.size() - 1; j >= 0; j--) { // For every already existing divisor d.
            ll cur = d[j];

            for (ll k = 1; k <= f[i].second; k++) { // Appending d * p^k.
                cur *= f[i].first;
                d.push_back(cur);
            }
        }
    }

    sort(d.begin(), d.end());

    return d;
}

void solve(){
	ll n;
	cin >> n;

	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ll ans = n*(n-1)/2;
	ll anti_ans = 0;
	vector<int> cnt(N+1,0);

	for(int i = 0; i < n; i++){
		vector<pair<ll,ll>> f = factor(a[i]);

		for(int m = 1; m < (1<<f.size()); m++){
			ll x = 1;
			for(int k = 0; k < f.size(); k++){
				if((m>>k)&1){
					if(x > a[i]/f[k].fi){
						x = a[i] + 1;
						break;
					}
					x = x * f[k].fi;
				}
			}

			if(x > a[i]) continue;

			if(__builtin_popcount(m) % 2){
				anti_ans += cnt[x];
			}
			else{
				anti_ans -= cnt[x];
			}
		}

		for(ll d : divisors(a[i])) cnt[d]++;
	}

	cout << ans-anti_ans << endl;
}

// 28 - 3 - 0 - 3 - 0

int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prs = linear_sieve(1000000);

	int t;
	t = 1;
	while(t--){
		solve();
	}
    return 0;
}
