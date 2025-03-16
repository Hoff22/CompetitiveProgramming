#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define T 100000
#define L 17
#define K 300

// The persistent segment tree uses exactly 2 * N - 1 + T * (ceil(log(N)) + 1) nodes in the worst case.
// 2 * N - 1 initial nodes + (L + 1) nodes for each one of the T updates.
int root[T + 1];
long long seg[2 * N + T * (L + 1)];
int lchild[2 * N + T * (L + 1)];
int rchild[2 * N + T * (L + 1)];
int a[N + 1]; // (Input)
int last;
int n, q;

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

vector<int> comp;

long long kth(int l, int r, int k, int i = 0, int j = n){
    int m = (i+j) / 2;
    long long vl;

    if(i == j) return i;

    vl = query(root[r], 0, comp.size(), i, m) - query(root[l-1], 0, comp.size(), i, m);

    if(vl >= k){
        return kth(l, r, k, i, m);
    }
    return kth(l, r, k-vl, m+1, j);
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i], comp.push_back(a[i]);

    sort(comp.begin(), comp.end());

    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

    for(int i = 1; i <= n; i++){
        a[i] = (int)(lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin());     
    }

    memset(root, 0, sizeof(root));
    memset(seg, 0, sizeof(seg));
    memset(lchild, 0, sizeof(lchild));
    memset(rchild, 0, sizeof(rchild));
    last = 0;

    root[0] = build(0,comp.size());
    for(int i = 1; i <= n; i++){
        root[i] = update(root[i-1], 0, comp.size(), a[i], 1);
    }

    for(int i = 0; i < q; i++){
        string op;
        cin >> op;

        if(op == "Q"){
            int l, r, k;
            cin >> l >> r >> k;

            cout << comp[kth(l, r, k)] << endl;
        }
        else{
            int j;
            cin >> j;

            root[j] = update(root[j], 0, comp.size(), a[j+1],  1);
            root[j] = update(root[j], 0, comp.size(), a[j],   -1);
            root[j+1] = update(root[j+1], 0, comp.size(), a[j],    1);
            root[j+1] = update(root[j+1], 0, comp.size(), a[j+1], -1);

            swap(a[i], a[i+1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}