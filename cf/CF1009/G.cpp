#include <bits/stdc++.h>

#define N 400
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll a[N+1];
ll DP[N+1][N+1][4];

ll dp(int l, int r, int can){
	#define bL(can) (can & 2)
	#define bR(can) (can & 1)

	if(r-l == 1) return 0;

	if(DP[l][r][can] != -1) return DP[l][r][can];
 
	ll res = -0x3f3f3f3f3f3f3f3f;

	// not take the current one
	for(int i = l+1; i < r; i++){
		res = max(res, dp(l,i, bL(can) | 1) + dp(i,r, 0 | bR(can)) );
		res = max(res, dp(l,i, bL(can) | 0) + dp(i,r, 2 | bR(can)) );
	}

	if(bL(can) and bR(can)){
		// take the current one
		for(int i = l+1; i < r; i++){
			res = max(res, dp(l,i,0) + dp(i,r,0) + (a[l] * a[r] * a[i]));
		}
	}

	return DP[l][r][can] = res;
}

// void rec(int l, int r, int can){
// 	#define bL(can) (can & 2)
// 	#define bR(can) (can & 1)

// 	if(r-l == 1) return;

// 	int used = -1;
// 	int take = 0;
// 	int nx_can_l = 0;
// 	int nx_can_r = 0;

// 	ll res = -0x3f3f3f3f3f3f3f3f;

// 	// not take the current one
// 	for(int i = l+1; i < r; i++){
// 		if(res < dp(l,i, bL(can) | 1) + dp(i,r, 0 | bR(can))){
// 			res = dp(l,i, bL(can) | 1) + dp(i,r, 0 | bR(can));
// 			used = i;
// 			take = 0;
// 			nx_can_l = bL(can) | 1;
// 			nx_can_r = 0 | bR(can);
// 		}

// 		if(res < dp(l,i, bL(can) | 0) + dp(i,r, 2 | bR(can))){
// 			res = dp(l,i, bL(can) | 0) + dp(i,r, 2 | bR(can));
// 			used = i;
// 			take = 0;
// 			nx_can_l = bL(can) | 0;
// 			nx_can_r = 2 | bR(can);
// 		}
// 	}

// 	if(bL(can) and bR(can)){
// 		// take the current one
// 		for(int i = l+1; i < r; i++){
// 			if(res < dp(l,i,0) + dp(i,r,0) + (a[l] * a[r] * a[i])){
// 				res = dp(l,i,0) + dp(i,r,0) + (a[l] * a[r] * a[i]);
// 				used = i;
// 				take = 1;
// 				nx_can_l = 0;
// 				nx_can_r = 0;
// 			}
// 		}
// 	}

// 	cout << l << " " << r << " " << used << " : " << (take ? "take" : ".") << endl;

// 	rec(l, used, nx_can_l);
// 	rec(used, r, nx_can_r);
// }

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			for(int c = 0; c < 4; c++) DP[i][j][c] = -1;
	
	// rec(0,n-1,3);
	cout << dp(0,n-1,3) << endl;
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