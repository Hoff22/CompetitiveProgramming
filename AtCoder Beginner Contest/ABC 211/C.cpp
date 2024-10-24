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


long long dp[N+1][8];
string chokudai = "chokudai";
string s;

long long solve(int i, int j){
	if(i == s.size()) return (j == chokudai.size());

	if(j == chokudai.size()) return 1;

	if(dp[i][j] != -1) return dp[i][j];

	if(s[i] == chokudai[j]){
		return dp[i][j] = (solve(i+1, j) + solve(i+1, j+1)) % MOD;
	}
	return dp[i][j] = solve(i+1, j);
}

int main(){
	
	cin >> s;

	memset(dp, -1, sizeof(dp));

	printf("%lld\n", solve(0,0));

    return 0;

}