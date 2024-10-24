#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

typedef long long ll;

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n+1);

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	deque<pair<ll,ll>> st;

	for(int i = 1; i <= n; i++){
		if(st.empty()){
			st.push_back({a[i], 1ll});
			continue;
		}

		ll sum = a[i];
		ll cnt = 1;
		while(st.size() and (sum+cnt-1) / cnt <= st.back().fi){
			sum += st.back().fi * st.back().se;
			cnt += st.back().se;
			st.pop_back();
		}
		// cout << sum << " " << cnt << endl;
		st.push_back({sum/cnt,cnt - (sum%cnt)});
		if(sum%cnt) st.push_back({sum/cnt + 1, sum%cnt});
		// for(auto [k,g] : st) cout << "("<<k<<","<<g<<") ";
		// cout << endl;
	}

	ll mn = 0x3f3f3f3f3f3f3f3f;
	ll mx = 0;
	while(!st.empty()){
		mn = min(st.back().fi, mn);
		mx = max(st.back().fi, mx);
		st.pop_back();
	}
	cout << mx - mn << endl;
}

/*

5 14 4 10 2

5 14 . 4
5 9 9 10
5 9 9 10 . 2   
5 7 7 8 8
    

*/

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