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

using namespace std;


void solve(){
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> e;

	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		e.push_back({r, l});
	}

	sort(e.begin(), e.end());

	multiset<int> pq;
	for(int i = 0; i < k; i++) pq.insert(0);

	int ans = 0;
	for(int i = 0; i < n; i++){
		// cout << e[i].se << " " << pq.top() << endl;
		auto j = pq.upper_bound(e[i].se);
		if(j == pq.begin()) continue;
		j--;

		pq.erase(j);
		pq.insert(e[i].fi);
		ans++;
	}

	cout << ans << endl;
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