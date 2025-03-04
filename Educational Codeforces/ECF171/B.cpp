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

typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n+1);

	for(int i = 1; i <= n; i++) cin >> a[i];

	ll l = 1;
	ll r = 1000000000000000000;
	ll ans = 0x3f3f3f3f3f3f3f3f;
	while(l <= r){
		ll m = l + (r - l) / 2;

		int good = 1;

		int p = 1;
		for(int i = 1; i <= n; i+=2){
			if(i == n){
				if(!p) good = 0;
			}
			else if(a[i+1] - a[i] > m){
				if(p){
					p--;
					i--;
					continue;
				}
				good = 0;
				break;
			}
		}

		if(good){
			ans = m;
			r = m-1;
		}
		else{
			l = m+1;
		}
	}

	cout << ans << endl;
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