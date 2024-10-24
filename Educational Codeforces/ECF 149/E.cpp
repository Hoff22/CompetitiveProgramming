#include <bits/stdc++.h>

#define N 600000
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
int a[N + 1]; // (input) an array of data to operate querys and updates over

// O(1)
int merge(int nl, int nr) {
	return min(nl,nr); // (input) this operation must be reversable and conform to problem
}

// O(1)
void lazy_update(int cur, int l, int r){
	// seg[cur] = seg[cur] + lazy[cur] * (r-l+1);	// this operation is for a range sum query 
	seg[cur] = seg[cur] + lazy[cur]; 			// this is for a max value range query 

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
		if(a[l] == -1) seg[cur] = INF;
		else seg[cur] = a[l];
		return;
	}

	build(LEFT(cur), l, m);
	build(RIGHT(cur), m + 1, r);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

// O(log(N))
int query(int cur, int l, int r, int i, int j) {
	int nl, nr;
	int m = (l + r) / 2;

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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int k;
    cin >> k;

    int n = (1<<k);

    memset(a, -1, sizeof(a));

    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	if(x != -1) a[i] = x;
    }

    build(1,1,n);

    for(int i = 1; i <= n; i++){
    	if(a[i] > 1){
    		int out, l, r;

    		out = k;
    		while((1<<(k-out)) <= a[i]-1) out--;

    		l = r = i;
    		for(int j = 0; j < out; j++){
    			if(((i-1)>>j) & 1){
    				l -= (1<<j); 
    			}
    			else{
    				r += (1<<j);
    			}
    		}

    		if((i-1)>>out & 1){
	    		// cout << i-1 << " " << a[i] << ": " << out << " (" << l-1 << "-" << r-1 << ", " << l-(1<<out)-1 << "-" << r-1 << ")" << endl;
				// cout << "q1 : " << query(1,1,n,l,r) << "| q2: " << query(1,1,n,l-(1<<out),r) << endl;
	    		if(query(1,1,n,l,r) != a[i] or query(1,1,n,l-(1<<out),r) == a[i]){
	    			cout << 0 << endl;
	    			return 0;
	    		}
    		}
    		else{
    			// cout << i-1 << " " << a[i] << ": " << out << " (" << l-1 << "-" << r+(1<<out)-1 << ", " << l-1 << "-" << r-1 << ")" << endl;
				// cout << "q1 : " << query(1,1,n,l,r) << "| q2: " << query(1,1,n,l,r+(1<<out)) << endl;
    			if(query(1,1,n,l,r) != a[i] or query(1,1,n,l,r+(1<<out)) == a[i]){
	    			cout << 0 << endl;
	    			return 0;
	    		}
    		}

    	}
    }



    return 0;

}