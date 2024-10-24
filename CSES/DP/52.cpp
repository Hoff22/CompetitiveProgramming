#include <bits/stdc++.h>
 
#define N 500
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first
 
using namespace std;
 
typedef long long ll;
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    vector<int> dp(n+1, 0);
 
    dp[0] = 1;
 
    for(int i = 1; i <= n; i++){
    	for(int k = 1; k <= 6 and i-k >= 0; k++){
    		dp[i] += dp[i-k];
    		dp[i] %= MOD;
    	}
    }
 
    cout << dp[n] << endl;
 
	return 0;
}