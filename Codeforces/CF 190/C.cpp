#include <bits/stdc++.h>

#define N 200000
#define MAX 200000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

int n;
vector<int> g[N+1];
int f[N+1];
int sz[N+1];
char r[N+1];

void w(int u, int p = 0){
	sz[u] = 1;
	for(int v : g[u]){
		if(v == p) continue;
		w(v,u);
		sz[u] += sz[v];
	}
}

void dfs(int u, char c){
	int mx = 0;
	for(int v : g[u]){
		if(f[v]) continue;
		if(sz[mx] < sz[v]) mx = v;
	}

	if(sz[mx] <= sz[u]/2){
		// centroid
		r[u] = c;
		// disconect
		f[u] = 1;
		
		for(int v : g[u]){
			if(f[v]) continue;
			if(c+1 > 'Z'){
				cout << "Impossible!" << endl;
				exit(0);
			}
			dfs(v, c+1);
		}
		return;
	}

	sz[u] = sz[u] - sz[mx];
	sz[mx] = sz[mx] + sz[u];

	dfs(mx, c);
}

void solve(){
	cin >> n;

	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	w(1);
	dfs(1, 'A');

	for(int i = 1; i <= n; i++){
		cout << r[i] << " ";
	}
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