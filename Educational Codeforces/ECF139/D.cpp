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

constexpr int N = 10000000;

int mp[N + 1]; // mp[i] stores the minimum prime number which divides i. i is prime if it's not 0 and mp[i] == i.

/* O(N). */
vector<int> linear_sieve(int n) {
    vector<int> p; // Stores prime numbers.

    for (int i = 2; i <= n; i++) {
        if (!mp[i]) { // i is prime if we haven't found any smaller factors of it.
            mp[i] = i;
            p.push_back(i);
        }

        // Since every number x can be written as x = i * mp[x] we can iterate over every prime mp[x] (prime[j]).
        for (int j = 0; j < p.size() and p[j] <= mp[i] and i * p[j] <= n; j++) {
            mp[i * p[j]] = p[j];
        }
    }

    return p;
}

/* O(Log(N)). */
vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> f; // Sorted vector of pairs (prime, exponent).

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
vector<int> divisors(int n) {
    vector<pair<int, int>> f = factor(n);
    vector<int> d = {1};

    // Building the divisors from the prime factors of n.
    for (int i = 0; i < f.size(); i++) {          // For every prime factor p.
        for (int j = d.size() - 1; j >= 0; j--) { // For every already existing divisor d.
            int cur = d[j];

            for (int k = 1; k <= f[i].second; k++) { // Appending d * p^k.
                cur *= f[i].first;
                d.push_back(cur);
            }
        }
    }

    sort(d.begin(), d.end());

    return d;
}

/*
(smallest prime factor of (b - a) ) - ((b|a) % (b - a));

 == 18

b < y*x

1 4
2 5
3 6


*/

void solve(){
	int a, b;
	scanf("%d %d", &a, &b);
	
	if(b - a == 1){
		printf("-1\n");
		return;
	}
	if(gcd(a, b) != 1){
		printf("0\n");
		return;
	}

	int d = (b-a);

	// if(pr[d] == false){
	// 	printf("%d\n", (b/d+1)*d - b);
	// 	return;
	// }

	vector<pair<int,int>> f = factor(d);

	long long y = INF;

	for(auto i : f){
		y = min(y, 1ll*(b/i.fi+1) * i.fi);
	}

	printf("%lld\n", y-b);

	//printf("%lld\n", x);
	//3163

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   	linear_sieve(10000000);

	int t;
	scanf("%d", &t);

	
	while(t--){
		solve();
	}
    return 0;

}