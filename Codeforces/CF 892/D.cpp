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
	return max(nl, nr); // (input) this operation must be reversable and conform to problem
}

// O(1)
void lazy_update(ll cur, ll l, ll r){
	//seg[cur] = seg[cur] + lazy[cur] * (r-l+1);	// this operation is for a range sum query 
	seg[cur] = max(seg[cur] , lazy[cur]); 				// this is for a max value range query 

	// if not leaf node
	if(l < r){
		// lazily propagating update to children
		lazy[LEFT(cur)] = max(lazy[cur],lazy[LEFT(cur)]);
		lazy[RIGHT(cur)] = max(lazy[cur],lazy[RIGHT(cur)]);
	}

	lazy[cur] = 0;
}

// O(N)
void build(ll cur, ll l, ll r) {
	ll m = (l + r) / 2;

	//cout << "build " << l << " " << r << " " << cur << endl;

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

void solve(){
	ll n;
	cin >> n;
	
	vector<ll> lb(n);
	vector<ll> rb(n);
	vector<ll> lv(n);
	vector<ll> rv(n);
	vector<ll> segs(n);

	for(ll i = 0; i < n; i++){
		ll l,r, a, b;
		cin >> l >> r >> a >> b;
		lb[i] = l;
		rb[i] = r;
		lv[i] = a;
		rv[i] = b;

		segs[i] = i;
	}	
	
	auto comp = [&](int i, int j){
		if(rv[i] == rv[j]){
			return lb[i] < lb[j];
		}
		return rv[i] < rv[j];
	};

	sort(segs.begin(), segs.end(), comp);

	stack<pair<ll,ll>> b;
	stack<pair<ll,ll>> v;

	for(ll i = 0; i < n; i++){
		ll s = segs[i];
		if(b.empty()){
			b.push({lb[s], rb[s]});
			v.push({lv[s], rv[s]});
		}
		else{

			ll cur_lb, cur_rb, cur_lv, cur_rv;
			cur_lb = lb[s];
			cur_rb = rb[s];
			cur_lv = lv[s];
			cur_rv = rv[s];
			
			while(b.size() and cur_lb <= v.top().se){
				ll last_lb, last_rb, last_lv, last_rv;
				last_lb = b.top().fi;
				last_rb = b.top().se;
				last_lv = v.top().fi;
				last_rv = v.top().se;

				b.pop();
				v.pop();

				cur_lb = min(cur_lb, last_lb);
				cur_rb = max(cur_rb, last_rb);
				cur_lv = min(cur_lv, last_lv);
				cur_rv = max(cur_rv, last_rv);
			}

			b.push({cur_lb, cur_rb});
			v.push({cur_lv, cur_rv});
		}
	}

	lb.clear();
	rb.clear();
	lv.clear();
	rv.clear();
	segs.clear();

	for(ll i = 0; b.size(); i++){
		lb.push_back(b.top().fi);
		rb.push_back(b.top().se);
		lv.push_back(v.top().fi);
		rv.push_back(v.top().se);
		segs.push_back(i);
		b.pop();
		v.pop();
	}

	sort(segs.begin(), segs.end(), comp);

	n = segs.size();

	ll q;
	cin>> q;

	vector<pair<ll,ll>> x(q);
	vector<ll> ans(q, 0);

	build(1, 1, q);

	for(ll i = 0; i < q; i++){
		cin >> x[i].fi;
		x[i].se = i;
	}

	sort(x.begin(), x.end());

	for(ll i = 0; i < n; i++){
		ll s = segs[i];

		ll l, r;
		l = lb[s];
		r = rb[s];

		// cout << lb[s] << " " << rb[s] << endl;
		// cout << lv[s] << " " << rv[s]  << endl<< endl;

		ll xl = (ll)(lower_bound(x.begin(), x.end(), make_pair(l,-1ll)) - x.begin());
		ll xr = (ll)(upper_bound(x.begin(), x.end(), make_pair(r,-1ll)) - x.begin());

		update(1, 1, q, xl+1, xr+1, rv[s]);
	}

	for(ll i = 0; i < q; i++){
		ans[x[i].se] = max(query(1, 1, q, i+1, i+1), x[i].fi);
	}

	for(ll i : ans) cout << i << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}