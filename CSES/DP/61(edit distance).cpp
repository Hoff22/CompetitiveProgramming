#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 5000;
 
int n, m;
string a, b;
 
int DP[N+1][N+1];
 
int dp(int i, int j){
	if(i < 0) return j+1;
	if(j < 0) return i+1;
 
	if(DP[i][j] != -1) return DP[i][j];
 
	if(a[i] == b[j]){
		return DP[i][j] = dp(i-1, j-1);
	}
 
	return DP[i][j] = 1 + min({
		dp(i-1,  j),
		dp(i,  j-1),
		dp(i-1,j-1)
	});
}
 
void solve(){
 
	memset(DP, -1, sizeof(DP));
 
	cin >> a >> b;
	n = (int)a.size();
	m = (int)b.size();
	
	cout << dp(n-1, m-1) << endl;
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