#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 1000;
constexpr int M = 100000;
 
int c[N+1];
int v[N+1];
int DP[N+1][M+1];
 
void solve(){
 
	int n, k;
	cin >> n >> k;
 
	for(int i = 0; i < n; i++){
		cin >> c[i]; 
	}
	for(int i = 0; i < n; i++){
		cin >> v[i]; 
	}
 
	for(int j = 0; j < n; j++) DP[j][0] = 0;
	for(int i = 1; i <= k; i++){
		if(i>=c[0]) DP[0][i] = v[0];
		else DP[0][i] = 0;
	}
 
	for(int j = 1; j < n; j++){
		for(int i = 1; i <= k; i++){
			if(c[j] <= i){
				DP[j][i] = max(DP[j-1][i], DP[j-1][i-c[j]] + v[j]);
			}
			else{
				DP[j][i] = DP[j-1][i];
			}
		}
	}
 
	cout << DP[n-1][k] << endl;
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