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

typedef long long ll;

vector<pair<ll,ll>> state;
vector<ll> cnt;


void solve(){
	int n, m;
	cin >> n >> m;

	state.assign(n+1, {0,0});
	cnt.assign(n+m+1, 0);

	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		state[i] = {x, 0};
	}

	ll ans = 0;
	for(int i = 1 ; i <= m; i++){
		int p, v;
		cin >> p >> v;
		
		ans += (i - state[p].se) * (state[p].se);
		ans += (i - state[p].se) * (i - state[p].se - 1) / 2;
		ans += (i - state[p].se) * (state[p].se - cnt[state[p].fi]);

		cnt[state[p].fi] += (i - state[p].se);
		state[p] = {v, i};
	}

	for(int p = 1; p <= n; p++){
		ans += (m - state[p].se + 1) * (state[p].se);
		ans += (m - state[p].se + 1) * (m - state[p].se) / 2;
		ans += (m - state[p].se + 1) * (state[p].se - cnt[state[p].fi]);
		cnt[state[p].fi] += (m - state[p].se + 1);
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