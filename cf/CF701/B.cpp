#include <bits/stdc++.h>

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

constexpr int N = 1000000;
constexpr int T = 200000;
constexpr int L = ceil_log2(N);

// The persistent segment tree uses exactly 2 * N - 1 + T * (ceil(log(N)) + 1) nodes in the worst case.
// 2 * N - 1 initial nodes + (L + 1) nodes for each one of the T updates.
int root[T + 1];
long long seg[2 * N + T * (L + 1)];
int lchild[2 * N + T * (L + 1)];
int rchild[2 * N + T * (L + 1)];
int last;

/* O(1) - Merges the children's values. */
long long merge(long long nl, long long nr) {
    return nl + nr;
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
        seg[ncur] = seg[cur] + x;
        return ncur;
    }

    // Creating new internal node and linking with children.
    lchild[ncur] = update(lchild[cur], l, m, p, x);
    rchild[ncur] = update(rchild[cur], m + 1, r, p, x);

    // Calculating new internal node.
    long long lv, rv;

    if(l == m) lv = seg[lchild[ncur]] * seg[lchild[ncur]] * l;
    else lv = seg[lchild[ncur]];
    if(m+1 == r) rv = seg[rchild[ncur]] * seg[rchild[ncur]] * r;
    else rv = seg[rchild[ncur]];

    seg[ncur] = merge(lv, rv);

    return ncur;
}

/* O(Log(N)) - Use query(root[k], 1, n, i, j) to query after the k'th update */
long long query(int cur, int l = 1, int r = 1000000, int i = 1, int j = 1000000) {
    int m = (l + r) / 2;
    long long nl, nr;

    if (l > j or r < i) {
        return 0;
    }

    if (l >= i and r <= j) {
        return seg[cur];
    }

    if(l == m) nl = query(lchild[cur], l, m, i, j) * query(lchild[cur], l, m, i, j) * l;
    else nl = query(lchild[cur], l, m, i, j);
    if(m+1 == r) nr = query(rchild[cur], m + 1, r, i, j) * query(rchild[cur], m + 1, r, i, j) * r;
    else nr = query(rchild[cur], m + 1, r, i, j);

    return merge(nl, nr);
}

void pr(int rot){
    for(int i = 1; i <= 3; i++){
        int l = 1;
        int r = 1000000;
        int cur = rot;
        while(l < r){
            int m = l + (r - l) / 2;
            if(i <= m){
                r = m;
                cur = lchild[cur];
            }
            else{
                l = m+1;
                cur = rchild[cur];
            }
        }

        cout << seg[cur] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    root[0] = build(1, 1000000);

    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    vector<tuple<int,int,int>> qs;
    for(int i = 0; i < t; i++){
        int l, r;
        cin >> l >> r;  
        qs.push_back({r,l,i});
    }

    vector<long long> ans(t);

    sort(qs.begin(), qs.end());
    reverse(qs.begin(), qs.end());

    for(int i = 1; i <= n; i++){
        root[i] = update(root[i-1], 1, 1000000, v[i], 1);
        pr(root[i]);
        while(qs.size() and get<0>(qs.back()) == i){
            int l, r, qi;
            tie(r,l,qi) = qs.back();
            qs.pop_back();
            cout << " " << i << ": " << query(root[i]) << endl;
            ans[qi] = query(root[i]) - query(root[l-1]);
        }
    }

    for(long long res : ans){
        cout << res << endl;
    }

    return 0;
}