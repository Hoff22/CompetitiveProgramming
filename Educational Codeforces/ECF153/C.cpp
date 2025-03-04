#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

void solve(){
	int n;cin >> n;
	vector<int> a(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ordered_set s;
	ordered_set zero;

	int ans = 0;

	for(int i = 0; i < n; i++){
		s.insert(a[i]);
		if(s.order_of_key(a[i]) == 0){
			zero.insert(a[i]);
		}
		else if(zero.order_of_key(a[i]) == s.order_of_key(a[i])){
			ans++;
		}
	}

	cout << ans << endl;

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}