#include <bits/stdc++.h>

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

typedef long long ll;

constexpr int N = 100000;

vector<int> g[N+1]; // (input) adjacency vector for input tree (undirected)
int val[N+1]; 		// (input) tree vert value array
int n; 				// (input) number of nodes in tree
int seg[4 * N + 1];
int lazy[4 * N + 1];
int parent[N+1];
int height[N+1];
int tin[N+1];
int sz[N+1];
int h[N+1];
int a[N+1];
int t;

// O(1)
int merge(int nl, int nr) {
	if(nl == -2) return nr;
	if(nr == -2) return nl;
	if(nl == nr){
		return nl;
	}
	return -1;
}

// O(1)
void lazy_update(int cur, int l, int r){
	seg[cur] = lazy[cur]; 

	// if not leaf node
	if(l < r){
		// lazily propagating update to children
		lazy[LEFT(cur)] = lazy[cur];
		lazy[RIGHT(cur)] = lazy[cur];
	}

	lazy[cur] = 0;
}

// O(N)
void build_seg(int cur, int l, int r) {
	int m = (l + r) / 2;

	lazy[cur] = 0;

	if (l == r) {
		seg[cur] = a[l];
		return;
	}

	build_seg(LEFT(cur), l, m);
	build_seg(RIGHT(cur), m + 1, r);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

// O(log(N))
int query(int cur, int l, int r, int i, int j) {
	int nl, nr, m = (l + r) / 2;

	if(lazy[cur]){
		lazy_update(cur, l, r);
	}

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return -2;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		return seg[cur];
	}

	nl = query(LEFT(cur), l, m, i, j);
	nr = query(RIGHT(cur), m + 1, r, i, j);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);

	return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
}

// O(log(N))
void update(int cur, int l, int r, int i, int j, int x) {
	int m = (l + r) / 2;

	if(lazy[cur]){
		lazy_update(cur, l, r);
	}

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		lazy[cur] = x;
		lazy_update(cur, l, r);
		return;
	}

	update(LEFT(cur), l, m, i, j, x);
	update(RIGHT(cur), m + 1, r, i, j, x);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

/* O(N) roots tree */
void dfs(int u, int p = -1){
	parent[u] = p;
	sz[u] = 1;

	if(p != -1){
		height[u] = height[p] + 1;
	}

	int heavy = -1;
	int heavy_v = 0;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v == p) continue;
		dfs(v, u);
		if(sz[v] > heavy_v){
			heavy_v = sz[v];
			heavy = i;
		}
		sz[u] += sz[v];
	}

	if(heavy != -1) swap(g[u][heavy], g[u][0]);
}

void build_hld(int u){
	tin[u] = ++t;
	a[tin[u]] = val[u];

	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v == parent[u]) continue;
		if(i == 0) h[v] = h[u];
		else h[v] = v;
		build_hld(v);
	}
}

void build(int root = 1){
	memset(parent, 0, sizeof(parent));
	memset(tin, 0, sizeof(tin));
	memset(h, 0, sizeof(h));
	memset(a, 0, sizeof(a));

	dfs(root);

	t = 0;
	h[root] = root;
	height[root] = 0;
	build_hld(root);

	// build contiguous data structure here
	// ... 
	build_seg(1, 1, t);
}

/* O(log^2(N)) */
int query_path(int u, int v){
	if(tin[u] < tin[v]) swap(u,v);

	if(h[u] == h[v]){
		// return query for range [tin[v] ... tin[u]]
		return query(1, 1, t, tin[v], tin[u]);
	}

	// return a merge of a query for range [tin[h[u]]...tin[u]] and the path query
	// between parent[h[u]] and v
	return merge(query(1, 1, t, tin[h[u]], tin[u]), query_path(parent[h[u]], v));
}

/* O(log^2(N)) */
void update_path(int u, int v, int x){
	if(tin[u] < tin[v]) swap(u,v);

	if(h[u] == h[v]){
		// update for range [tin[v] ... tin[u]]
		update(1, 1, t, tin[v], tin[u], x);
		return;
	}

	update(1, 1, t, tin[h[u]], tin[u], x);
	update_path(parent[h[u]], v, x);
}

/* O(log(N)) returns lca for nodes u,v */
int lca(int u, int v){
	if(tin[u] < tin[v]) swap(u,v);
	if(h[u] == h[v]) return v;
	return lca(parent[h[u]], v);
}

bool comp(pair<int,int> i, pair<int,int> j){
	int lca_i = lca(i.fi, i.se);
	int lca_j = lca(j.fi, j.se);

	return (height[i.fi] + height[i.se] - 2 * height[lca_i] + 1) > (height[j.fi] + height[j.se] - 2 * height[lca_j] + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int q;
    cin >> n >> q;

    vector<pair<int,int>> qrs(q);

    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    for(int i = 0; i < q; i++){
    	cin >> qrs[i].fi >> qrs[i].se;
    }

    memset(val, 0, sizeof(val));

    build();

    sort(qrs.begin(), qrs.end(), comp);

    int good = 1;

    for(int i = 0; i < q; i++){
    	int u = qrs[i].fi;
    	int v = qrs[i].se;

    	if(query_path(u,v) == -1) good = 0;

    	update_path(u, v, i+1);
    }

    if(good) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;

}