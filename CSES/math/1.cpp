#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;

ll f(ll n, ll k){
	if(n == 1) return 1;

	if(k <= (n+1)/2){
		if(2*k > n) return 1;
		return 2*k;
	}

	ll x = f(n/2, k - (n+1)/2);

	if(n%2) return 2*x + 1;
	return 2*x - 1;
}

// 1 2 3 4 5 6 7  - 7, 5
// 3 5 7          - 3, 1

void solve(){
	ll n, k;
	cin >> n >> k;

	cout << f(n, k) << endl;
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
