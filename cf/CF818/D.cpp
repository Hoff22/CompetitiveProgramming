#include <bits/stdc++.h>

#define N 100000
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

void solve(){
	long long n, k;
	scanf("%lld %lld", &n, &k);
	
	long long sum = 0;
	for(long long i = 1; i <= min(k, n); i++){
		sum = (sum + nck(n,i,MOD)) % MOD;
	}
	printf("%lld\n", sum+1);

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nck_init(MOD);

	solve();
    return 0;

}