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

void solve(){
	ll n, q;
	cin >> n >> q;

	vector<ll> acc(n+1, 0);
	for(int i = 1; i <= n; i++){
		ll x;
		cin >> x;
		acc[i] = acc[i-1] + x;
	}

	ll total = acc[n];

	while(q--){
		ll l, r, k;
		cin >> l >> r >> k;
	
		if((total - (acc[r]-acc[l-1]) + (r-l+1)*k) % 2){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
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