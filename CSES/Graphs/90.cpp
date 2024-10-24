#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 100000;
constexpr int M = 200000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;
 
int n, m;
vector<int> g[N+1];
long long DP[N+1];

long long dp(int u){
	if(u == n) return 1;

	if(DP[u] != -1) return DP[u];

	long long ans = 0;

	for(int v : g[u]){
		ans += dp(v);
		ans %= MOD;
	}

	return DP[u] = ans % MOD;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
 	memset(DP, -1, sizeof(DP));
 	cout << dp(1) << endl;
}
 
int main(){
 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t = 1;
 
	while(t--){
		solve();
	}
 
	return 0;
}