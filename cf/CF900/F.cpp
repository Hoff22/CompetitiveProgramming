#include <bits/stdc++.h>

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

constexpr int N = 1000000;

long long mp[N + 1]; // mp[i] stores the minimum prime number which divides i. i is prime if it's not 0 and mp[i] == i.

/* O(N). */
vector<long long> linear_sieve(long long n) {
    vector<long long> p; // Stores prime numbers.

    for (long long i = 2; i <= n; i++) {
        if (!mp[i]) { // i is prime if we haven't found any smaller factors of it.
            mp[i] = i;
            p.push_back(i);
        }

        // Since every number x can be written as x = i * mp[x] we can iterate over every prime mp[x] (prime[j]).
        for (long long j = 0; j < p.size() and p[j] <= mp[i] and i * p[j] <= n; j++) {
            mp[i * p[j]] = p[j];
        }
    }

    return p;
}

/* O(Log(N)). */
vector<pair<long long, long long>> factor(long long n) {
    vector<pair<long long, long long>> f; // Sorted vector of pairs (prime, exponent).

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

void solve(){
	long long n, q;
	cin >> n >> q;

	map<long long,long long> ini;

	for(auto [p,c] : factor(n)){
		ini[p] += c;
	}

	map<long long,long long> cnt = ini;

	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			long long x;
			cin >> x;

			for(auto [p,c] : factor(x)){
				cnt[p] += c;
			}

			long long dvs = 1;
			for(auto [p,c] : cnt){
				dvs *= (c+1);
			}

			for(auto [p,c] : cnt){
				int i = 0;
				while(dvs%p == 0 and i < c){
					dvs /= p;
					i++;
				}
			}

			if(dvs != 1){
				cout << "NO" << endl;
			}
			else{
				cout << "YES" << endl;
			}
		}	
		else{
			cnt = ini;
		}
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	linear_sieve(N);

	while(t--){
		solve();
	}
    return 0;

}