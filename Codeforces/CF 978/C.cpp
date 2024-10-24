#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

int n;
char a[2][N+1];
long long DP[N+1][4][4][2];

long long dp(int i, int s0, int s1, int same){
	if(i == n){
		if(s0 != 3 or s1 != 3) return -INF;
		return 0;
	}

	if(DP[i][s0][s1][same] != -1) return DP[i][s0][s1][same];

	if(s0 == 3 and s1 == 3){
		return DP[i][s0][s1][same] = max(
			dp(i+1, 2, 2, 1), // open same
			dp(i+1, 1, 1, 0)  // open dif
		);
	}

	if(same){ // and s0 == 2 and s1 == 2
		return DP[i][s0][s1][same] = max(
			dp(i+1, 3, 1, 0) + ((a[0][i-1] + a[1][i-1] + a[0][i]) > 1), // close on top
			dp(i+1, 1, 3, 0) + ((a[0][i-1] + a[1][i-1] + a[1][i]) > 1)  // close on bot
		);
	}

	if(s0 == 2 and s1 == 2){
		return DP[i][s0][s1][same] = dp(i+1, 3, 3, 0) + ((a[0][i-1] + a[0][i-2] + a[0][i]) > 1) + ((a[1][i-1] + a[1][i-2] + a[1][i]) > 1);
	}
	if(s0 == 2 and s1 == 3){
		return DP[i][s0][s1][same] = dp(i+1, 3, 1, 0) + ((a[0][i-1] + a[0][i-2] + a[0][i]) > 1);
	}
	if(s0 == 3 and s1 == 2){
		return DP[i][s0][s1][same] = dp(i+1, 1, 3, 0) + ((a[1][i-1] + a[1][i-2] + a[1][i]) > 1);
	}
	if(s0 == 1 and s1 == 3){
		return DP[i][s0][s1][same] = max(
			dp(i+1, 3, 3, 1) + ((a[0][i-1] + a[0][i] + a[1][i]) > 1),   // close on top
			dp(i+1, 2, 1, 0)
		);
	}
	if(s0 == 3 and s1 == 1){
		return DP[i][s0][s1][same] = max(
			dp(i+1, 3, 3, 1) + ((a[1][i-1] + a[1][i] + a[0][i]) > 1),   // close on bot
			dp(i+1, 1, 2, 0)
		);
	}
	if(s0 == 2 and s1 == 1){
		return dp(i+1, 3, 2, 0) + ((a[0][i-1] + a[0][i-2] + a[0][i]) > 1);
	}
	if(s0 == 1 and s1 == 2){
		return dp(i+1, 2, 3, 0) + ((a[1][i-1] + a[1][i-2] + a[1][i]) > 1);
	}

	return DP[i][s0][s1][same] = dp(i+1, s0+1, s1+1, 0);
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		char c; cin >> c;
		a[0][i] = (c == 'A');
	}
	for(int i = 0; i < n; i++){
		char c; cin >> c;
		a[1][i] = (c == 'A');
	}

	for(int i = 0; i < n; i++){
		for(int k = 0; k < 4; k++){
			DP[i][k][0][0] = DP[i][k][1][0] = DP[i][k][2][0] = DP[i][k][3][0] = -1;
			DP[i][k][0][1] = DP[i][k][1][1] = DP[i][k][2][1] = DP[i][k][3][1] = -1;
		}
	}

	cout << dp(0, 3, 3, 0) << endl;
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