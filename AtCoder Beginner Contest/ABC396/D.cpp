#include <bits/stdc++.h>

#define N 10
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll a[N+1][N+1];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) a[i][j] = a[j][i] = -1;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		ll w;
		cin >> w;
		a[u][v] = a[v][u] = w;
	}

	vector<int> per;
	for(int i = 2; i <= n; i++) per.push_back(i);

	ll ans = 0x3f3f3f3f3f3f3f3f;

	do{	
		ll cur = 0;
		int u = 1;
		for(int i = 0; i < per.size(); i++){
			if(u == n) break;
			if(a[u][per[i]] == -1) break;
			cur ^= a[u][per[i]];
			u = per[i];
		}
		if(u == n){
			ans = min(ans, cur);
		}
	}while(next_permutation(per.begin(), per.end()));

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
    return 0;
}