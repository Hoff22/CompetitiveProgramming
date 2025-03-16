#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

namespace segInv{
	constexpr ll N = 200000;
	ll seg[4 * N + 1];

	// O(1)
	ll merge(ll nl, ll nr) {
	    return nl + nr; // (input) this operation must be reversable and conform to problem
	}

	// O(N)
	void build(ll cur, ll l, ll r) {
	    ll m = (l + r) / 2;

	    if (l == r) {
	        seg[cur] = 0;
	        return;
	    }

	    build(LEFT(cur), l, m);
	    build(RIGHT(cur), m + 1, r);

	    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}

	// O(log(N))
	ll query(ll cur, ll l, ll r, ll i, ll j) {
	    ll nl, nr, m = (l + r) / 2;

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

	// O(log(N))
	void update(ll cur, ll l, ll r, ll i, ll x) {
	    ll m = (l + r) / 2;

	    if (r < i or l > i) { // this cur is out of my desired range of search [i,j]
	        return;
	    }

	    if (l >= i and r <= i) { // this cur is completely inside my desired range of search [i,j]
	        seg[cur] += x;
	        return;
	    }

	    update(LEFT(cur), l, m, i, x);
	    update(RIGHT(cur), m + 1, r, i, x);

	    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}
}

namespace segL{
	constexpr ll N = 200000;
	ll seg[4 * N + 1];

	// O(1)
	ll merge(ll nl, ll nr) {
	    return nl + nr; // (input) this operation must be reversable and conform to problem
	}

	// O(N)
	void build(ll cur, ll l, ll r) {
	    ll m = (l + r) / 2;

	    if (l == r) {
	        seg[cur] = 0;
	        return;
	    }

	    build(LEFT(cur), l, m);
	    build(RIGHT(cur), m + 1, r);

	    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}

	// O(log(N))
	ll query(ll cur, ll l, ll r, ll i, ll j) {
	    ll nl, nr, m = (l + r) / 2;

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

	// O(log(N))
	void update(ll cur, ll l, ll r, ll i, ll x) {
	    ll m = (l + r) / 2;

	    if (r < i or l > i) { // this cur is out of my desired range of search [i,j]
	        return;
	    }

	    if (l >= i and r <= i) { // this cur is completely inside my desired range of search [i,j]
	        seg[cur] += x;
	        return;
	    }

	    update(LEFT(cur), l, m, i, x);
	    update(RIGHT(cur), m + 1, r, i, x);

	    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}
}

namespace segR{
	constexpr ll N = 200000;
	ll seg[4 * N + 1];

	// O(1)
	ll merge(ll nl, ll nr) {
	    return nl + nr; // (input) this operation must be reversable and conform to problem
	}

	// O(N)
	void build(ll cur, ll l, ll r) {
	    ll m = (l + r) / 2;

	    if (l == r) {
	        seg[cur] = 0;
	        return;
	    }

	    build(LEFT(cur), l, m);
	    build(RIGHT(cur), m + 1, r);

	    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}

	// O(log(N))
	ll query(ll cur, ll l, ll r, ll i, ll j) {
	    ll nl, nr, m = (l + r) / 2;

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

	// O(log(N))
	void update(ll cur, ll l, ll r, ll i, ll x) {
	    ll m = (l + r) / 2;

	    if (r < i or l > i) { // this cur is out of my desired range of search [i,j]
	        return;
	    }

	    if (l >= i and r <= i) { // this cur is completely inside my desired range of search [i,j]
	        seg[cur] += x;
	        return;
	    }

	    update(LEFT(cur), l, m, i, x);
	    update(RIGHT(cur), m + 1, r, i, x);

	    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}
}

// 5 3 | 5 0 1 5 3 | 5 0 1
// 4
// 2 6 2 3 4
// 3


void solve(){
	ll n, m;
	cin >> n >> m;

	vector<ll> a(n);
	for(ll i = 0; i < n; i++) cin >> a[i];

	ll tt = 0;

	segL::build(1,0,m);
	segR::build(1,0,m);
	segInv::build(1,0,m);

	vector<ll> okL(m+1,0);
	vector<ll> okR(m+1,0);

	for(ll i = n-1; i >= 0; i--){
		ll t = segInv::query(1,0,m,0,a[i]-1);
		tt += t;
		okL[a[i]] += (n-i-1) - t;
		segL::update(1, 0, m, a[i], t);
		segInv::update(1, 0, m, a[i], 1);
	}

	segInv::build(1,0,m);

	for(int i = 0; i < n; i++){
		ll t = segInv::query(1,0,m,a[i]+1,m);
		okR[a[i]] += i - t;
		segR::update(1, 0, m, a[i], t);
		segInv::update(1, 0, m, a[i], 1);
	}

	for(int i = m-1; i >= 0; i--){
		okR[i] = okR[i] + okR[i+1]; 
		okL[i] = okL[i] + okL[i+1]; 
	}

	for(int k = 0; k < m; k++){
		cout << tt - segL::query(1,0,m,m-k,m) + segR::query(1,0,m,m-k,m) - okL[m-k] + okR[m-k]  << endl; 
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
    return 0;
}