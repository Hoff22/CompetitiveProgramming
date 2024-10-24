#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

#define N 400024
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF (1000000000ll * 200000ll)
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

void solve(){
	ll n, x;
	cin >> n >> x;

	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	map<ll, vector<pair<int,int>>> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			ll s = a[j]+a[i];
			m[s].push_back({j,i});
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			ll s = a[j]+a[i];
			for(auto [l,r] : m[x-s]){
				if(l != j and l != i and r != j and r != i){
					cout << l+1 << " " << r+1 << " " << j+1 << " " << i+1 << endl;
					return;
				}
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;

}

/*


5 12 - 7+
6 10 - -1
8 15 - -4


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