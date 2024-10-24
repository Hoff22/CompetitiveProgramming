#include <bits/stdc++.h>

#define fi first
#define se second
#define MOD 1000000007
#define N 1000000

using namespace std;

typedef long long ll;

/* O(Log(min(a, b))) - Returns a * b mod m without overflowing. 2 * (m - 1) must not overflow. */
ll mod_mul(ll a, ll b, ll m) {

    // In case a >= m or b >= m.
    if(a > m or b > m) return -1;

    // Forcing b to be the smallest.
    if (a < b) {
        swap(a, b);
    }

    ll ans = 0;

    // Decomposing b in binary. Adding to the answer a * 2^0, a * 2^1, a * 2^2, a * 2^4, a * 2^8, ...
    while (b > 0) {
        // If current bit is set.
        if (b & 1ll) {
        	if(a > m) return -1;
            ans = (ans + a);
            if(ans > m) return -1;
        }

        b >>= 1ll;         // Next bit.
        if(a <= m) a = (2ll * a); 	   // Next power of two multiplied by a.
    }

    return ans;
}

void solve(){
	ll n, k;
	cin >> n >> k;

	vector<ll> p(k);
	for(int i = 0; i < k; i++){
		cin >> p[i];
	}

	ll ans = 0;

	for(int m = 1; m < (1ll<<k); m++){
		ll cur = 1;
		int good = 1;
		for(int i = 0; i < k; i++){
			if((m>>i)&1){
				cur = mod_mul(cur, p[i], n);
				if(cur == -1){
					good = 0;
					break;
				}
			}
		}

		if(good){
			if(__builtin_popcount(m) % 2) ans += n/cur;
			else ans -= n/cur;
		}
	}

	// int ans2 = 0;

	// for(int i = 1; i <= n; i++){
	// 	for(int j = 0; j < k; j++){
	// 		if(i%p[j] == 0){
	// 			ans2++;
	// 			break;
	// 		}
	// 	}
	// }
	// cout << ans2 << endl;
	cout << ans << endl;
}

/*

        .         .              .              . 
    .     .     .       .        .        .    
  .   .   .   .   .     .     .     .     .     .
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
  

 
2 3 5


*/

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
