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
	vector<pair<int,int>> e;
 
	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		e.push_back({r, l});
	}
 
	sort(e.begin(), e.end());
 
	int r = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(e[i].se >= r) ans++, r = e[i].fi;
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