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
vector<int> ans;
int seen[N+1]; 
int dist[N+1];
int deg[N+1];
int p[N+1];

void dfs(int u){
	seen[u] = 1;
	for(int v : g[u]){
		if(seen[v]) continue;
		dfs(v);
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        deg[v]++;
    }
 
 	dfs(1);
 	for(int i = 1; i <= n; i++){
 		if(!seen[i]){
 			for(int v : g[i]){
 				deg[v]--;
 			}
 		}
 	}

 	memset(seen, 0, sizeof(seen));

 	queue<int> q;
 	q.push(1);
 	dist[1] = 1;
 	while(q.size()){
 		int u = q.front();
 		q.pop();

 		if(seen[u]) continue;
 		seen[u] = 1;

 		for(int v : g[u]){
 			if(seen[v]) continue;
 			deg[v]--;
 			if(dist[u] >= dist[v]){
 				p[v] = u;
 				dist[v] = dist[u] + 1;
 			}
 			if(deg[v] == 0){
 				q.push(v);
 			}
 		}
 	}

 	if(p[n] == 0){
 		cout << "IMPOSSIBLE" << endl;
 	}
 	else{
 		cout << dist[n] << endl;
 		for(int cur = n; cur != 0; cur = p[cur]) ans.push_back(cur);
 		reverse(ans.begin(), ans.end());
 		for(int i : ans) cout << i << " ";
 		cout << endl;
 	}
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