#include <bits/stdc++.h>

#define N 300000
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

int n;
vector<int> a;
int seg[4 * N + 1];
int dp[N+1];

int merge(int nl, int nr) {
	return max(nl, nr); // (input) this operation must be reversable and conform to problem
}

void build(int cur, int l, int r) {
	int m = (l + r) / 2;

	if (l == r) {
		seg[cur] = dp[l];
		return;
	}

	build(LEFT(cur), l, m);
	build(RIGHT(cur), m + 1, r);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

void update(int cur, int l, int r, int i, int x) {
	int m = (l + r) / 2;

	if (r < i or l > i) {
		return;
	}

	if (l == r) {
		seg[cur] = x;
		return;
	}

	update(LEFT(cur), l, m, i, x);
	update(RIGHT(cur), m + 1, r, i, x);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

int query(int cur, int l, int r, int i, int j, int val) {
	int nl, nr, m = (l + r) / 2;

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return 0;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		return seg[cur] * ((a[l] ^ val) < (a[val] ^ l));
	}

	nl = query(LEFT(cur), l, m, i, j, val);
	nr = query(RIGHT(cur), m + 1, r, i, j, val);

	return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
}


void solve(){
	scanf("%d", &n);
	a.resize(n);



	int MIN_VAL = 0;
	int MAX_VAL = n-1;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	//m = a;
	//m.resize(unique(c.begin(), c.end()) - c.begin());

	for(int i = 0; i < n; i++) dp[i] = 1;

	build(1, MIN_VAL, MAX_VAL);

// j < i : a[j] < a[i]
	for(int i = 1; i < n; i++){
		dp[i] = query(1, MIN_VAL, MAX_VAL, MIN_VAL, i - 1, i) + 1;
		update(1, MIN_VAL, MAX_VAL, i, dp[i]);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, dp[i]);
	}

	printf("%d\n", ans);
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