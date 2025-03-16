#include <bits/stdc++.h>

#define N 2000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int a[N+1][N+1];
vector<int> rows[N+1], cols[N+1];

ll DP[N+1][N+1][5];

ll dp(int r, int c, int i){
	// cout << r << " " << c << " " << i << endl;
	
	if(i == 4) return 1;

	if(DP[r][c][i] != -1) return DP[r][c][i];

	ll res = 0;

	for(int nxt_c : rows[r]){
		if(nxt_c == c) continue;
		res += dp(r,nxt_c,i+1);
	}
	for(int nxt_r : cols[c]){
		if(nxt_r == r) continue;
		res += dp(nxt_r,c,i+1);
	}

	return DP[r][c][i] = res;
}

// N = max number n to compute n choose k;
// n choose k = choose[n][k]; 
ll choose[N+1][N+1];
ll f[N+1];

void pascal(){
	for(int i = 0; i <= N; i++){
		choose[i][0] = 1;
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= min(i,3); j++){
 			choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) /*% MOD*/;
		}
	}
}

void solve(){
	pascal();

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char x; cin >> x;
			a[i][j] = (x == '.');
			if(a[i][j]){
				rows[i].push_back(j);
				cols[j].push_back(i);
			}
		}
	}

	ll ans = 0;

	vector<int> r_cnt(n,0), c_cnt(m,0);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			r_cnt[i] += a[i][j];
		}
		ans -= choose[r_cnt[i]][3] * 6 * 3; // 3 in a row
		// ABCA | ABCB | 
	}

	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			c_cnt[j] += a[i][j];
		}
		ans -= choose[c_cnt[j]][3] * 6 * 3; // 3 in a row ABAC | ACAB
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j]){
				// B    ABAC | ACAB | BACA | CABA 
				// AC   
				ans -= (c_cnt[j]-1) * (r_cnt[i]-1) * 4;
				// A    ABAB
				// B
				ans -= (c_cnt[j]-1);
				// AB   ABAB
				ans -= (r_cnt[i]-1);
			}
		}
	}

	memset(DP, 0, sizeof(DP));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j]){
				DP[i][j][4] = 1;
			}
		}
	}

	for(int k = 3; k >= 1; k--){
		vector<ll> rows_l(n,0), cols_l(m,0);
		for(int r = 0; r < n; r++){
			for(int nxt_c : rows[r]){
				rows_l[r] += DP[r][nxt_c][k+1];
			}	
		}
		for(int c = 0; c < m; c++){
			for(int nxt_r : cols[c]){
				cols_l[c] += DP[nxt_r][c][k+1];
			}	
		}


		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				DP[i][j][k] = (rows_l[i] - DP[i][j][k+1]) + (cols_l[j] - DP[i][j][k+1]);
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j]){
				ans += DP[i][j][1];
			}
		}
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
    return 0;
}