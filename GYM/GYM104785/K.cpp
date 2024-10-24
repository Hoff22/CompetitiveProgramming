#include <bits/stdc++.h>

#define se second
#define fi first
#define N 100000

using namespace std;

typedef long long ll;

map<int, int> g[N+1]; 

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


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<pair<int,int>> dep;

	for(int i = 1; i <= n; i++) make_set(i);

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u][v]++;
		dep.push_back({u,v});
	}

	vector<tuple<int,int,int>> e;

	for(int u = 1; u <= n; u++){
		for(auto [v, q] : g[u]){
			e.push_back({q, u, v});
		}
	}

	sort(e.begin(), e.end());
	reverse(e.begin(), e.end());

	for(auto [w, u, v] : e){
		if(find_set(u) == find_set(v)){
			g[u][v] = 0;
			continue;
		}
		union_set(u,v);
	}

	vector<int> ans;

	for(int i = 0; i < dep.size(); i++){
		int u = dep[i].fi;
		int v = dep[i].se;
		if(g[u][v] == 0) continue;
		ans.push_back(i+1);
	}

	if(ans.size() >= m/2){
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for(int i : ans) cout << i << " ";
		cout << endl;
	}
	else{
		cout << "NO" << endl;
	}
}