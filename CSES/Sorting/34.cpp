#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>

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
	multiset<int> s;
	int recent_close = 0;
	for(auto [ignore, i] : e){
		if(i > 0){
			if(recent_close >= l[i]) ans1[i] = 1;
			recent_close = max(recent_close, l[i]);
			s.erase(s.lower_bound(l[i]));
			if(!s.empty() and *s.begin() <= l[i]) ans2[i] = 1; // eh contido por alguem
		}
		else{
			i *= -1;
			s.insert(l[i]);
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