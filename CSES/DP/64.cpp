#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 5000;
 
long long a[N+1];
 
long long DP[N+1][N+1][2];
bool seen[N+1][N+1][2];
 
long long dp(int i, int j, bool p){
	if(i > j) return 0;
 
	if(seen[i][j][p]) return DP[i][j][p];
	seen[i][j][p] = 1;
 
	if(p){
		return DP[i][j][p] = max(dp(i+1,j,!p) + a[i], dp(i,j-1,!p) + a[j]);
	}
	else{
		return DP[i][j][p] = min(dp(i+1,j,!p), dp(i,j-1,!p));
	}
}
 
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
 
	cout << dp(0,n-1,1) << endl;
	
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t = 1; 
	while(t--){
		solve();
	}
 
	return 0;
