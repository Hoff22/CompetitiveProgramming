#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int a[N + 1]; // (input) an array of data to operate querys and updates over

long long DP[N+1][3][4];
long long seen[N+1][3][4];

int n;
long long dp(int i, int state, int k){
	if(i > n){
		if(state != 2){
			return -INF;
		}
		return 0;
	}

	if(seen[i][state][k]) return DP[i][state][k];
	seen[i][state][k] = 1;

	if(state == 0){
		return DP[i][state][k] = max({dp(i+1, state, k), dp(i+1, 1, k)-1, dp(i+1, 1, k-1) + a[i]-1});
	}
	else if(state == 1){
		if(k == 1){
			return DP[i][state][k] = max(dp(i+1, state, k)-1, dp(i+1, 2, 0) + a[i] - 1);
		}
		else{
			return DP[i][state][k] = max(dp(i+1, state, k)-1, dp(i+1, state, k-1) + a[i] - 1);
		}
	}
	else{
		return DP[i][state][k] = dp(i+1, state, k);
	}
}

void solve(){
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 4; k++){
				seen[i][j][k] = 0;
			}
		} 
	}
	cout << dp(1,0,3)+1 << endl;
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