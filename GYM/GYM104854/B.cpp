#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int N = 2000000;
constexpr int M = 1000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;

typedef long long ll;

vector<multiset<ll>> b(N+1, multiset<ll>());
vector<pair<ll,ll>> a(N+1, {0,0});

void solve(){
	int n;
	cin >> n;

	while(n--){
		ll op, d, v;
		cin >> op >> d >> v;

		if(op == 1){

			b[d].insert(v);

			while(d){
				if(b[d].size()) a[d].fi = max({0ll,*b[d].rbegin()+a[d*2].fi,*b[d].rbegin()+a[d*2+1].fi});
				else a[d].fi = 0ll;

				a[d].se = max({a[d*2].se, a[d*2+1].se, a[d].fi});

				d>>=1;
			}

			cout << a[1].se << endl; 
		}
		else{
			b[d].erase(b[d].lower_bound(v));

			while(d){
				if(b[d].size()) a[d].fi = max({0ll,*b[d].rbegin()+a[d*2].fi,*b[d].rbegin()+a[d*2+1].fi});
				else a[d].fi = 0ll;

				a[d].se = max({a[d*2].se, a[d*2+1].se, a[d].fi});

				d>>=1;
			}

			cout << a[1].se << endl; 
		}
	}
	
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}