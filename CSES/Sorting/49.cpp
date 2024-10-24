#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

#define N 400000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF (1000000000ll * 200000ll)
#define se second
#define fi first

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<pair<ll,int>, null_type, less<pair<ll,int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;// find_by_order(x)


#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

pair<ll,int> seg[4 * N + 1];

// O(1)
pair<ll,int> merge(pair<ll,int> nl, pair<ll,int> nr) {
    return {nl.fi + nr.fi, nl.se + nr.se}; // (input) this operation must be reversable and conform to problem
}

// O(log(N))
pair<ll,int> query(int cur, int l, int r, int i, int j) {
    pair<ll,int> nl, nr;
    int m = (l + r) / 2;

    if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
        return {0,0};
    }

    if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
        return seg[cur];
    }

    nl = query(LEFT(cur), l, m, i, j);
    nr = query(RIGHT(cur), m + 1, r, i, j);

    return merge(nl, nr); // return the merge of apair<ll,int> curs that are inside my desired range of search [i,j]
}

// O(log(N))
void update(int cur, int l, int r, int i, pair<ll,int> x) {
    int m = (l + r) / 2;

    if (r < i or l > i) { // this cur is out of my desired range of search [i,j]
        return;
    }

    if (l >= i and r <= i) { // this cur is completely inside my desired range of search [i,j]
        seg[cur] = {seg[cur].fi + x.fi, seg[cur].se + x.se};
        return;
    }

    update(LEFT(cur), l, m, i, x);
    update(RIGHT(cur), m + 1, r, i, x);

    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

// O(N)
void build(int cur, int l, int r) {
    int m = (l + r) / 2;

    if (l == r) {
        seg[cur] = {0,0};
        return;
    }

    build(LEFT(cur), l, m);
    build(RIGHT(cur), m + 1, r);

    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

void solve(){
	int n, k;
	cin >> n >> k;

	vector<ll> a(n);

	vector<ll> b;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		b.push_back(a[i]);
	}

	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end())-b.begin());

	map<ll,ll> cp;
	for(int i = 0; i < b.size(); i++){
		cp[b[i]] = i+1;
	}

	build(1,1,cp.size());
	ordered_set s;

	for(int i = 0; i < n; i++){
		if(i < k-1){
			s.insert({a[i], i});
			update(1, 1, cp.size(), cp[a[i]], {a[i],1});
		} 
	}
	for(int i = 0, j = k-1; j < n; j++, i++){
		s.insert({a[j], j});
		// cout << "cp[a[j]]: " << cp[a[j]] << "  ";
		update(1, 1, cp.size(), cp[a[j]], {a[j],1});

		ll m = (*s.find_by_order((k-1)/2)).fi;
		pair<ll,int> above = query(1,1,cp.size(),cp[m],cp.size());
		pair<ll,int> below = query(1,1,cp.size(),1,cp[m]-1);
		ll suma = above.fi - (m*above.se);
		ll sumb = (m*below.se) - below.fi;

		if(cp[m]-1 < 1) sumb = 0;

		// cout << above.fi << "," << above.se << " | " << below.fi << "," << below.se << endl;

		//cout << m << ",";
		cout << suma + sumb << " ";

		// cout << a[i] << " " << i << endl;
		
		// cout << query(1,1,cp.size(), 2 , cp.size()).fi << " " << query(1,1,cp.size(), 2 , cp.size()).se << endl;

		s.erase({a[i], i});
		update(1, 1, cp.size(), cp[a[i]], {-a[i],-1});

		// cout << query(1,1,cp.size(), 2 , cp.size()).fi << " " << query(1,1,cp.size(), 2 , cp.size()).se << endl;
	}
	cout << endl;
}

/*


5 12 - 7+
6 10 - -1
8 15 - -4


*/

int main(){	
	ios_base::sync_with_stdio(false);
	int t;
    cin.tie(NULL);
	t = 1;
	while(t--){
		solve();
	}
    return 0;

}