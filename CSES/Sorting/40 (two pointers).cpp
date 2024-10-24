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

	vector<pair<ll,int>> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].fi;
		a[i].se = i+1;
	}

	sort(a.begin(), a.end());

	for(int i = 0; i < n; i++){
		ll s = x-a[i].fi;
		int l = 0;
		int r = i-1;
		while(l < r and (a[l].fi + a[r].fi) != s){
			if((a[l].fi + a[r].fi) > s) r--;
			else l++;
		}
		if(l < r and a[l].fi + a[r].fi){
			cout << a[l].se << " " << a[r].se << " " << a[i].se << endl;
			return;
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