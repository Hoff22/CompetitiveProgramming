#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

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

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> primes = linear_sieve(1000000);

	int l, r;
	cin >> l >> r;

	int a = 0, b = 0;

	vector<bool> cana(1000000, 1); 
	vector<bool> canb(1000000, 1); 

	for(int i = l; i <= r; i++){
		string s;
		cin >> s;

		if(s == "Fizz"){
			for(int d : divisors(i)){
				canb[d] = 0;
			}
		}
		else if(s == "Buzz"){
			for(int d : divisors(i)){
				cana[d] = 0;
			}
		}
		else if(s == "FizzBuzz"){
		}
		else{
			for(int d : divisors(i)){
				cana[d] = 0;
				canb[d] = 0;
			}
		}

	}

	if(a == 0){
		for(int i = 1; i <= 1000000; i++){
			if(cana[i]){
				a = i;
				break;
			}
		}
	}

	if(b == 0){
		for(int i = 1; i <= 1000000; i++){
			if(canb[i]){
				b = i;
				break;
			}
		}
	}

	cout << a << " " << b << endl;

}