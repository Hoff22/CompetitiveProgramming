#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 1000000;
 
int DP[8][N+1];
vector<int> g[8] = {
	{0, 5},         // 0         
	{},             // 1
	{7,6,3,2},      // 2
	{7,6,3,2},		// 3
	{},             // 4
	{7,6,3,2,0,5},  // 5
	{7,6,3,2},      // 6
	{7,6,3,2,0,5},  // 7
};
 
/*
   000
	   -> 000, 101,
   001
	 _ -> nao existe
   010
	|  -> 111, 110, 011, 010,
   011
	|_ -> 111, 110, 011, 010,
   100
   _   -> nao existe
   101
   _ _ -> 111, 110, 011, 010, 000, 101, 
   110
   _|  -> 111, 110, 011, 010,
   111
   _|_ -> 111, 110, 011, 010, 000, 101,
 
 
010
011
110
 
111
101
 
000
*/
 
 
 
// int dp(int n, int s){
// 	if(n == 0){
// 		return ((s&5) == 5);
// 	}
 
// 	if(DP[s][n] != -1) return DP[s][n];
 
// 	int res = 0;
 
// 	for(int s_ : g[s]){
// 		res += dp(n-1, s_);
// 		res %= MOD;
// 	}
 
// 	return DP[s][n] = res;
// }
 
void solve(){
	int n; cin >> n;
 
	cout << DP[7][n] << endl;	
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n = 1000000;
 
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 7; j++){
			DP[j][i] = 0;
		}
	}
 
	for(int s = 0; s <= 7; s++){
		DP[s][0] = ((s&5) == 5);	
	}
 
	for(int i = 1; i <= n; i++){
		for(int s = 0; s <= 7; s++){
			for(int s_ : g[s]){
				DP[s][i] += DP[s_][i-1];
				DP[s][i] %= MOD;
			}
		}
	}
 
	int t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}