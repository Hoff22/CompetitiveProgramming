#include <bits/stdc++.h>

#define N 1000100
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

ll n, m;

vector<vector<ll>> DP[6];

vector<ll> v[N+1];

void solve(){
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		v[i].push_back(0);
		for(int j = 1; j <= m; j++){
			ll x; cin >> x;
			v[i].push_back(x);
		}
	}

	for(int i = 0; i < 6; i++){
		DP[i] = vector<vector<ll>>(m+1, vector<ll>(n+1, 0));
	}


	for(int i = 1; i <= m; i++){
		ll BEST = 0;
		for(int a = 0; a < n; a++){
			for(int k = 0; k <= 5; k++){
				BEST = max(BEST, DP[k][i-1][a]);
			}
		}
		for(int a = 0; a < n; a++){
			// extend current range
			if(DP[5][i-1][a] or DP[4][i-1][a]){
				DP[5][i][a] = (max(DP[4][i-1][a], DP[5][i-1][a]) 	+  v[a][i] + 5) * (v[a][i] ? 1 : 0);
			}
			if(DP[3][i-1][a]){
				DP[4][i][a] = (DP[3][i-1][a]	+  v[a][i] + 4) * (v[a][i] ? 1 : 0);
			}
			if(DP[2][i-1][a]){
				DP[3][i][a] = (DP[2][i-1][a]	+  v[a][i] + 3) * (v[a][i] ? 1 : 0);
			}
			if(DP[1][i-1][a]){
				DP[2][i][a] = (DP[1][i-1][a]	+  v[a][i] + 2) * (v[a][i] ? 1 : 0);
			}
			if(DP[0][i-1][a] and v[a][i-1]){
				DP[1][i][a] = (DP[0][i-1][a]	+  v[a][i] + 1) * (v[a][i] ? 1 : 0);
			}

			// open new range
			DP[0][i][a] = BEST + v[a][i];

		}
		// for(int k = 0; k <= 5; k++){
		// 	cout << "DP["<< k << "][" << i << "]: " << DP[k][i][0] << "\t";
		// }
		// cout << endl;
	}

	ll ans = 0;
	for(int a = 0; a < n; a++){
		for(int k = 0; k <= 5; k++){
			ans = max(ans, DP[k][m][a]);
		}
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}