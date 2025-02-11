#include <bits/stdc++.h>
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
using namespace std;
 
#define dbg(x) { cerr << #x << " = " << x << "\n"; } 
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull; 

//min T, such that T * T >= TARGET
ll get_sqrt(ull x) {
	ll ans = (ll)sqrt(x);
	if((ans)*(ans) < x) ans++;
	if((ans-1)*(ans-1) >= x) ans--;
	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m;

	set<ll> positive_k, negative_k;
	for(int i = 1; i <= n; i++) {
		ll e;
		cin >> e;
		if(e >= 0) {
			positive_k.insert(e);
		} else {
			negative_k.insert(e);
		}
	}


	for(int i = 1; i <= m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;


		ll target = 4*a*c;
		
		if(target <= 0) {
			cout << "NO\n\n";
			continue;
		}


		ll T = get_sqrt(target);
		//dbg(T)

		if(b >= 0) {
			if(b <= T) {
				if(negative_k.size() && (b-*negative_k.rbegin()) < T) {
					cout << "YES\n" << *negative_k.rbegin() << "\n";
					continue;
				} else {
					if(positive_k.size() && abs(b-*positive_k.begin()) < T) {
						cout << "YES\n" << *positive_k.begin() << "\n";
						continue;
					}
				}
				cout << "NO\n";
				continue;
			}

			auto it = positive_k.upper_bound(b - T);
			if(it != positive_k.end()){
				if(abs(b-*it) < T) {
					cout << "YES\n" << *it << "\n";
					continue;
				}
			}

			cout << "NO\n\n";
			continue;
			
		} else {
			if(abs(b) <= T) {
				if(positive_k.size() && abs(b-*positive_k.begin()) < T){
					cout << "YES\n" << *positive_k.begin() << "\n";
					continue;
				} else {
					if(negative_k.size() && abs(b-*negative_k.rbegin()) < T) {
						cout << "YES\n" << *negative_k.rbegin() << "\n";
						continue;
					}
				}
				cout << "NO\n\n";
				continue;
			}

			auto it = negative_k.lower_bound(-1*(abs(b) - T));
			if(it == negative_k.end()) it--;
			if(it != negative_k.end()) {
				it--;
				if(it != negative_k.end()) {
					if(abs(b-*it) < T) {
						cout << "YES\n" << *it << "\n";
						continue;
					}
				}
			}
			cout << "NO\n\n";
			continue;
		}
	}
}
 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
 
	return 0;
}