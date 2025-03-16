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
	int n; cin >> n;
	vector<int> a(n+1);
 
	set<int> p[3];

	for(int i = 1; i <= n; i++){
		cin >> a[i];

		p[a[i]].insert(i);
	}

	vector<pair<int,int>> ans;
	p[0].insert(-100000000);
    p[2].insert( 100000000);
	while(true){
		if(*p[0].rbegin() < *p[1].begin() and *p[1].rbegin() < *p[2].begin())break;
		while(*p[1].rbegin() > *p[2].begin()){
			int on = *p[1].rbegin(), tw = *p[2].begin();
			p[1].erase(on);
			p[1].insert(tw);
			p[2].erase(tw);
			p[2].insert(on);
			ans.push_back({on,tw});
		}
		while(*p[0].rbegin() > *p[1].begin()){
			int on = *p[0].rbegin(), tw = *p[1].begin();
			p[0].erase(on);
			p[0].insert(tw);
			p[1].erase(tw);
			p[1].insert(on);
			ans.push_back({on,tw});
		}
	}

	cout << ans.size() << endl;
	for(auto [u,v] : ans) cout << u << " " << v << endl; 
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