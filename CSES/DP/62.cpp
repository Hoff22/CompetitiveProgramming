#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 500;
 
int n, m;
 
int DP[N+1][N+1];
 
int dp(int a, int b){
	if(a == b) return 0;
 
	if(DP[a][b] != -1) return DP[a][b];
 
	int r = INF;
 
	for(int i = 1; i < a; i++){
		r = min(r, dp(i,b) + dp(a-i,b) + 1);
	}
	for(int i = 1; i < b; i++){
		r = min(r, dp(a,i) + dp(a,b-i) + 1);
	}
 
	return DP[a][b] = r;
}
/*
.
  ..
. ..
 
 
*/
 
void solve(){
	memset(DP, -1, sizeof(DP));
 
	cin >> n >> m;
	
	cout << dp(n, m) << endl;
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