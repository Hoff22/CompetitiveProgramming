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

/* O(1) - Retrieves the index of the Most Significant Bit. */
constexpr int msb_index(int mask) {
    return 8 * sizeof(mask) - __builtin_clz(mask) - 1;
}

/* O(1) - Retrieves ceil(log2(n)). */
constexpr int ceil_log2(int n) {
    assert(n > 0);
    return n == 1 ? 0 : msb_index(n - 1) + 1;
}

constexpr int N = 100000;
constexpr int T = 100000;
constexpr int L = ceil_log2(N);

// The persistent segment tree uses exactly 2 * N - 1 + T * (ceil(log(N)) + 1) nodes in the worst case.
// 2 * N - 1 initial nodes + (L + 1) nodes for each one of the T updates.
int root[T + 1];
long long seg[2 * N + T * (L + 1)];
int lchild[2 * N + T * (L + 1)];
int rchild[2 * N + T * (L + 1)];
int comp[N + 1]; // (Input)
int last;

/* O(1) - Merges the children's values. */
long long merge(long long nl, long long nr) {
    return max(nl,nr);
}

/* O(N) - Use root[0] = build(1, n) */
int build(int l, int r) {
    int cur, m = (l + r) / 2;

    cur = ++last;

    if (l == r) {
        seg[cur] = 0;
        return cur;
    }

    lchild[cur] = build(l, m);
    rchild[cur] = build(m + 1, r);

    seg[cur] = merge(seg[lchild[cur]], seg[rchild[cur]]);

    return cur;
}

/* O(Log(N)) - Use root[t] = update(root[t - 1], 1, n, p, x) */
int update(int cur, int l, int r, int p, long long x) {
    int ncur, m = (l + r) / 2;

    if (l > p or r < p) {
        return cur;
    }

    ncur = ++last;

    if (l == r) {
        // Creating new leaf node.
        seg[ncur] = x;
        return ncur;
    }

    // Creating new internal node and linking with children.
    lchild[ncur] = update(lchild[cur], l, m, p, x);
    rchild[ncur] = update(rchild[cur], m + 1, r, p, x);

    // Calculating new internal node.
    seg[ncur] = merge(seg[lchild[ncur]], seg[rchild[ncur]]);

    return ncur;
}

/* O(Log(N)) - Use query(root[k], 1, n, i, j) to query after the k'th update */
long long query(int cur, int l, int r, int i, int j) {
    int m = (l + r) / 2;
    long long nl, nr;

    if (l > j or r < i) {
        return 0;
    }

    if (l >= i and r <= j) {
        return seg[cur];
    }

    nl = query(lchild[cur], l, m, i, j);
    nr = query(rchild[cur], m + 1, r, i, j);

    return merge(nl, nr);
}

long long mx = 0;
vector<int> g[N+1];
long long ans[N+1];

void dfs(int u, long long r, long long best){
	long long cur, nxtr;

	if(comp[u] == 1) cur = 1;
	else{
		cur = 1 + query(r, 1, mx, 1, comp[u]-1);
	}

	nxtr = update(r, 1, mx, comp[u], cur);

	ans[u] = max(cur, best);

	for(int v : g[u]){
		dfs(v, nxtr, ans[u]);
	}
}

void solve(){
	int n;
	cin >> n;

	for(int i = 2; i <= n; i++){
		int u; cin >> u;
		g[u].push_back(i);
	}

	vector<int> aux(n);
	vector<int> a(n+1);

	for(int i = 0; i < n; i++){
		cin >> aux[i];
		a[i+1] = aux[i];
	}

	if(n == 1) return;

	sort(aux.begin(), aux.end());
	aux.resize(unique(aux.begin(), aux.end())-aux.begin());

	map<int,int> m;
	for(int i = 0; i < aux.size(); i++){
		m[aux[i]] = i+1;
	}

	for(int i = 1; i <= n; i++){
		comp[i] = m[a[i]];
	}

	mx = aux.size();

	dfs(1, build(1,mx), 0);

	for(int i = 2; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    solve();

    return 0;

}