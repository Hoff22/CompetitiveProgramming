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

constexpr int N = 300000;
constexpr int T = 300000;
constexpr int L = ceil_log2(N);

// The persistent segment tree uses exactly 2 * N - 1 + T * (ceil(log(N)) + 1) nodes in the worst case.
// 2 * N - 1 initial nodes + (L + 1) nodes for each one of the T updates.
int root[T + 2];
string seg[2 * N + T * (L + 2)];
int lchild[2 * N + T * (L + 2)];
int rchild[2 * N + T * (L + 2)];
string a[N + 2]; // (Input)
int last;

vector<int> g[N + 2];
vector<pair<string,string>> prop[N + 2];
int query_root[N + 2];

/* O(1) - Merges the children's values. */
string merge(string nl, string nr) {
	if(nl == "") return nr;
    return nl;
}

/* O(N) - Use root[0] = build(1, n) */
int build(int l, int r) {
    int cur, m = (l + r) / 2;

    cur = ++last;

    if (l == r) {
        seg[cur] = a[l];
        return cur;
    }

    lchild[cur] = build(l, m);
    rchild[cur] = build(m + 1, r);

    seg[cur] = merge(seg[lchild[cur]], seg[rchild[cur]]);

    return cur;
}

/* O(Log(N)) - Use root[t] = update(root[t - 1], 1, n, p, x) */
int update(int cur, int l, int r, int p, string x) {
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
string query(int cur, int l, int r, int i) {
    int m = (l + r) / 2;
    string nl, nr;

    if (l > i or r < i) {
        return "";
    }

    if (l == r) {
        return seg[cur];
    }

    nl = query(lchild[cur], l, m, i);
    nr = query(rchild[cur], m + 1, r, i);

    return merge(nl, nr);
}

map<string,int> m;

void dfs(int u, int last_root){
	query_root[u] = last_root;

	for(pair<string,string> p : prop[u]){
		query_root[u] = update(query_root[u], 1, m.size(), m[p.fi], p.se);
	}

	for(int v : g[u]){
		dfs(v, query_root[u]);
	}
}

void solve(){
	int n;
	cin >> n;


	for(int i = 1; i <= n; i++){
		int p, k;
		cin >> p >> k;
		g[p].push_back(i);

		for(int j = 0; j < k; j++){
			string s;
			cin >> s;

			string cur = "";
			string fs, sc;
			for(char c : s){
				if(c == '='){
					fs = cur;
					cur = "";
				}
				else{
					cur += c;
				}
			}
			sc = cur;

			if(m.count(fs) == 0) m[fs] = m.size()+1;
			prop[i].push_back({fs,sc});
		}
	}

	if(m.size() > 0){
		for(int i = 1; i <= m.size(); i++){
			a[i] = "";
		}

		root[0] = build(1, m.size());

		dfs(1, root[0]);
	}

	int q;
	cin >> q;

	while(q--){
		int u;
		string p;
		cin >> u >> p;

		if(!m.count(p)){
			cout << "N/A" << endl;
			continue;
		}

		string ans = query(query_root[u], 1, m.size(), m[p]);

		if(ans == ""){
			cout << "N/A" << endl;
		}
		else{
			cout << ans << endl;
		}
		cout.flush();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	solve();
   
    return 0;
}