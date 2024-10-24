#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>

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
using namespace __gnu_pbds;
 
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order(x)
// order_of_key(x)

// mandar +20 pra betina

void solve(){
	int n, k;
	cin >> n >> k;

	ordered_set s;

	for(int i = 1; i <= n; i++){
		s.insert(i);
	}

	int cur = k;
	while(!s.empty()){
		// who's the k-th element (zero-based)
		auto p = s.find_by_order(cur%(int)s.size()); 
		cout << *p << " ";
		cur = s.order_of_key(*p) + k;
		s.erase(p);
	}

	cout << endl;
}

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