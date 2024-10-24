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

pair<ll,ll> calc(ll a, ll b, ll c){
	ll l = 0;
	ll r = 1000000000;
	ll ansL = 0;

	if(4*a*c < 0){
		return {0,INF};
	}

	ll delta = b*b - 4*a*c;

	while(l <= r){
		ll m = l + (r-l) / 2;

		if((b-m)*(b-m) - 4*a*c >= 0 or -delta/(4*a*m) <= -b/2*a){
			ansL = m;
			r = m-1;
		}
		else{
			l = m+1;
		}
	}

	l = 0;
	r = 1000000000;
	ll ansR = 0;
	while(l <= r){
		ll m = l + (r-l) / 2;

		if((b-m)*(b-m) - 4*a*c >= 0 or -delta/(4*a*m) >= -b/2*a){
			ansR = m;
			l = m+1;
		}
		else{
			r = m-1;
		}
	}

	return {ansL, ansR};
}

/*

kx = -delta/4ak

*/

void solve(){
	ll n, m;
	cin >> n >> m;

	vector<ll> ks(n);
	for(ll i = 0; i < n; i++){
		cin >> ks[i];
	}

	sort(ks.begin(), ks.end());

	for(ll i = 0; i < m; i++){

		ll a, b, c;
		cin >> a >> b >> c;

		pair<ll, ll> k_m = calc(a,b,c);

		cout << "\t" << k_m.fi << " " << k_m.se << endl;

		auto pL = lower_bound(ks.begin(),ks.end(), k_m.fi);
		auto pR = lower_bound(ks.begin(),ks.end(), k_m.se);
		if(pL != ks.begin()){
			pL--;
			cout << "YES" << endl;
			cout << *pL << endl;
			continue;
		}
		if(pR != ks.end()){
			cout << "YES" << endl;
			cout << *pR << endl;
			continue;
		}

		cout << "NO" << endl;
	}
}

/*

ax^2 + bx + c = kx

ax^2 + bx - kx = -c

x(ax + b - k) = -c

ax^2+(b−k)x+c = 0



(b-k)*(b-k) - 4*a*c < 0



b^2 -2bk + k^2 - 4*a*c < 0



b^2 - 4*a*c < 2bk - k^2

2ax + b = k

(k-b)/2a = x

xv = -b/2a
yv = -delta/4a

*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}