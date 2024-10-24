#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 2000000
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

map<ll,ll> mb;

ll seg[4 * N + 1];
ll seg2[4 * N + 1];
ll lazy[4 * N + 1];
bool pref[4 * N + 1];
bool sufx[4 * N + 1];

// O(log(N))
ll query(int cur, int l, int r, int i, int j) {
	// cout << l << " " << r << endl;
	ll nl, nr;
	int m = (l + r) / 2;

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return 0;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		// cout << "ans > seg[" << l << "," << r << "] = " << seg[cur] << endl;
		return seg[cur];
	}

	nl = query(LEFT(cur), l, m, i, j);
	nr = query(RIGHT(cur), m + 1, r, i, j);

	ll ans = nl + nr;

	if(nl>0 and nr>0){
		if(pref[RIGHT(cur)] and sufx[LEFT(cur)]){
			ans += mb[m+1]-mb[m]-1;
		}
	}

	// cout << "ans > seg[" << l << "," << r << "] = " << ans << endl;

	return ans; // return the merge of all curs that are inside my desired range of search [i,j]
}

// O(log(N))
void update(int cur, int l, int r, int i, int j) {
	int m = (l + r) / 2;

	if (seg[cur] == mb[r]-mb[l]+1 or r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return;
	}

	if (l == r) { // this cur is completely inside my desired range of search [i,j]
		// cout << "update " << l << " " << r << endl;
		seg[cur] = 1;
		pref[cur] = sufx[cur] = 1;
		return;
	}

	update(LEFT(cur), l, m, i, j);
	update(RIGHT(cur), m + 1, r, i, j);

	seg[cur] = seg[LEFT(cur)] + seg[RIGHT(cur)];
	
	if(pref[RIGHT(cur)] and sufx[LEFT(cur)]){
		seg[cur] += mb[m+1]-mb[m]-1;
	}

	// cout << "seg[" << l << "," << r << "] = " << seg[cur] << endl;

	pref[cur] = pref[LEFT(cur)];
	sufx[cur] = sufx[RIGHT(cur)];
}

// O(1)
void lazy_update(int cur, int l, int r){
	seg2[cur] = seg2[cur] + lazy[cur];	// this operation is for a range sum query 
	//seg2[cur] = seg2[cur] + lazy[cur]; 			// this is for a min value range query 

	// if not leaf node
	if(l < r){
		// lazily propagating update to children
		lazy[LEFT(cur)] += lazy[cur];
		lazy[RIGHT(cur)] += lazy[cur];
	}

	lazy[cur] = 0;
}
// O(log(N))
void updatemin(int cur, int l, int r, int i, int j, ll x) {
	int m = (l + r) / 2;

	if(lazy[cur] != 0){
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

	updatemin(LEFT(cur), l, m, i, j, x);
	updatemin(RIGHT(cur), m + 1, r, i, j, x);

	seg2[cur] = min(seg2[LEFT(cur)], seg2[RIGHT(cur)]);
}

// O(log(N))
ll querymin(int cur, int l, int r, int i, int j) {
	ll nl, nr;
	int m = (l + r) / 2;

	if(lazy[cur] != 0){
		lazy_update(cur, l, r);
	}

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return INF;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		return seg2[cur];
	}

	nl = querymin(LEFT(cur), l, m, i, j);
	nr = querymin(RIGHT(cur), m + 1, r, i, j);

	seg2[cur] = min(seg2[LEFT(cur)], seg2[RIGHT(cur)]);

	return min(nl,nr); // return the merge of all curs that are inside my desired range of search [i,j]
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;

	vector<tuple<ll,ll,ll>> a;
	vector<ll> b;

	for(int i = 0; i < n; i++){
		ll l, r, c;
		cin >> l >> r >> c;

		a.push_back({c,l,r});
		b.push_back(l);
		b.push_back(r);
	}

	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end())-b.begin());

	map<ll,ll> m;
	for(int i = 0; i < b.size(); i++){
		m[b[i]] = i+1;
		mb[i+1] = b[i];
	}

	sort(a.begin(), a.end());

	vector<int> take;

	for(int i = 0; i < a.size(); i++){
		ll c, l, r;
		tie(c,l,r) = a[i];

		ll t = r-l+1;
		ll s = query(1,1,b.size(),m[l],m[r]);

		//cout << l << " " << r << " " << c << " | " << t << " - " << s << endl;

		if((t-s) * k - c > 0){
			take.push_back(i);
			update(1,1,b.size(),m[l],m[r]);
			updatemin(1,1,b.size(),m[l],m[r],1);
		}
	}

	ll ans = query(1,1,b.size(), 1, b.size()) * k;

	reverse(take.begin(), take.end());

	for(int i : take){
		ll c, l, r;
		tie(c, l, r) = a[i];

		if(querymin(1,1,b.size(), m[l], m[r]) == 1){
			ans -= c;
		}
		else{
			updatemin(1,1,b.size(), m[l], m[r], -1);
		}
	}

	cout << ans << endl;

	return 0;
}