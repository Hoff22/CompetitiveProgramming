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

long long seg[4 * N + 1];
long long a[N + 1]; // (input) an array of data to operate querys and updates over

long long merge(long long nl, long long nr) {
	return nl + nr; // (input) this operation must be reversable and conform to problem
}

void build(int cur, int l, int r) {
	int m = (l + r) / 2;

	if (l == r) {
		seg[cur] = a[l];
		return;
	}

	build(LEFT(cur), l, m);
	build(RIGHT(cur), m + 1, r);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

long long query(int cur, int l, int r, int i, int j) {
	long long nl, nr, m = (l + r) / 2;

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return 0ll;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		return seg[cur];
	}

	nl = query(LEFT(cur), l, m, i, j);
	nr = query(RIGHT(cur), m + 1, r, i, j);

	return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
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

pair<ll, int> seg2[4 * N + 1];
long long mn;

pair<ll, int> merge2(pair<ll, int> nl, pair<ll, int> nr) {
	
	if(nr.fi <= mn) return nl;
	return nr;
}

void build2(int cur, int l, int r) {
	int m = (l + r) / 2;

	if (l == r) {
		seg2[cur] = make_pair(a[l], l);
		return;
	}

	build2(LEFT(cur), l, m);
	build2(RIGHT(cur), m + 1, r);

	seg2[cur] = merge2(seg2[LEFT(cur)], seg2[RIGHT(cur)]);
}

pair<ll, int> query2(int cur, int l, int r, int i, int j) {
	pair<ll, int> nl, nr;
	int m = (l + r) / 2;

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return make_pair(-INF, 0);
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		return seg2[cur];
	}

	nl = query2(LEFT(cur), l, m, i, j);
	nr = query2(RIGHT(cur), m + 1, r, i, j);

	return merge2(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
}

void update2(int cur, int l, int r, int i, long long x) {
	int m = (l + r) / 2;

	if (r < i or l > i) {
		return;
	}

	if (l == r) {
		seg2[cur] = make_pair(x, l);
		return;
	}

	update2(LEFT(cur), l, m, i, x);
	update2(RIGHT(cur), m + 1, r, i, x);

	seg2[cur] = merge2(seg2[LEFT(cur)], seg2[RIGHT(cur)]);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n, k;
    cin >> n >> k;
    vector<int> left(n+1, 0);
    vector<int> right(n+1, 0);

    mn = INF;

    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	mn = min(mn, a[i]);
    }

    build(1, 1, n);
    build2(1, 1, n);

    long long ans = 0;

    for(int i = 1; i+k-1 <= n; i++){
    	long long sum;
    	sum = query(1, 1, n, i, i+k-1);

    	// cout << i << " " << i+k-1 <<" ----" << endl;

    	while(sum >= 0){
	    	long long x;
	    	int idx;
	    	tie(x, idx) = query2(1, 1, n, i, i+k-1);

	    	// cout << "sum: " << sum << endl;
	    	// cout << idx << " " << endl;
	    	// cout << a[idx] << " " << x << endl;
// 
    		ans += (a[idx] - max(mn, a[idx]-(sum+1)));
    		a[idx] = max(mn, a[idx]-(sum+1));
    		update(1, 1, n, idx, a[idx]);
    		update2(1, 1, n, idx, a[idx]);

    		// cout << "new a[i] " << a[idx] << endl;

    		sum = query(1, 1, n, i, i+k-1);
    	}

    	// for(int j = 1; j <= n; j++){
	    	// cout << a[j] << " ";
	    // }
	    // cout << endl;
    }
    
    cout << ans << endl;
    for(int i = 1; i <= n; i++){
    	cout << a[i] << " ";
    }
    cout << endl;

    return 0;

}