#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define C 0
#define J 1

using namespace std;

int dp[N][2];
int cj, jc;
int n;
string s;
// x = cj
// y = jc

/*// versao recursiva ruim kk
int solve(int i, int last, int sum){
	if(i == n){
		return sum;
	}

	if(s[i] == 'C') return solve(i+1, C, sum+(last == J)*jc);
	if(s[i] == 'J') return solve(i+1, J, sum+(last == C)*cj);
	return min(solve(i+1, C, sum+(last == J)*jc), solve(i+1, J, sum+(last == C)*cj));
}
*/

void test_case(int q){
	cin >> cj >> jc >> s;

	n = (int)s.length();

	dp[0][C] = (s[0] == 'J') * INF;
	dp[0][J] = (s[0] == 'C') * INF;

	for(int i = 1; i < n; i++){
		if(s[i] == 'C'){
			dp[i][C] = min(dp[i-1][J]+jc, dp[i-1][C]);
			dp[i][J] = INF;
		}
		else if(s[i] == 'J'){
			dp[i][J] = min(dp[i-1][J], dp[i-1][C]+cj);
			dp[i][C] = INF;
		}
		else{ // s[i] == '?'
			dp[i][C] = min(dp[i-1][J]+jc, dp[i-1][C]);
			dp[i][J] = min(dp[i-1][J], dp[i-1][C]+cj);
		}
	}

	printf("Case #%d: %d\n", q, min(dp[n-1][C], dp[n-1][J]));
}

int main(){
	
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		test_case(i);
	}
    return 0;

}