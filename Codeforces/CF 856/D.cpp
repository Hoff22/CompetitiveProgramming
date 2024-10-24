#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 998244353
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

constexpr int N = 1000000;

typedef long long ll;

long long f[N + 1];

/* O(Log(min(a, b))) - Extended Euclidean Algorithm.
   Returns a solution to a * x + b * y = gcd(a, b).
   Returns |x| <= |a / gcd(a, b)|, |y| <= |b / gcd(a, b)| and gcd(a, b). */
tuple<long long, long long, long long> extended_gcd(long long a, long long b) {
    long long x, y, gcd;

    if (a == 0) {
        return {b, 0, 1};
    }

    tie(gcd, x, y) = extended_gcd(b % a, a);

    return {gcd, y - (b / a) * x, x};
}

/* O(Log(M)) - Returns the modular multiplicative inverse of a mod m, if it exists.
Returns x that satisfies a * x = 1 (mod m) if a and m are coprime. Returns 0 otherwise. */
long long modular_inverse(long long a, long long m) {
    long long gcd, x, y;

    tie(gcd, x, y) = extended_gcd((a % m + m) % m, m);

    if (gcd != 1) {
        return 0;
    }

    return (x % m + m) % m;
}

/* O(Log(M)) - This only works if k! * (n - k)! is coprime with m. */
long long nck(long long n, long long k, long long m) {
    long long num, den;

    // Trivial case.
    if (k < 0 or k > n) {
        return 0;
    }

    num = f[n];
    den = (f[k] * f[n - k]) % m;

    return (num * modular_inverse(den, m)) % m;
}

/* O(N). */
void nck_init(long long m) {
    f[0] = 1;

    for (long long i = 1; i <= N; i++) {
        f[i] = (f[i - 1] * i) % m;
    }
}

// C++ function for extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long *x, long long *y);
 
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
long long modInverse(long long b, long long m)
{
    long long x, y; // used in extended GCD algorithm
    long long g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}
 
// Function to compute a/b under modulo m
long long modDivide(long long a, long long b, long long m)
{
    a = a % m;
    long long inv = modInverse(b, m);
    if (inv == -1)
    	return -1;
    else
       return (inv * a) % m;
}
 
// C function for extended Euclidean Algorithm (used to
// find modular inverse.
long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

bool prime[N + 1];

/* O(N * Log(Log(N))). */
vector<long long> sieve(long long n) {
    vector<long long> p;

    // Initializing.
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    // For every number i from 2 to N.
    for (long long i = 2; i <= n; i++) {
        // If current number is prime.
        if (prime[i]) {
            p.push_back(i);

            // Marking its multiples as not prime.
            for (long long j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    return p;
}

vector<pair<ll,ll>> a;

ll DP[4046][2023];

ll dp(ll i, ll k){
	if(i == a.size()){
		if(k == 0){
			// cout << "return 1" << endl;
			return 1;
		}
		else{
			// cout << "return 0 k:" << k << endl;
			return 0;
		}
	}

	if(DP[i][k] != -1) return DP[i][k];

	if(prime[a[i].fi] and k){
		ll r = (modDivide(dp(i+1, k-1) , f[a[i].se-1], MOD) + modDivide(dp(i+1, k) , f[a[i].se], MOD)) %MOD; 
		return DP[i][k] = r;
	}
	ll r = modDivide(dp(i+1, k) , f[a[i].se], MOD);
	return DP[i][k] = r;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	sieve(1000000);
	nck_init(MOD);

	ll n;
	cin >> n;
		
	map<ll ,ll> cnt;

	for(ll i = 0; i < 2*n; i++){
		ll x;
		cin >> x;
		cnt[x]++;
	}

	for(auto i : cnt){
		a.push_back(i);
	}

	memset(DP, -1, sizeof(DP));

	ll r = dp(0,n);

	ll div = ((r % MOD) * f[n]) % MOD;

	cout << div << endl;

    return 0;

}

/*

2 3 5

3 * 

*/