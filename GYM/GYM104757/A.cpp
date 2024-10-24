#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/* ordered_set<int> s - Declaration
   s.order_of_key(x) - Returns the number of elements lesser than x in s. If x is in s then this corresponds to its 0-based index k.
   s.find_by_order(k) - Returns the k-th element in s. Use k such that 0 <= k < s.size(). */
template <class TKey, class TValue>
using ordered_map = __gnu_pbds::tree<TKey, TValue, less<TKey>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class TKey>
using ordered_set = ordered_map<TKey, __gnu_pbds::null_type>;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	ordered_set<int> l, r;
	
	for(int i = 0; i < n; i++){
		r.insert(a[i]);
	}

	vector<int> ans;

	for(int i = 0; i < n; i++){
		r.erase(a[i]);
		if(r.order_of_key(a[i]) == 0 and l.order_of_key(a[i]) == l.size()){
			ans.push_back(a[i]);
		}
		l.insert(a[i]);
	}

	cout << ans.size() << " ";

	for(int i = 0; i < min(100, (int)ans.size()); i++){
		cout << ans[i] << " ";
	}
	cout << endl;

    return 0;

}