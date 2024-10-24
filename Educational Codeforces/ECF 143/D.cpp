#include <bits/stdc++.h>

#define N 200000
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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	nck_init(MOD);
	
	int n;
	scanf("%d", &n);

	vector<map<int, long long>> a(n/3);

	for(int i = 0; i < n/3; i++){
		int j,k,l;
		scanf("%d %d %d", &j,&k,&l);
		a[i][j]++;
		a[i][k]++;
		a[i][l]++;
	}

	long long ans = 1;
	for(int i = 0; i < n/3; i++){
		ans = (ans * (a[i].begin()->se)) % MOD;
		//printf("%d : (%d, %lld)\n", i, (a[i].begin()->fi), (a[i].begin()->se));
	}

	ans = (ans * nck(n/3, n/6, MOD)) % MOD;

	printf("%lld\n", ans);

    return 0;

}