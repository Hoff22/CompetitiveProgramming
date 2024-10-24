#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 100;
constexpr int M = 100000;
 
 
void solve(){
	int n;
	cin >> n;
 
	vector<int> c(n+1);
	vector<int> dp(M+1, n+1);
 
	for(int i = 1; i <= n; i++) cin >> c[i];
 
	sort(c.begin()+1, c.end());
 
	dp[0] = 0;
 
	for(int i = 0; i <= M; i++){
		for(int j = dp[i]+1; j <= n; j++){
			dp[i+c[j]] = min(dp[i+c[j]], j);
		}
	}
 
	set<int> s;
	for(int i = 1; i <= M; i++){
		if(dp[i] != n+1) s.insert(i);
	}
 
	cout << s.size() << endl;
	for(int i : s) cout << i << " ";
	cout << endl;
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