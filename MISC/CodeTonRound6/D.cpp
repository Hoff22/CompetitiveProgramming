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

typedef long long ll;

ll seg[4 * N + 1];
ll lazy[4 * N + 1];

// O(1)
ll merge(ll nl, ll nr) {
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
ll query(int cur, int l, int r, int i, int j) {
	ll nl, nr;
	int m = (l + r) / 2;

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
		lazy[cur] = x;
		lazy_update(cur, l, r);
		return;
	}

	update(LEFT(cur), l, m, i, j, x);
	update(RIGHT(cur), m + 1, r, i, j, x);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

void solve(){
	ll n, k;
	cin >> n;
	
	build(1,1,n);

	vector<ll> c(n+1);
	for(int i = 1; i <= n; i++) cin >> c[i];
	cin >> k;

	vector<pair<ll,int>> s;
	int mn = INF;
	for(int i = n; i >= 1; i--){
		if(c[i] < mn){
			mn = c[i];
			s.push_back({c[i],-i});
		}
	}

	sort(s.begin(), s.end());

	// for(auto [p, j] : s) cout << p << "," << j << " ";
	// cout << endl;

	ll last = k/s[0].fi;
	ll cur = k%s[0].fi;
	update(1,1,n,1,-s[0].se,last);
	for(int i = 0; i < s.size()-1; i++){
		// cout << i << " " << k/s[i].fi << " == " << k/s[i+1].fi << endl;
		if(cur/(s[i+1].fi-s[i].fi) > 0){
			int q = min(last, cur/(s[i+1].fi-s[i].fi));
			update(1,1,n,1,-s[i].se,-q);
			update(1,1,n,1,-s[i+1].se,q);
			last = q;
			cur -= q*(s[i+1].fi-s[i].fi);
		}
		else break;
	}

	// cout << i << "!!! "; 
	// cout << s[i].fi << ", " << s[i].se << endl;
	for(int j = 1; j <= n; j++){
		cout << query(1,1,n,j,j) << " ";
	}
	cout << endl;

}

/*
6
10 6  4  6  3  4

2  2  2  2  2  1

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