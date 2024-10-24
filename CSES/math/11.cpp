#include <bits/stdc++.h>

#define fi first
#define se second
#define MOD 1000000007
#define N 1000000

using namespace std;

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

/* O(N). */
void nck_init(long long m) {
    f[0] = 1;

    for (long long i = 1; i <= N; i++) {
        f[i] = (f[i - 1] * i) % m;
    }
}

void solve(){
	string s;
	cin >> s;

	int n = (int)s.size();

	vector<int> cnt(26,0);
	for(char c : s) cnt[c-'a']++;

	long long ans = f[n];
	for(int i = 0; i < 26; i++){
		ans = (ans * modular_inverse(f[cnt[i]], MOD)) % MOD;
	}

	cout << ans << endl;
}

// 28 - 3 - 0 - 3 - 0

int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nck_init(MOD);

	int t;
	t = 1;
	while(t--){
		solve();
	}
    return 0;
}
