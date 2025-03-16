#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
	ll n, k, x, y;

	cin >> n >> k >> x >> y;

	vector<ll> a, b;
	for(int i = 0; i < n; i++){
		char t;
		ll v;
		cin >> t >> v;
		if(t == 'A') a.push_back(v);
		else b.push_back(v);
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());

	if(a.size() < k){
		vector<ll> b_l(b.begin(), b.begin()+k);
		vector<ll> b_r(b.begin()+k, b.end());
		reverse(b_r.begin(), b_r.end());

		while(a.size() < k){
			a.push_back(b_r.back()-y);
			b_r.pop_back();
		}

		reverse(b_r.begin(), b_r.end());

		for(ll i : b_r) b_l.push_back(i);
		b = b_l;
	}	
	else if(b.size() < k){
		vector<ll> a_l(a.begin(), a.begin()+k);
		vector<ll> a_r(a.begin()+k, a.end());
		reverse(a_r.begin(), a_r.end());

		while(b.size() < k){
			b.push_back(a_r.back()-x);
			a_r.pop_back();
		}

		reverse(a_r.begin(), a_r.end());

		for(ll i : a_r) a_l.push_back(i);
		a = a_l;
	}	

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());

	multiset<ll> as(a.begin(),a.begin()+k), bs(b.begin(),b.begin()+k);

	ll acc = 0;
	for(int i = 0; i < k; i++){
		acc += a[i] + b[i]; 
	}

	ll ans1 = acc, ans2 = acc;

	for(int i = k; i < a.size(); i++){
		if(*bs.begin() < a[i]-x){
			ll p = *bs.begin();
			bs.erase(bs.lower_bound(p));
			bs.insert(a[i]-x);
			ans1 += (a[i]-x) - p;
		}
	}
	for(int i = k; i < b.size(); i++){
		if(*as.begin() < b[i]-y){
			ll p = *as.begin();
			as.erase(as.lower_bound(p));
			as.insert(b[i]-y);
			ans2 += (b[i]-y) - p;
		}
	}

	cout << max(ans1, ans2) << endl;
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