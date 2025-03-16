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

#define N 200000
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

int seg[4 * N + 1];
int a[N + 1]; // (input) an array of data to operate querys and updates over

// O(1)
int merge(int nl, int nr) {
    return (nl ^ nr); // (input) this operation must be reversable and conform to problem
}

// O(N)
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

// O(log(N))
int query(int cur, int l, int r, int i, int j) {
    int nl, nr, m = (l + r) / 2;

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

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	build(1, 1, n);

	string s;
	cin >> s;

	int xorZ = 0;
	int xorO = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == '1') xorO ^= a[i+1];
		else xorZ ^= a[i+1];
	}

	int q; cin >> q;

	while(q--){
		int t;
		cin >> t;

		if(t == 1){
			int l, r;
			cin >> l >> r;
			xorZ ^= query(1,1,n,l,r);
			xorO ^= query(1,1,n,l,r);
		}
		else{
			int g;
			cin >> g;
			if(g){
				cout << xorO << " ";
			}
			else{
				cout << xorZ << " ";
			}
		}
	}
	cout << endl;
}

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