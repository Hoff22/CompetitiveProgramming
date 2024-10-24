#include <bits/stdc++.h>

#define N 200000
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

/* O(sqrt(N)). */
vector<pair<long long, long long>> factor(long long n) {
    vector<pair<long long, long long>> f; // Sorted vector of pairs (prime, exponent).

    // For every prime p up to sqrt(n).
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            f.push_back({0ll, p});

            // While p divides n, keep dividing n by p and increasing the number of p factors.
            while (n % p == 0) {
                n /= p;
                f.back().first++;
            }
        }
    }

    // If n is not 1 by now, then it is a prime factor.
    if (n > 1) {
        f.push_back({1ll, n});
    }

    return f;
}

void solve(){
	long long n;
	scanf("%lld", &n);

	vector<pair<long long, long long>> factors = factor(n);

	long long ans = 0;

	sort(factors.begin(), factors.end());

	
	vector<long long> m(factors.size()+1);

	m[factors.size()] = 1;	
	for(int i = factors.size()-1; i >= 0; i--){
		m[i] = factors[i].se * m[i+1];
	}

	long long cur = 0;
	for(int i = 0; i < factors.size(); i++){
		if(cur != factors[i].fi){
			ans += m[i] * (factors[i].fi - cur);
			cur = factors[i].fi;
		}
	}

	printf("%lld\n", ans);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}