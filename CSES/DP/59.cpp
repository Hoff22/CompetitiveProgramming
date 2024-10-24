#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 100000;
constexpr int M = 100;
 
 
int n, m;
int a[N+1];
int DP[N+1][M+1];
 
int dp(int i, int l){
	if(i == n) return 1;
 
	if(DP[i][l] != -1) return DP[i][l];
 
	if(a[i] and abs(l-a[i])>1) return DP[i][l] = 0;
	if(a[i]) return DP[i][l] = dp(i+1, a[i]);
 
	if(a[i]){
		if(abs(l-a[i]) > 1) return DP[i][l] = 0;
		return DP[i][l] = dp(i+1, a[i]);
	}
 
	int r = dp(i+1, l);
 
	if(l<m){
		r += dp(i+1, l+1);
		r %= MOD;
	}
 
	if(l>1){
		r += dp(i+1, l-1);
		r %= MOD;
	}
 
	return DP[i][l] = r;
}
 
void solve(){
 
	cin >> n >> m;
 
	memset(DP, -1, sizeof(DP));
 
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
 
	if(a[0] == 0){
		int r = 0;
		for(int i = 1; i <= m; i++){
			r += dp(1,i);
			r %= MOD;
		}
		cout << r << endl;
	}
	else{
		cout << dp(1,a[0]) << endl;
	}
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