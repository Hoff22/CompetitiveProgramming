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


/* O(1) - Retrieves the index of the Most Significant Bit. */
constexpr int msb_index(int mask) {
    return 8 * sizeof(mask) - __builtin_clz(mask) - 1;
}

/* O(1) - Retrieves ceil(log2(n)). */
constexpr int ceil_log2(int n) {
    assert(n > 0);
    return n == 1 ? 0 : msb_index(n - 1) + 1;
}

constexpr int L = ceil_log2(N);

// The segment tree uses exactly 2 * N - 1 nodes, but we need at least 2^(ceil(log(N)) + 1) - 1 when we index the tree using
// 2 * cur and 2 * cur + 1. This value can be further simplified by a more relaxed upperbound of  4 * N - 5 nodes.
pair<long long,long long> lazy[1 << (L + 1)];
pair<long long,long long> seg[1 << (L + 1)];

/* O(1) - Updates the current node with lazy and flushes down the lazyness. */
void lazy_update(int cur, int l, int r) {
    seg[cur].fi += (r - l + 1) * lazy[cur].fi; // Updating cur.
    seg[cur].se = max(lazy[cur].se, seg[cur].se); // Updating cur.

    // If not leaf node.
    if (l < r) {
        // Marking children as lazy.
        lazy[LEFT(cur)] = {lazy[LEFT(cur)].fi + lazy[cur].fi, max(lazy[LEFT(cur)].se , lazy[cur].se)};
        lazy[RIGHT(cur)] = {lazy[RIGHT(cur)].fi + lazy[cur].fi, max(lazy[RIGHT(cur)].se , lazy[cur].se)};
    }

    // Marking current node as not lazy.
    lazy[cur] = {0, 0};
}

/* O(1) - Merges the children's values. */
pair<long long,long long> merge(pair<long long,long long> nl, pair<long long,long long> nr) {
    return {nl.fi + nr.fi, max(nl.se,nr.se)};
}

/* O(N) - Builds a Segment Tree "seg" out of the array "a". */
void build(int cur, int l, int r) {
    int m = (l + r) / 2;

    // Leaf node.
    if (l == r) {
        seg[cur] = {0,1};
        return;
    }

    // Going down both ways.
    build(LEFT(cur), l, m);
    build(RIGHT(cur), m + 1, r);

    // Merging children's results.
    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

/* O(Log(N)) - Updates the range [i..j]. */
void update(int cur, int l, int r, int i, int j, pair<long long,long long> x) {
    int m = (l + r) / 2;

    // Updates current node with lazy if it needs an update.
    if (lazy[cur] != make_pair(0ll,0ll)) {
        lazy_update(cur, l, r);
    }

    // [l..r] is outside update range [i..j].
    if (l > j or r < i) {
        return;
    }

    // [l..r] is fully inside the update range [i..j].
    if (l >= i and r <= j) {
        // Updating with x.
        lazy[cur] = x;
        lazy_update(cur, l, r);
        return;
    }

    // Going down both ways.
    update(LEFT(cur), l, m, i, j, x);
    update(RIGHT(cur), m + 1, r, i, j, x);

    // Merging children's results.
    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

/* O(Log(N)) - Returns the content of the range [i, j] of the Segment Tree. */
pair<long long,long long> query(int cur, int l, int r, int i, int j) {
    int m = (l + r) / 2;
    pair<long long,long long> nl, nr;

    // Updates current node with lazy if it needs an update.
    if (lazy[cur] != make_pair(0ll,0ll)) {
        lazy_update(cur, l, r);
    }

    // [l..r] is outside query range [i..j].
    if (l > j or r < i) {
        // Returning a value that will not affect the result.
        return make_pair(0ll,0ll);
    }

    // [l..r] is fully inside the query range [i..j].
    if (l >= i and r <= j) {
        return seg[cur];
    }

    // Going down both ways.
    nl = query(LEFT(cur), l, m, i, j);
    nr = query(RIGHT(cur), m + 1, r, i, j);

    // Merging children's results.
    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);

    // Merging the query results.
    return merge(nl, nr);
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
    cin >> n;

    vector<tuple<int,int,int>> a;

    for(int i = 1; i <= n; i++){
    	int l,r;
    	cin >> l >> r;
    	a.push_back({l,r,i});
    }

    sort(a.begin(), a.end());

    build(1,1,n);

    vector<int> ans(n+1, -1);

    int cur = 1;
    for(int i = 0; i < n; i++){
    	int l, r, idx;
    	tie(l,r,idx) = a[i];

    	while(cur < l) cur++;

    	update(1, 1, n, l, r, {1,idx});
    	while(query(1, 1, n, cur, cur).fi == cur){
    		ans[cur] = query(1, 1, n, cur, cur).se;
    		cur++;
    	}
    }

    for(int i = 1; i <= n; i++){
    	printf("%d ", ans[i]);
    }
    printf("\n");


    return 0;

}

/*

          cur:
1 2, 2    1
1 4, 5    2
3 3, 1
3 4, 4
3 6, 3
4 6, 6




*/