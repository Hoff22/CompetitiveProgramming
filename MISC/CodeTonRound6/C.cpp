#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

#define N 100000
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

int seg[4 * N + 1];
int lazy[4 * N + 1];
int islazy[4 * N + 1];

// O(1)
int merge(int nl, int nr) {
	return min(nl,nr); // (input) this operation must be reversable and conform to problem
}

// O(1)
int mergemx(int nl, int nr) {
	return max(nl,nr); // (input) this operation must be reversable and conform to problem
}

// O(1)
void lazy_update(int cur, int l, int r){
	// cout << l << " " << r << " " << seg[cur] << " " << lazy[cur] << endl;
	seg[cur] = min(seg[cur],lazy[cur]);	// this operation is for a range sum query 
	//seg[cur] = seg[cur] + lazy[cur]; 			// this is for a max value range query 

	if(l < r){
		// lazily propagating update to children
		lazy[LEFT(cur)] = min(lazy[cur], lazy[LEFT(cur)]);
		lazy[RIGHT(cur)] = min(lazy[cur], lazy[RIGHT(cur)]);
		islazy[LEFT(cur)] = islazy[RIGHT(cur)] = 1;
	}

	islazy[cur] = 0;
	lazy[cur] = INF;
}

// O(1)
void lazy_updatemx(int cur, int l, int r){
	seg[cur] = max(seg[cur],lazy[cur]);	// this operation is for a range sum query 
	//seg[cur] = seg[cur] + lazy[cur]; 			// this is for a max value range query 

	// if not leaf node
	if(l < r){
		// lazily propagating update to children
		lazy[LEFT(cur)] = max(lazy[cur], lazy[LEFT(cur)]);
		lazy[RIGHT(cur)] = max(lazy[cur], lazy[RIGHT(cur)]);
		islazy[LEFT(cur)] = islazy[RIGHT(cur)] = 1;
	}

	islazy[cur] = 0;
	lazy[cur] = 0;
}

// O(N)
void build(int cur, int l, int r) {
	int m = (l + r) / 2;

	lazy[cur] = INF;
	islazy[cur] = 0;

	if (l == r) {
		seg[cur] = INF;
		return;
	}

	build(LEFT(cur), l, m);
	build(RIGHT(cur), m + 1, r);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

// O(N)
void buildmx(int cur, int l, int r) {
	int m = (l + r) / 2;

	lazy[cur] = 0;
	islazy[cur] = 0;

	if (l == r) {
		seg[cur] = 0;
		return;
	}

	buildmx(LEFT(cur), l, m);
	buildmx(RIGHT(cur), m + 1, r);

	seg[cur] = mergemx(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

// O(log(N))
int query(int cur, int l, int r, int i, int j) {
	int nl, nr, m = (l + r) / 2;

	if(islazy[cur]){
		lazy_update(cur, l, r);
	}

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return INF;
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
	// cout << l << " " << r << " " << i << " " << j << endl;

	if(islazy[cur]){
		lazy_update(cur, l, r);
	}

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		lazy[cur] = min(lazy[cur], x);
		islazy[cur] = 1;
		lazy_update(cur, l, r);
		return;
	}

	update(LEFT(cur), l, m, i, j, x);
	update(RIGHT(cur), m + 1, r, i, j, x);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

// O(log(N))
int querymx(int cur, int l, int r, int i, int j) {
	int nl, nr, m = (l + r) / 2;

	if(islazy[cur]){
		lazy_updatemx(cur, l, r);
	}

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return 0;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		return seg[cur];
	}

	nl = querymx(LEFT(cur), l, m, i, j);
	nr = querymx(RIGHT(cur), m + 1, r, i, j);

	seg[cur] = mergemx(seg[LEFT(cur)], seg[RIGHT(cur)]);

	return mergemx(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
}

// O(log(N))
void updatemx(int cur, int l, int r, int i, int j, int x) {
	int m = (l + r) / 2;

	if(islazy[cur]){
		lazy_updatemx(cur, l, r);
	}

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		lazy[cur] = max(lazy[cur], x);
		islazy[cur] = 1;
		lazy_updatemx(cur, l, r);
		return;
	}

	updatemx(LEFT(cur), l, m, i, j, x);
	updatemx(RIGHT(cur), m + 1, r, i, j, x);

	seg[cur] = mergemx(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	build(1,1,k);

	vector<int> mnX(k+1,INF);
	vector<int> mnY(k+1,INF);
	vector<int> mxX(k+1,0);
	vector<int> mxY(k+1,0);

	for(int i = 1; i <= n; i++){
		// cout << i << ": --------" << endl;
		update(1,1,k,1,a[i],i);
		// cout << "qry " << a[i] << " " << query(1,1,k,a[i],a[i]) << endl;
		// cout << "upd " << 1 << "," << a[i] << " = " << i << endl;
		// cout << "qry " << a[i] << " " << query(1,1,k,a[i],a[i]) << endl;
		int t = query(1,1,k, a[i], a[i]);
		// cout << t << endl;
		mnX[a[i]] = mnY[a[i]] = min(mnX[a[i]],t);
		// cout << endl;
	}

	
	buildmx(1,1,k);

	for(int i = n; i >= 1; i--){
		updatemx(1,1,k,1,a[i],i);
		int t = querymx(1,1,k, a[i], a[i]);
		mxX[a[i]] = mxY[a[i]] = max(mxY[a[i]],t);
	}
	
	vector<int> ans(k+1, 0);

	for(int i = 1; i <= k; i++){
		if(mxX[i] == 0 or mxY[i] == 0 or mnX[i] == INF or mnY[i] == INF){
			ans[i] = 0;
		}
		else{
			ans[i] = (mxX[i]-mnX[i]+1) + (mxY[i]-mnY[i]+1);
		}
	}

	// for(int i = 1; i <= k; i++){
	// 	cout << i << ": ";
	// 	cout << mnX[i] << " "<< mnY[i] << " "<< mxX[i] << " " << mxY[i] << " " << endl;
	// }

	for(int i = 1; i <= k; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}

/*
5 3
1 2 3 2 1

11 12 13 14 15   1 1 1 1 1
21 22 23 24 25   1 2 2 2 1 
31 32 33 34 35   1 2 3 2 1
41 42 43 44 45   1 2 2 2 1
51 52 53 54 55   1 1 1 1 1

3 5
3 2 4

11 12
21 22

11 12 13  3 2 3
21 22 23  2 2 2
31 32 33  3 2 4


*/

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