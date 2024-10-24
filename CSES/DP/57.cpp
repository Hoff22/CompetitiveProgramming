#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 1000;
 
int n;
int a[N+1][N+1];
int DP[N+1][N+1];
 
int dp(int i, int j){
	if(i==n or j==n) return 0;
	if(a[i][j]) return 0;
	if(i == n-1 and j == n-1) return 1;
 
	if(DP[i][j] != -1) return DP[i][j];
 
	return DP[i][j] = (dp(i+1,j) + dp(i,j+1)) % MOD;
}
 
void solve(){
 
	memset(DP, -1, sizeof(DP));
 
	cin >> n;
 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c;
			cin >> c;
			a[i][j] = (int)(c=='*');
		}
	}
 
	cout << dp(0,0) << endl;
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