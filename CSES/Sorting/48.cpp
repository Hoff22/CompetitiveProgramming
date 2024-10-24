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
using namespace __gnu_pbds;
 
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;// find_by_order(x)

typedef long long ll;

void solve(){
	int n, k;
	cin >> n >> k;

	vector<int> a(n);

	ordered_set s;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i < k-1){
			s.insert(make_pair(a[i],i));
		} 
	}

	for(int i = 0, j = k-1; j < n; j++, i++){
		s.insert(make_pair(a[j], j));
		cout << (*s.find_by_order((k-1)/2)).fi << " ";
		s.erase(make_pair(a[i], i));
	}

	cout << endl;
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