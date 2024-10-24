#include <bits/stdc++.h>

#define N 500
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

string a;
string b;

int dp[N+1][2*N+1][2][3];

int go(int i, int j, bool sw, int dir){
	//printf("%d %d\n", i, j);
	if(j == b.size()){
		return 1;
	}
	if(i == a.size() or i == -1) return 0;
	if(a[i] != b[j]) return 0;

	if(dp[i][j][sw][(dir+1)] != -1) return dp[i][j][sw][(dir+1)];

	if(sw == 0){
		return dp[i][j][sw][(dir+1)] = go(i+dir, j+1, 0, dir) or go(i-dir, j+1, 1, -dir);
	}
	return dp[i][j][sw][(dir+1)] = go(i+dir, j+1, 1, dir);
}

void solve(){

	cin >> a >> b;

	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < a.size(); i++){
		if(a[i] == b[0]){
			if(go(i+1, 1, 0, 1)){
				printf("YES\n");
				return;
			}
			if(go(i-1, 1, 1, -1)){
				printf("YES\n");
				return;
			}
		}
	}

	printf("NO\n");

}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}