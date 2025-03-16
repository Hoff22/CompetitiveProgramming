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

ll val = 0;

namespace mst{
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

	// O(E * log(N)) - expects graph 1-indexed
	vector<vector<pair<int,int>>> mst(vector<vector<pair<int,int>>>& g){
		int n = g.size()-1;
		
		vector<vector<pair<int,int>>> res(n+1,vector<pair<int,int>>());

		for(int i = 1; i <= n; i++){
			make_set(i);
		}

		vector<tuple<int,int,int>> edges;
		for(int u = 1; u <= n; u++){
			// cout << "> " << u << endl;
			for(auto [v, w] : g[u]){
				edges.push_back({w,u,v});
			}
		}

		sort(edges.begin(), edges.end());

		for(auto [w,u,v] : edges){
			
			// cout << u << " " << v << " " << w << endl;

			if(find_set(v) == find_set(u)) continue;
			// cout << "  get" << endl;

			union_set(u,v);
			res[u].push_back({v,w});
			res[v].push_back({u,w});
			val += w;
		}

		return res;
	}
}

// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
// Pode usar a seguinte funcao para indexar os nohs:
// f(l, r) = (l+r)|(l!=r), usando 2N de memoria
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

namespace seg {
	ll seg[4*N+1], lazy[4*N+1];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

// HLD - aresta
//
// SegTree de soma
// query / update de soma das arestas
//
// Complexidades:
// build - O(n)
// query_path - O(log^2 (n))
// update_path - O(log^2 (n))
// query_subtree - O(log(n))
// update_subtree - O(log(n))

// namespace seg { ... }

namespace hld {
	vector<vector<pair<int, int> >> g;
	int pos[N+1], sz[N+1];
	int sobe[N+1], pai[N+1];
	int h[N+1], v[N+1], t;

	void build_hld(int k, int p = -1, int f = 1) {
		// cout << "bu hld " << k << endl;
		v[pos[k] = t++] = sobe[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i.first != p) {
			auto [u, w] = i;
			sobe[u] = w; pai[u] = k;
			h[u] = (i == g[k][0] ? h[k] : u);
			build_hld(u, k, f); sz[k] += sz[u];

			if (sz[u] > sz[g[k][0].first] or g[k][0].first == p)
				swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(vector<vector<pair<int, int> >>& g_, int root = 0) {
		g = g_;
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}
	ll query_path(int a, int b) {
		if (a == b) return 0;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b]+1, pos[a]);
		return max(seg::query(pos[h[a]], pos[a]) , query_path(pai[h[a]], b));
	}
}

void solve(){
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int,int>>> g_(n+1, vector<pair<int,int>>());
	vector<tuple<int,int,int>> edges;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g_[u].push_back({v,w});
		g_[v].push_back({u,w});
		edges.push_back({u,v,w});
	}

	vector<vector<pair<int,int>>> g = mst::mst(g_);

	// for(int u = 1; u <= n; u++){
	// 	cout << u << ": ";
	// 	for(auto [v,w] : g[u]){
	// 		cout << "(" << v << "," << w << ") ";
	// 	}
	// 	cout << endl;
	// }
	// cout << val << endl;

	// return;
	hld::build(g, 1);
	for(auto [u,v,w] : edges){
		// cout << u << " " << v << " > " << hld::query_path(u,v) << endl;
		cout << val + w - hld::query_path(u,v) << endl;
	}
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