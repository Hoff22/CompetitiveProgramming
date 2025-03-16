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
	ll n, q;
	cin >> n;

	vector<ll> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 

	vector<ll> sum(n+10,0), block(n+10,0), sumBlock(n+10,0), ele(n+10,0);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i];
	}
	for(ll i = n; i >= 1; i--){
		ele[i] = n-i+1 + ele[i+1];
	}
	ele[0] = ele[1];
	block[n] = a[n];
	for(ll i = n-1, k = 2; i >= 1; i--, k++){
		block[i] = block[i+1] + k * a[i];
	}
	for(int i = 1; i <= n; i++){
		sumBlock[i] = sumBlock[i-1] + block[i];
	}
	sumBlock[n+1] = sumBlock[n];

	cin >> q;

	while(q--){
		ll L, R;
		cin >> L >> R;
		R++;
		ll lb, rb, l, r, ans, of;

		lb = 0, rb = n;
		while(lb <= rb){
			ll m = lb + (rb - lb) / 2;
			ll s = ((n+1)*n)/2 - ele[m+1];
			if(s >= L) l = m, rb = m-1;
			else lb = m+1;
		}
		lb = 0, rb = n;
		while(lb <= rb){
			ll m = lb + (rb - lb) / 2;
			ll s = ele[m];
			if(s > ((n+1)*n)/2 - R) r = m, lb = m+1;
			else rb = m-1;
		}

		ans = sumBlock[r] - sumBlock[l];

		of = ((n*(n+1))/2 - ((n-l)*(n-l+1))/2) - L;
		ans += block[n-of] + (sum[n-of-1] - sum[l-1]) * (of + 1);
		// cout << "+= block["<<n-of<<"] + (sum["<<n-of-1<<"] - sum["<<l-1<<"]) * " << (of + 1) << endl;

		of = ((n*(n+1))/2 - ((n-r)*(n-r+1))/2) - R;
		ans -= block[n-of] + (sum[n-of-1] - sum[r-1]) * (of + 1);
		// cout << "-= block["<<n-of<<"] + (sum["<<n-of-1<<"] - sum["<<r-1<<"]) * " << (of + 1) << endl;

		cout << ans << endl;

		// cout << l << " " << r << endl;
	}
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