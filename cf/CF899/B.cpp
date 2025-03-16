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
	int n;
	cin >> n;

	vector<set<int>> a(n, set<int>());

	set<int> s;

	for(int i = 0; i < n; i++){
		int k; cin >> k;
		for(int j = 0; j < k; j++){
			int x;cin >> x;
			a[i].insert(x);
			s.insert(x);
		}
	}

	int ans = 0;

	for(int i : s){
		set<int> s2;
		for(int j = 0; j < n; j++){
			if(a[j].count(i)) continue;
			for(int k : a[j]) s2.insert(k);
		}

		if(s2.size() != s.size()){
			ans = max(ans, (int)s2.size());
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