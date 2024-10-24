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
int sz[N+1];

// make_set(a) creates a new set/tree with only the node a
void make_set(int a){
	parent[a] = a;
	sz[a] = 1;
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
		if(sz[b] > sz[a]) swap(a, b); // bigger's always a;
		parent[b] = a;
		sz[a] += sz[b];
	}
}

void solve(){
	int n, m;
	cin >> n >> m;

	multiset<int> s;

	for(int i = 1; i <= n; i++) make_set(i), s.insert(sz[find_set(i)]);

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		
		if(find_set(u) != find_set(v)){
			s.erase(s.lower_bound(sz[find_set(u)]));
			s.erase(s.lower_bound(sz[find_set(v)]));

			union_set(u,v);

			s.insert(sz[find_set(u)]);
		}

		cout << s.size() << " " << *s.rbegin() << "\n";
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