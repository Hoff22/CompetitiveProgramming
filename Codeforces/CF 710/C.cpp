#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

string a, b;
int n, m;

int dp[50][50];

int lcstr(){
	int ans = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 or j == 0){
				dp[i][j] = 0;
			}
			else if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				ans = max(ans, dp[i][j]);
			}
			else dp[i][j] = 0; // pra lcs 0 -> dp[i-1][j-1]
		}
	}

	return ans;
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> a;
		cin >> b;

		memset(dp, 0, sizeof(dp));

		n = a.length();
		m = b.length();

		cout << n + m - 2*lcstr() << endl;
	}
    return 0;

}