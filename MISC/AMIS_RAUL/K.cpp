#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define e 2.7182818284590452353602874713527
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

#define endl '\n'

typedef long long ll;

using namespace std;

ll f[N+1];
vector<int> prs;

tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
    ll x, y, gcd;
    if (a == 0) {
        return {b, 0, 1};
    }
    tie(gcd, x, y) = extended_gcd(b % a, a);
    return {gcd, y - (b / a) * x, x};
}
ll modular_inverse(ll a, ll m) {
    ll gcd, x, y;

    tie(gcd, x, y) = extended_gcd((a % m + m) % m, m);

    if (gcd != 1) {
        return 0;
    }

    return (x % m + m) % m;
}
ll nck(ll n, ll k, ll m) {
    ll num, den;

    if(n == k) return 1;

    // Trivial case.
    if (k < 0 or k > n) {
        return 0;
    }

    num = f[n];
    den = (f[k] * f[n - k]) % m;

    return (num * modular_inverse(den, m)) % m;
}

ll ffp(ll a, ll b, ll mod){
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

ll mult(ll a, ll b, ll m){
	a %= m;
	b %= m;
	return (a * b) % m;
}

ll mult(const vector<ll>& l, ll mod){
	ll cur = 1;
	for(ll i : l){
		cur = (cur * i) % mod;
	}
	return cur;
}

ll sub(ll a, ll b, ll m){
	a %= m;
	b %= m;
	return (a - b + m) % m;
}

ll add(ll a, ll b, ll m){
	return (a + b) % m;
}

void solve(){
	ll n, mod;
	cin >> n >> mod;
	f[0] = 1;
	for(ll i = 1; i <= 2*n; i++){
		f[i] = (f[i-1] * i) % mod;
	}
	for(int i = 2; i <= n; i++){
		prs.push_back(i);
		for(int d = 2; d*d <= i; d++){
			if(i % d == 0){
				prs.pop_back();
				break;
			}
		}
	}

	n = n-1;

	// 

	ll any = mult({f[2*n], modular_inverse(ffp(2,n,mod), mod)}, mod);
	for(int k = 1; k <= n; k++){
		ll rem = mult({nck(n,k,mod) , f[2*n - k], modular_inverse(ffp(2, n-k, mod), mod)}, mod);
		int sign;
		(k % 2) ? sign = -1 : sign = 1;
		any = add(any, rem * sign, mod);
	}
	// any
	cout << any << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}