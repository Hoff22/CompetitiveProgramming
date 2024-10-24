#include <bits/stdc++.h>

#define N 1000000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

typedef long long ll;

using namespace std;

bool prime[N + 1];
vector<ll> primes;

/* O(N * Log(Log(N))). */
vector<ll> sieve(ll n) {
    vector<ll> p;

    // Initializing.
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    // For every number i from 2 to N.
    for (ll i = 2; i <= n; i++) {
        // If current number is prime.
        if (prime[i]) {
            p.push_back(i);

            // Marking its multiples as not prime.
            for (ll j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    return p;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int q;
	cin >> q;
	
	primes = sieve(1000000);

	while(q--){
		long long a, b;
		cin >> a >> b;

		ll mx = 0;
		ll ans = 0;
		for(int p = 0; p < primes.size(); p++){
			ll cur = 0;
			ll t = max(a, p);
			while(t < b){
				cur++;
				t *= p;
			}

			if(cur < mx){
				break;
			}

			mx = cur;

			ll l = a;
			ll r = b;

			while(l < r){
				ll m = (l+r)/2;

				if()
			}
		}


	}
    return 0;

}