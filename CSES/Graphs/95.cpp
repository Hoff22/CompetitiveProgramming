#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 100000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;

vector<int> g[N+1];
int seen[N+1];

int parent[N+1];
int height[N+1];

// make_set(a) creates a new set/tree with only the node a
void make_set(int a){
	parent[a] = a;
	height[a] = 0;
}

// find(a) returns the answer to which set the element a belongs to
int find_set(int a){
	if(parent[a] == a){
		return a;
	}
	return parent[a] = find_set(parent[a]);
}

// union(a, b) merges two sets into one
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	
	if(a != b){
		if(height[b] > height[a]) swap(a, b); // bigger's always a;
		parent[b] = a;
		if(height[a] == height[b]) height[a] += 1;
	}
}

void dfs(int u){
	seen[u] = 1;
	for(int v : g[u]){
		if(!seen[v]) dfs(v);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;

	vector<tuple<ll,int,int>> edges;

	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w,u,v});
	}

	for(int i = 1; i <= n; i++) make_set(i);

	sort(edges.begin(), edges.end());

	ll ans = 0;

	for(auto [w, u, v] : edges){
		if(find_set(u) == find_set(v)) continue;

		g[u].push_back(v);
		g[v].push_back(u);

		union_set(u,v);

		ans += w;
	}

	dfs(1);
	for(int i = 1; i <= n; i++){
		if(!seen[i]){
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}

	cout << ans << endl;
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