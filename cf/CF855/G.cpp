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

int n;
int c[N+1];
int md[N+1];
int cnt[N+1];
vector<int> g[N+1];
map<vector<int>, int> val;

void root_tree(int u, int p){
	vector<int> ngu;
	for(int v : g[u]){
		if(v == p) continue;
		root_tree(v,u);
		ngu.push_back(v);
	}
	g[u] = ngu;
}

int dfs(int u){
	vector<int> w;

	for(int v : g[u]){
		w.push_back(dfs(v));
	}

	for(int i = 0; i < w.size(); i++){
		cnt[w[i]]++;
		if(cnt[w[i]] % 2) c[u]++;
		else c[u]--;
	}
	
	for(int i = 0; i < w.size(); i++){
		if(cnt[w[i]] % 2) {md[u] = g[u][i];}
	}

	for(int i = 0; i < w.size(); i++){
		cnt[w[i]] = 0;
	}

	sort(w.begin(), w.end());
	
	if(!val.count(w)) val[w] = val.size();

	return val[w];
}

bool rec(int u){
	if(c[u] == 0 or u == 0) return true;
	if(c[u] > 1) return false;

	return rec(md[u]);
}

void solve(){

	val.clear();

	cin >> n;

	for(int i = 0; i <= n; i++){
		g[i].clear();
		cnt[i] = 0;
		md[i] = 0;
		c[i] = 0;
	}

	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	root_tree(1,0);

	dfs(1);

	if(rec(1)){
		cout << "YES\n";
	}
	else cout << "NO\n";

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}