#include <bits/stdc++.h>
 
#define fi first
#define se second
#define MOD 1000000007
#define N 1000000
 
using namespace std;
 
typedef long long ll;
 
tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
    ll x, y, gcd;
 
    if (a == 0) {
        return {b, 0, 1};
    }
 
    tie(gcd, x, y) = extended_gcd(b % a, a);
 
    return {gcd, y - (b / a) * x, x};
}
 
/* O(Log(M)) - Returns the modular multiplicative inverse of a mod m, if it exists.
Returns x that satisfies a * x = 1 (mod m) if a and m are coprime. Returns 0 otherwise. */
ll modular_inverse(ll a, ll m) {
    ll gcd, x, y;
 
    tie(gcd, x, y) = extended_gcd((a % m + m) % m, m);
 
    if (gcd != 1) {
        return 0;
    }
 
    return (x % m + m) % m;
}
 
ll mdiv(ll a, ll b, ll mod){
	return (a * modular_inverse(b, mod)) % mod;
}
 
// O(log_2(N))
ll _pow(ll a, ll b, ll mod){
    ll res = 1;
    while(b){
        if(b&1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res; 
}
 
void solve(){
	ll n;
	cin >> n;
 
	vector<ll> p(n), a(n);
	for(int i = 0; i < n; i++){
		cin >> p[i] >> a[i];
	}
 
	ll ans1 = 1;
	vector<ll> ld(n), rd(n);
	for(int i = 0; i < n; i++){
		ans1 = (ans1 * (a[i]+1)) % MOD;
		if(i == 0){
			ld[i] = (a[i] + 1) % (MOD-1);
		}
		else{
			ld[i] = (ld[i-1] * (a[i] + 1)) % (MOD-1);
		}
	}
	for(int i = n-1; i >= 0; i--){
		if(i == n-1){
			rd[i] = (a[i] + 1) % (MOD-1);
		}
		else{
			rd[i] = (rd[i+1] * (a[i] + 1)) % (MOD-1);
		}
	}
 
	ll ans2 = 1;
	for(int i = 0; i < n; i++){
		ll t = (mdiv((_pow(p[i], a[i]+1, MOD) - 1) % MOD, (p[i] - 1) % MOD, MOD) - 1) % MOD;
		ll cur = (ans2 * t) % MOD;
		ans2 = (ans2 + cur) % MOD;
	}
 
	ll ans3 = 1;
	for(int i = 0; i < n; i++){
		// ll y = mdiv(divs, a[i]+1, MOD-1);
		// ll x = mdiv((a[i] * a[i] + a[i]) % (MOD-1), 2, MOD-1);
		// ll t = _pow(p[i], (y*x) % (MOD-1), MOD);
		// ans3 = (ans3 * t) % MOD;
 
		ll y, x, t;
 
		if(i == 0) x = 1;
		else x = ld[i-1];
 
		if(i == n-1) x *= 1;
		else x = (x * rd[i+1]) % (MOD-1);
 
		y = ((a[i] * a[i] + a[i]) / 2) % (MOD-1);
 
		t = _pow(p[i], (x*y) % (MOD-1), MOD);
		
		ans3 = (ans3 * t) % MOD;
	}
 
	cout << ans1 << " " << ans2 << " " << ans3 << endl;
}
 
int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	int t;
	t = 1;
	while(t--){
		solve();
	}
    return 0;
}