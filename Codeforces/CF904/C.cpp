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
	int n, m;
	cin >> n >> m;

	vector<pair<int,int>> seg; 
	vector<pair<int,int>> e;

	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		seg.push_back({l,r});
	}


	e.clear();
	for(int i = 0; i < n; i++){
		int l, r;
		tie(l, r) = seg[i];
		if(l == 1) continue;
		e.push_back({l,-1});
		e.push_back({r, 1});
	}
	sort(e.begin(), e.end());

	int mx1 = 0;

	int cur = 0;
	for(auto [p, op] : e){
		if(op == -1){
			cur++;
		}
		else{
			cur--;
		}
		if(mx1 < cur){
			mx1 = cur;
		}
	}

	e.clear();
	for(int i = 0; i < n; i++){
		int l, r;
		tie(l, r) = seg[i];
		if(r == m) continue;
		e.push_back({l,-1});
		e.push_back({r, 1});
	}
	sort(e.begin(), e.end());

	int mx2 = 0;

	cur = 0;
	for(auto [p, op] : e){
		if(op == -1){
			cur++;
		}
		else{
			cur--;
		}
		if(mx2 < cur){
			mx2 = cur;
		}
	}

	cout << max(mx2, mx1) << endl;
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