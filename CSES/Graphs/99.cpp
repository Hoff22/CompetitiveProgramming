#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;

constexpr int N = 100000;
constexpr int M = 200000;

vector<pair<int,int>> g[N+1];
int used[M+1];
int seen[N+1];
vector<int> ans;

void con(int u){
	seen[u] = 1;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i].first;
		if(!seen[v]) con(v);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;

	vector<int> deg(n+1,0);

	for(int i = 1; i <= m; i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
		deg[u]++;
		deg[v]++;
	}

	con(1);
	
	for(int i = 1; i <= n; i++){
		if(deg[i] % 2 or (!seen[i] and deg[i])){
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}

	stack<int> st; st.push(1);

	while(st.size()){
		int u = st.top();
		if(deg[u] == 0){
			ans.push_back(u);
			st.pop();
		}
		else{
			while(used[g[u].back().second]) g[u].pop_back();
			int v = g[u].back().first;
			deg[u]--; deg[v]--;
			used[g[u].back().second] = 1;
			st.push(v);	
		}
	}

	for(int i : ans) cout << i << " ";
	cout << endl;
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