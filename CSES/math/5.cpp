#include <bits/stdc++.h>

#define fi first
#define se second
#define MOD 1000000007
#define N 1000000

using namespace std;

typedef long long ll;

// int mp[N + 1]; // mp[i] stores the minimum prime number which divides i. i is prime if it's not 0 and mp[i] == i.

// /* O(N). */
// vector<int> linear_sieve(int n) {
//     vector<int> p; // Stores prime numbers.

//     for (ll i = 2; i <= n; i++) {
//         if (!mp[i]) { // i is prime if we haven't found any smaller factors of it.
//             mp[i] = i;
//             p.push_back(i);
//         }

//         // Since every number x can be written as x = i * mp[x] we can iterate over every prime mp[x] (prime[j]).
//         for (ll j = 0; j < p.size() and p[j] <= mp[i] and i * p[j] <= n; j++) {
//             mp[i * p[j]] = p[j];
//         }
//     }

//     return p;
// }

// /* O(Log(N)). */
// vector<pair<int, int>> factor(int n) {
//     vector<pair<int, int>> f; // Sorted vector of pairs (prime, exponent).

//     // Asserting that linear_sieve was executed before factorizing.
//     assert(mp[2] == 2);

//     // While there are still prime factors.
//     while (n > 1) {
//         if (!f.empty() and mp[n] == f.back().first) {
//             f.back().second++;
//         } else {
//             f.push_back({mp[n], 1});
//         }

//         // Dividing n by its smallest prime factor.
//         n /= mp[n];
//     }

//     return f;
// }

// /* O(d(N) * Log(d(N))) such that d(N) is the number of divisors of N. */
// vector<int> divisors(int n) {
//     vector<pair<int, int>> f = factor(n);
//     vector<int> d = {1};

//     // Building the divisors from the prime factors of n.
//     for (int i = 0; i < f.size(); i++) {          // For every prime factor p.
//         for (int j = d.size() - 1; j >= 0; j--) { // For every already existing divisor d.
//             int cur = d[j];

//             for (int k = 1; k <= f[i].second; k++) { // Appending d * p^k.
//                 cur *= f[i].first;
//                 d.push_back(cur);
//             }
//         }
//     }

//     sort(d.begin(), d.end());

//     return d;
// }

void solve(){
	int n;
	cin >> n;

	int ans = 1;
	vector<int> cnt(1000000,0);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		stack<int> st;
		for(int d = 1; d * d <= x; d++){
			if(x%d == 0){
				if(d != x/d) st.push(d);
				if(cnt[x/d]){
					ans = max(ans, x/d);
					break;
				}
				cnt[x/d]++;
			}
		}

		while(st.size()){
			if(cnt[st.top()]){
				ans = max(ans, st.top());
				break;
			}
			cnt[st.top()]++;
			st.pop();
		}

	}


	cout << ans << endl;
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
