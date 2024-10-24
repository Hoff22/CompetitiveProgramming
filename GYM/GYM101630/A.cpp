#include <bits/stdc++.h>

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

/* O(1) - Retrieves the index of the Most Significant Bit. */
constexpr int msb_index(int mask) {
    return 8 * sizeof(mask) - __builtin_clz(mask) - 1;
}

/* O(1) - Retrieves ceil(log2(n)). */
constexpr int ceil_log2(int n) {
    assert(n > 0);
    return n == 1 ? 0 : msb_index(n - 1) + 1;
}

constexpr int N = 600000;
constexpr int L = ceil_log2(N);

set<ll> lazy[1 << (L + 1)];
set<ll> seg[1 << (L + 1)];

/* O(1) - Updates the current node with lazy and flushes down the lazyness. */
void lazy_update(int cur, int l, int r) {
    for(ll i : lazy[cur]){
    	if(seg[cur].count(i)){
    		seg[cur].erase(i);
    	}
    	else{
    		seg[cur].insert(i);
    	}
    }
    if (l < r) {
    	for(ll i : lazy[cur]){
    		if(lazy[LEFT(cur)].count(i)){
	    		lazy[LEFT(cur)].erase(i);
	    	}
	    	else{
	    		lazy[LEFT(cur)].insert(i);
	    	}
    		if(lazy[RIGHT(cur)].count(i)){
	    		lazy[RIGHT(cur)].erase(i);
	    	}
	    	else{
	    		lazy[RIGHT(cur)].insert(i);
	    	}
    	}
    }

    lazy[cur].clear();
}

/* O(Log(N)) - Updates the range [i..j]. */
void update(int cur, int l, int r, int i, int j, long long x) {
    int m = (l + r) / 2;


    if (lazy[cur].empty() == 0) {
        lazy_update(cur, l, r);
    }

    if (l > j or r < i) {
        return;
    }

    if (l >= i and r <= j) {
        lazy[cur].insert(x);
        lazy_update(cur, l, r);
        return;
    }

    update(LEFT(cur), l, m, i, j, x);
    update(RIGHT(cur), m + 1, r, i, j, x);
}

/* O(Log(N)) - Returns the content of the range [i, j] of the Segment Tree. */
set<ll> query(int cur, int l, int r, int i) {
    int m = (l + r) / 2;
    set<ll> nl, nr;


    if (lazy[cur].empty() == 0) {
        lazy_update(cur, l, r);
    }

    if (l == r) {
        return seg[cur];
    }

    if(i <= m){
    	return query(LEFT(cur), l, m, i);
    }
    return query(RIGHT(cur), m + 1, r, i);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    ll n;
	cin >> n;

	map<ll,ll> m;
	vector<ll> a;
	pair<ll,ll> c[200001];
	int t[200001];

	for(int i = 1; i <= n; i++){
		int q;
		ll x, y;
		cin >> q >> x >> y;
		if(q == 1){
			c[i] = {x, y};
			a.push_back(x-y);
			a.push_back(x+y);
		}
		else{
			c[i] = {x,y};
			a.push_back(x);
		}
		t[i] = q;
	}

	sort(a.begin(), a.end());
	for(int i : a){
		if(!m.count(i)) m[i] = m.size()+1;
	}


	for(int i = 1; i <= n; i++){
		if(t[i] == 1){
			update(1, 1, m.size(), m[c[i].fi-c[i].se], m[c[i].fi+c[i].se], i);
		}
		else{
			set<ll> res = query(1, 1, m.size(), m[c[i].fi]);

			ll ans = -1;

			for(ll j : res){
				ll x_c = c[j].fi;
				ll r_c = c[j].se;

				ll x = c[i].fi;
				ll y = c[i].se;


				if((x-x_c)*(x-x_c) + (y-r_c)*(y-r_c) < r_c*r_c){
					ans = j;
					break;
				}
			}

			cout << ans << endl; 
			if(ans != -1){
				update(1, 1, m.size(), m[c[ans].fi-c[ans].se], m[c[ans].fi+c[ans].se], ans);
			}
		}
	}


    return 0;

}