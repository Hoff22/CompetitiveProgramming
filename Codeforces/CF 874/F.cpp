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

typedef long long ll;

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

void solve(){
	int n, m;
	cin >> n >> m;
	vector<ll> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	vector<ll> a;
	vector<ll> val;

	sort(v.begin(),v.end());
	
	a.push_back(-1);
	val.push_back(-1);
	for(int i = 0; i < n; i++){
		if(i == 0 or v[i] != v[i-1]){
			a.push_back(1);
			val.push_back(v[i]);
		}
		else{
			a[a.size()-1]++;
		}
	}

	n = a.size()-1;

	vector<ll> acc(n+1, 1);

	for(int i = 1; i <= n; i++){
		acc[i] = (acc[i-1] * a[i]) % MOD;
	}

	ll ans = 0;
	for(int l = 1; l <= n; l++){
		int r = l+m-1;

		if(r > n) break;
		if(val[r] - val[l] >= m) continue;

		ans += (acc[r] * modular_inverse(acc[l-1], MOD)) % MOD;
		ans %= MOD;
	}

	cout << ans << endl;
}

/*

5 3
4 2 2 3 6

2 2 3 4 6

2 1 1 1

*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}