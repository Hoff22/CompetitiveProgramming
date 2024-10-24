#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int g,c,t;
	cin >> g >> c >> t;

	vector<ll> pg(g);
	vector<ll> pc(c);
	vector<ll> pt(t);
	
	for(int i = 0; i < c; i++) cin >> pc[i];
	for(int i = 0; i < g; i++) cin >> pg[i];
	for(int i = 0; i < t; i++) cin >> pt[i];

	vector<ll> lc(c); 

	for(int i = 0; i < c; i++){
		lc[i] = pc[i];
		for(int j = 0; j < g; j++){
			ll x; cin >> x;

			lc[i] -= x * pg[j];
		}
	}

	// for(int i =0; i < c; i++) cout << pc[i] << " ";
	// cout << endl;

	vector<vector<int>> needed(t, vector<int>());
	vector<vector<int>> need(t, vector<int>());

	for(int i = 0; i < c; i++){
		int n; cin >> n;
		for(int j = 0; j < n; j++){
			int tool; cin >> tool;

			if(lc[i] > 0){
				needed[tool-1].push_back(i);
				need[i].push_back(tool-1);
			}
		}
	}

	vector<int> rem(c, 0);

	set<int> s;

	// for(int  i= 0; i <c; i++) cout << lc[i] << " ";
	// cout << endl;

	ll ans = 0;
	while(true){
		int cho = -1;
		ll mx = -INF;
		for(int i = 0; i < c; i++){
			if(rem[i]) continue;
			ll ctr = 0;
			for(int tool : need[i]){
				if(s.count(tool)) continue;
				ctr += pt[tool]; 
			}

			if(lc[i] - ctr > mx){
				mx = lc[i] - ctr;
				cho = i;
			}
		}

		if(cho == -1) break;

		// cout << cho << " "  << mx << endl;

		rem[cho] = 1;
		for(int tool : need[cho]){
			s.insert(tool);
		}

		ll cakes = 0;
		ll tools = 0;
		for(int i : s) tools += pt[i];
		for(int i = 0; i < c; i++) if(rem[i]) cakes += lc[i];
		// cout << "\t" << cakes - tools << endl; 
		ans = max(ans, cakes - tools);
	}

	cout << ans << endl; 

    return 0;

}