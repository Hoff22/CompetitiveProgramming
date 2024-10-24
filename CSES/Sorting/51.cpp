#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

#define N 400000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF (1000000000ll * 200000ll)
#define se second
#define fi first

using namespace std;
 
typedef long long ll;

void solve(){
	int n, a, b;
	cin >> n >> a >> b;

	vector<ll> v(n+1);
	vector<ll> acc(n+1,0);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		acc[i] = acc[i-1] + v[i];
	}

	ll ans = -INF;

	multiset<ll> s;
	int i, j;
	for(int k = 1; k <= n; k++){
		// k-j+1 = a
		// k-a+1 = j
		j = k-a;
		i = k-b-1;

		if(j >= 0){
			s.insert(acc[j]);
		}
		if(i >= 0){
			s.erase(s.lower_bound(acc[i]));
		}

		if(s.size()){
			ans = max(ans, acc[k] - *s.begin());
		}
	}

	cout << ans << endl;
}

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