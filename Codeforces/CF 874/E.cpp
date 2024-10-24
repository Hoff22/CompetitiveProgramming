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

int parent[N];
int height[N];

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
		if(height[a] == height[b]){
			height[a] += 1;
		}
		height[b] = -1;
	}
}

int seen[N+1];
vector<int> g[N+1];
set<pair<int,int>> neigh[N+1];

void dfs(int u){
	seen[u] = 1;
	for(int v : g[u]){
		union_set(u, v);
		if(seen[v]) continue;
		dfs(v);
	}
}

// bool comp(int a, int b){
// 	return neigh[a].size() < neigh[b].size();
// }

void solve(){
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		g[i].clear();
		neigh[i].clear();
		seen[i] = 0;
	}

	for(int u = 1; u <= n; u++){
		int v;
		cin >> v;

		make_set(u);

		g[u].push_back(v);

		pair<int,int> edge;

		if(u > v){
			edge = {v,u};
		}
		else{
			edge = {u,v};
		}
		neigh[v].insert(edge);
		neigh[u].insert(edge);
	}

	// vector<int> order(n);
	// for(int i = 1; i <= n; i++) order.push_back(i);
	// sort(order.begin(),order.end(), comp);

	// int mx = 0;
	// for(int i = 0; i < n; i++){
	// 	int u = order[i];
	// 	if(seen[u] == 0){
	// 		mx++;
	// 		dfs(u);
	// 	}
	// }

	for(int i = 1; i <= n; i++){
		if(seen[i] == 0){
			dfs(i);
		}
	}

	set<int> cnt;
	vector<int> one_cnt(n+1, 0);
	for(int i = 1; i <= n; i++){
		cnt.insert(find_set(i));
		if(neigh[i].size() == 1){
			one_cnt[find_set(i)]++;
		}
	}

	int mx = cnt.size();
	int mn = 0;

	for(int i = 1; i <= n; i++){
		if(one_cnt[i] >= 2) mn = 1;
	}

	for(int i = 1; i <= n; i++){
		if(height[i] != -1 and one_cnt[i] < 2) mn++;
	}

	cout << mn << " " << mx << endl;
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