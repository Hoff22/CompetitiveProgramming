#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<int> g[N+1];
uint64_t ans = 0;

void dfs(int u, uint64_t d = 0){
	int f = 0;
	for(int v : g[u]) f += (g[v].empty());

	if(f){
		int l = 0;
		int r = 28;
		int x = 0;
		while(l <= r){
			int m = (l+r)/2;
			if((1ll<<m) < f) l = m+1;
			else x=m, r=m-1;
		}
		if(f == g[u].size() and f > 1){
			ans = max(ans, d + x);
		}
		else{
			ans = max(ans, d + x + 1);
		}
		// cout << u << ": " << d+x << endl;
	}

	for(int v : g[u]){
		if(g[v].empty()) continue; 
		dfs(v,d+1);
	}
}

void solve(){
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++) g[i].clear();

	for(int i = 2; i <= n; i++){
		int p; cin >> p;
		g[p].push_back(i);
	}

	ans = 0;
	dfs(1);

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double ev = 0.0;

    for(int i = 1; i <= 20; i++){
    	for(int j = 1; j <= 20; j++){
    		ev += max(i,j) * (1.0/(20 * 20));
    	}
    }
    cout << ev << endl;

    int t;
	cin >> t;
	while(t--){
		solve();
	}
    return 0;
}