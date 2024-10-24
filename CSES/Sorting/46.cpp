#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

#define N 200000
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
	ll n, k;
	cin >> n >> k;

	ll ans = 0;
	vector<int> a(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int cnt = 0;
	map<int,ll> s;
	for(int i = 0, j = 0; i < n; i++){
		while(j < n and (cnt < k or (cnt == k and s[a[j]] > 0))){
			if(s[a[j]] == 0) cnt++;
			s[a[j]]++;
			j++;
		}
		// cout << i << " " << j << endl;
		ans += (j-i);
		if(s[a[i]] == 1) cnt--;
		s[a[i]]--;
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
	int t;
    cin.tie(NULL);
	t = 1;
	while(t--){
		solve();
	}
    return 0;

}