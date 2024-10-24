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

void solve(){
	int n;
	cin >> n;

	vector<pair<long long,long long>> a(n); 
	for(int i = 0; i < n; i++){
		cin >> a[i].fi >> a[i].se;
	}

	sort(a.begin(), a.end());

	long long ans = 0;
	long long cur = 0;
	for(int i = 0; i < n; i++){
		cur += a[i].fi;
		ans += (a[i].se - cur);
	}

	cout << ans << endl;
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