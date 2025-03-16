#include <bits/stdc++.h>

#define N 5000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int a[N+1];
int m[N+1][N+1];
int DP[N+1][N+1];

int dp(int l, int r, int f){
	if(l == r) return DP[l][r] = 0;

	if(DP[l][r] != -1) return DP[l][r];

	int res = r-l;
	if(f){
		res = min(DP[i][j], res);
		if(a[l] <= m[l+1][r]){
			res = min(res, dp(l+1,r));
		}
	}
	else{
		if(a[r] >= m[l][r-1]){
			res = min(res, dp(l, r-1));
		}
	}

	dp(l, r-1);
	dp(l+1, r);

	return DP[l][r] = res;
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 0; i <= n; i++){
		for(int j = i; j <= n; j++){
			DP[i][j] = -1;
			m[i][j] = -INF;
		}
	}
	for(int i = 1; i <= n; i++){
		m[i][i] = a[i];
		for(int j = i+1; j <= n; j++){
			m[i][j] = max(m[i][j-1], a[j]);
		}
	}

	dp(1, n, 0);

	for(int i = 1; i <= n; i++){
		m[i][i] = a[i];
		for(int j = i+1; j <= n; j++){
			m[i][j] = min(m[i][j-1], a[j]);
		}
	}

	dp(1, n, 1);

	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			ans += DP[i][j];
		}
	}

	cout << ans << endl;
}

/*

1 2 3 4 5 6
6-1 = 5

3-1 = 2
6-4 = 2



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