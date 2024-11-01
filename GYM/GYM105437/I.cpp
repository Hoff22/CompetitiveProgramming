#include <bits/stdc++.h>

#define N 5000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vector<int> l(m+1,0);
	int cur = 0;
	for(int i = 0; i < n; i++){
		l[cur] = i;
		if(a[i] == 0) cur++;
	}
	l[cur] = n;
	
	vector<ll> ans(m+1,0);

	for(int k = 1; k <= m; k++){
		ordered_multiset<int> str;
		ordered_multiset<int> inte;
		for(int i = l[k-1]; i < l[k]; i++){
			if(a[i] > 0) inte.insert(a[i]);
			if(a[i] < 0) str.insert(-a[i]);
		}

		for(int j = k; j >= 1; j--){
			ans[j] = max(
				ans[ j ] + (ll)inte.order_of_key(k-j+1) + (ll)str.order_of_key(j+1),
				ans[j-1] + (ll)inte.order_of_key(k-j+1) + (ll)str.order_of_key(j+1)
			);
		}
		ans[0] = ans[ 0 ] + (ll)inte.order_of_key(k+1) + (ll)str.order_of_key(0+1);
	}

	ll as = 0;
	for(int i = 0; i <= m; i++){
		as = max(as, ans[i]);
	}
	cout << as << endl;
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