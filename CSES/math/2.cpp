#include <bits/stdc++.h>

#define fi first
#define se second
#define MOD 1000000007

using namespace std;

typedef long long ll;

// O(log_2(N))
long long fast_pow(long long a, long long b, long long mod){
    long long res = 1;
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
	ll a, b;
	cin >> a >> b;

	cout << fast_pow(a, b, MOD) << endl;
	//cout << fast_pow(fast_pow(a, b, MOD), c, MOD) << endl;
}
 
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
