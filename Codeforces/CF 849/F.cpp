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

constexpr int N = 200000;
constexpr int L = ceil_log2(N);

// The segment tree uses exactly 2 * N - 1 nodes, but we need at least 2^(ceil(log(N)) + 1) - 1 when we index the tree using
// 2 * cur and 2 * cur + 1. This value can be further simplified by a more relaxed upperbound of  4 * N - 5 nodes.
long long lazy[1 << (L + 1)];
long long seg[1 << (L + 1)];

/* O(1) - Updates the current node with lazy and flushes down the lazyness. */
void lazy_update(int cur, int l, int r) {
    seg[cur] += (r - l + 1) * lazy[cur]; // Updating cur.

    // If not leaf node.
    if (l < r) {
        // Marking children as lazy.
        lazy[LEFT(cur)] += lazy[cur];
        lazy[RIGHT(cur)] += lazy[cur];
    }

    // Marking current node as not lazy.
    lazy[cur] = 0;
}

/* O(1) - Merges the children's values. */
long long merge(long long nl, long long nr) {
    return nl + nr;
}

/* O(N) - Builds a Segment Tree "seg" out of the array "a". */
void build(int cur, int l, int r) {
    int m = (l + r) / 2;

    // Leaf node.
    if (l == r) {
        seg[cur] = 0;
        return;
    }

    // Going down both ways.
    build(LEFT(cur), l, m);
    build(RIGHT(cur), m + 1, r);

    // Merging children's results.
    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

/* O(Log(N)) - Updates the range [i..j]. */
void update(int cur, int l, int r, int i, int j, long long x) {
    int m = (l + r) / 2;

    // Updates current node with lazy if it needs an update.
    if (lazy[cur] != 0) {
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
long long query(int cur, int l, int r, int i, int j) {
    int m = (l + r) / 2;
    long long nl, nr;

    // Updates current node with lazy if it needs an update.
    if (lazy[cur] != 0) {
        lazy_update(cur, l, r);
    }

    // [l..r] is outside query range [i..j].
    if (l > j or r < i) {
        // Returning a value that will not affect the result.
        return 0;
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

int sumDig(int x){
	int sum = 0;
	while(x){
		sum += (x%10);
		x /= 10;
	}
	return sum;
}


void solve(){
	int n, q;
	scanf("%d %d", &n, &q);

	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	build(1, 1, n);

	while(q--){
		int op;
		scanf("%d", &op);

		if(op == 1){
			int l, r;
			scanf("%d %d", &l, &r);

			update(1, 1, n, l, r, 1);
		}
		else{
			int x;
			scanf("%d", &x);

			int m = query(1, 1, n, x, x);

			//printf("q: %d m: %d\n", x, m);

			int cur = a[x];
			for(int i = 0; i < m and cur > 9; i++){
				update(1, 1, n, x, x, -1);
				cur = sumDig(cur);
			}
			a[x] = cur;
			printf("%d\n", a[x]);
		}
	}
}



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}