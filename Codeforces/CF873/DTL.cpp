#include <bits/stdc++.h>
#include <bit>

#define N 5000
#define K 15
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

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

vector<int> a;

int st_mx[K + 1][N+1];
int st_mn[K + 1][N+1];

int min_q(int l, int r){
	int i = log2_floor(r - l + 1);
	return min(st_mn[i][l], st_mn[i][r - (1 << i) + 1]);
}
int max_q(int l, int r){
	int i = log2_floor(r - l + 1);
	return min(st_mx[i][l], st_mx[i][r - (1 << i) + 1]);
}

int DP[N+1][N+1];

int dp(int l, int r){
	if(l == r) return DP[l][r] = 0;

	if(DP[l][r] != -1) return DP[l][r];

	int res = r-l;
	for(int i = l; i < r; i++){
		if(-max_q(l,i) <= min_q(i+1,r)){
			res = min(res, dp(l,i) + dp(i+1, r));
		}
	}
	//cout << l << " " << r << ": " << res << endl;
	return DP[l][r] = res;
}

void solve(){
	int n;
	cin >> n;
	a.assign(n+1,0);
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 0; i <= n; i++){
		for(int j = i; j <= n; j++){
			DP[i][j] = -1;
		}
	}

	std::copy(a.begin(), a.end(), st_mn[0]);

	for (int i = 1; i <= K; i++){
	    for (int j = 0; j + (1 << i) <= n+1; j++){
	        st_mn[i][j] = min(st_mn[i - 1][j], st_mn[i - 1][j + (1 << (i - 1))]);
	    }
	}

	for(int i = 0; i <= n; i++){
		st_mx[0][i] = -a[i];
	}

	for (int i = 1; i <= K; i++){
	    for (int j = 0; j + (1 << i) <= n+1; j++){
	        st_mx[i][j] = min(st_mx[i - 1][j], st_mx[i - 1][j + (1 << (i - 1))]);
	    }
	}

	// for(int i = 1; i <= n; i++){
	// 	for(int j = i; j <= n; j++){
	// 		cout << i << " " << j << ": " << max_q(i,j) << endl;
	// 	}
	// }

	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			ans += dp(i,j);
			cout << i << " " << j << ": " << dp(i,j) << endl;
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