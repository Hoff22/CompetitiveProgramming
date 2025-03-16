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

using ll = unsigned long long;

/* O(1) - Retrieves the index of the Most Significant Bit. */
ll msb_index(ll mask) {
    return 8ll * sizeof(mask) - __builtin_clzll(mask) - 1ll;
}

/* O(1) - Retrieves ceil(log2(n)). */
ll floor_log2(ll n) {
    assert(n > 0);
    return msb_index(n);
}

ll p[61][64];

double logb(ll n, ll b){
	return log2(n) / log2(b);
}

ll floor_logb(ll n, ll b){
	ll ans = 0;
	while(n >= b){
		ans++;
		n /= b; 
	}

	return ans;
}

ll check(ll l, ll r, ll b){
	ll last = l;
	ll ans = 0;

	for(ll i = floor_logb(l,b)+1; i <= 61; i++){
		ll cur = min(r, p[b][i]-1);

		ans += (((cur - last + 1) % MOD) * ((i-1) % MOD)) % MOD;
		ans %= MOD;  

		last = cur+1;
		if(cur == r) break;
	}

	return ans % MOD;
}

void solve(){
	int n;
	cin >> n;

	while(n--){
		ll l, r;

		cin >> l >> r;

		
		ll last = l;
		ll ans = 0;

		// cout << "l: " <<  l << endl;
		for(int i = floor_log2(l)+1; i <= 61; i++){
			ll cur = min(r, p[2][i]-1);

			// cout << "i: " << i << " cur: " << cur << endl;
			ll b = floor_log2(cur);

			// cout << i << " " << b << " " << last << " " << cur << endl;

			ans = (ans + check(last, cur, b) ) % MOD;
			last = cur+1;

			if(cur == r) break;
			// cout << ans << endl;
		}

		cout << ans << endl;

	}

}

/*
6
2 2 4 5 3 2
.
. .
. . . .



*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;

	for(ll b = 2; b <= 60; b++){
		p[b][0] = 1;
		// cout << b << " : ";
		for(int i = 1; p[b][i-1] <= LONG_LONG_MAX/b ; i++){
			// cout << i << " .. ";
			p[b][i] = (p[b][i-1] * b);
		}
		// cout << endl;
	}
	
	while(t--){
		solve();
	}
    return 0;

}