#include <bits/stdc++.h>

#define MAX 10000000
#define E 0.0000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first
#define pi 3.1415926535897932384626433

using namespace std;

typedef long long ll;

#define N 600000
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

ll seg[4 * N + 1];
ll lazy[4 * N + 1];

// O(1)
ll merge(ll nl, ll nr) {
	return min(nl,nr); // (input) this operation must be reversable and conform to problem
}

// O(1)
void lazy_update(ll cur, ll l, ll r){
	// seg[cur] = seg[cur] + lazy[cur] * (r-l+1);	// this operation is for a range sum query 
	seg[cur] = lazy[cur]; 			// this is for a max value range query 

	// if not leaf node
	if(l < r){
		// lazily propagating update to children
		lazy[LEFT(cur)] = lazy[cur];
		lazy[RIGHT(cur)] = lazy[cur];
	}

	lazy[cur] = 0;
}

// O(N)
void build(ll cur, ll l, ll r) {
	ll m = (l + r) / 2;

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
ll query(ll cur, ll l, ll r, ll i, ll j) {
	ll nl, nr, m = (l + r) / 2;

	if(lazy[cur]){
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
void update(ll cur, ll l, ll r, ll i, ll j, ll x) {
	ll m = (l + r) / 2;

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

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;

	cin >> n;

	vector<tuple<ll,ll,ll>> e;
	vector<ll> tin(n+1);

	vector<ll> comp;

	for(ll i = 1; i <= n; i++){
		ll amt;
		cin >> tin[i] >> amt;

		e.push_back({tin[i], -amt, i});
		e.push_back({tin[i]+amt, -amt, -i});
		comp.push_back(tin[i]);
		comp.push_back(tin[i]+amt);
	}

	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

	ll sn = comp.size();

	sort(e.begin(), e.end());

	build(1,1,sn);

	vector<ll> ans(n+1, 0);
	for(auto [t, amt, p] : e){
		if(p < 0){ // saida

		}
		else{
			ll l = (ll)(lower_bound(comp.begin(), comp.end(), t) - comp.begin());
			ll r = (ll)(lower_bound(comp.begin(), comp.end(), t-amt) - comp.begin());

			ll k = query(1, 1, sn, l, r);
			// cout << p << " " << l << endl;
			ans[p] = k;
			update(1,1,sn, l, r, k+1);
		}

	}

	for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;

}