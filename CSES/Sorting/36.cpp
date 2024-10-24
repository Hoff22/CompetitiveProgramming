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

	vector<pair<int,int>> e;
	for(int i = 1; i <= n; i++){
		int l, r;
		cin >> l >> r;
		e.push_back({l, -i});
		e.push_back({r, i});
	}

	sort(e.begin(), e.end());
	vector<int> ans(n+1, 0);

	int cur = 1;
	set<int> rooms;
	for(auto [p, i] : e){
		if(i < 0){
			i *= -1;
			if(rooms.empty()){
				ans[i] = cur;
				cur++;
			}
			else{
				ans[i] = *rooms.begin();
				rooms.erase(*rooms.begin());
			}
		}
		else{
			rooms.insert(ans[i]);
		}
	}

	cout << cur-1 << endl;
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
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