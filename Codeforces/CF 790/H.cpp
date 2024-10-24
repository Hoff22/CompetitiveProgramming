#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

#define N 200000
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

int seg[4 * N + 1];
int a[N + 1]; // (input) an array of data to operate querys and updates over

int merge(int nl, int nr) {
	return nl + nr; // (input) this operation must be reversable and conform to problem
}

void build(long long cur, int l, int r) {
	int m = (l + r) / 2;

	//printf("%d")

	if (l == r) {
		seg[cur] = a[l];
		return;
	}

	build(LEFT(cur), l, m);
	build(RIGHT(cur), m + 1, r);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

int query(long long cur, int l, int r, int i, int j) {
	int nl, nr, m = (l + r) / 2;

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return 0;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		return seg[cur];
	}

	nl = query(LEFT(cur), l, m, i, j);
	nr = query(RIGHT(cur), m + 1, r, i, j);

	return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
}

void update(long long cur, int l, int r, int i) {
	int m = (l + r) / 2;

	if (r < i or l > i) {
		return;
	}

	if (l == r) {
		seg[cur]++;
		return;
	}

	update(LEFT(cur), l, m, i);
	update(RIGHT(cur), m + 1, r, i);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}


void solve(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) a[i] = 0;

	build(1, 1, n);

	long long ans = 0;

	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);

		int more = query(1, 1, n, x, n);

		ans += more;

		update(1, 1, n, x);
	}

	printf("%lld\n", ans);
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