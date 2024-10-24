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

int seg[4 * N + 1];
int lazy[4 * N + 1];

// O(1)
int merge(int nl, int nr) {
	return nl + nr; // (input) this operation must be reversable and conform to problem
}

// O(1)
void lazy_update(int cur, int l, int r){
	seg[cur] = seg[cur] + lazy[cur] * (r-l+1);	// this operation is for a range sum query 
	//seg[cur] = seg[cur] + lazy[cur]; 			// this is for a max value range query 

	// if not leaf node
	if(l < r){
		// lazily propagating update to children
		lazy[LEFT(cur)] += lazy[cur];
		lazy[RIGHT(cur)] += lazy[cur];
	}

	lazy[cur] = 0;
}

// O(N)
void build(int cur, int l, int r) {
	int m = (l + r) / 2;

	lazy[cur] = 0;

	if (l == r) {
		seg[cur] = 0;
		return;
	}

	build(LEFT(cur), l, m);
	build(RIGHT(cur), m + 1, r);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

// O(log(N))
int query(int cur, int l, int r, int i, int j) {
	int nl, nr, m = (l + r) / 2;

	if(lazy[cur]){
		lazy_update(cur, l, r);
	}

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return 0;
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
		lazy[cur] += x;
		lazy_update(cur, l, r);
		return;
	}

	update(LEFT(cur), l, m, i, j, x);
	update(RIGHT(cur), m + 1, r, i, j, x);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	vector<int> b(n+1);

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}

	sort(a.begin()+1, a.end());

	build(1,1,n);

	for(int i = 1; i <= n; i++){
		int j = (int)(upper_bound(a.begin(),a.end(), b[i]) - a.begin());
		
		if(j > n) continue;

		update(1,1,n,j,n,1);
	}

	long long ans = 1;
	for(int i = 1; i <= n; i++){
		ans = (ans * (query(1,1,n,i,i) - i + 1)) % MOD;
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}