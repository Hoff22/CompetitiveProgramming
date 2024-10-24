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
using namespace __gnu_pbds;
 
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order(x)


void solve(){
	int n;
	cin >> n;

	vector<int> l(n+1);
	vector<int> r(n+1);
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
	}

	vector<pair<int,int>> e;
	for(int i = 1; i <= n; i++){
		e.push_back({l[i], -i});
		e.push_back({r[i], +i});
	}

	auto cmp = [&](pair<int,int> a, pair<int,int> b){
		if(a.fi == b.fi){
			if((a.se > 0) and (b.se > 0)){
				return l[a.se] > l[b.se];
			}
			return a.se < b.se;
		}
		return a.fi < b.fi;
	};

	sort(e.begin(), e.end(), cmp);

	vector<int> ans1(n+1, 0);
	vector<int> ans2(n+1, 0);

	ordered_set op;
	ordered_set cl;

	for(auto [ignore, i] : e){
		if(i > 0){
			ans1[i] = (int)cl.size() - cl.order_of_key({l[i], 0});
			op.erase({l[i], i});
			ans2[i] = op.order_of_key({l[i], n+1});
			cl.insert({l[i], i});
		}
		else{
			i *= -1;
			op.insert({l[i], i});
		}
	}

	for(int i = 1; i <= n; i++) cout << ans1[i] << " ";
	cout << endl;
	for(int i = 1; i <= n; i++) cout << ans2[i] << " ";
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