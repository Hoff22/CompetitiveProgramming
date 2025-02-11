#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

#define LEFT(x) (2*x)
#define RIGHT(x) (2*x+1)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int seg[4 * N + 1];
vector<int> a;
int n, k;

// O(1)
int merge(int nl, int nr) {
    return max(nl, nr); // (input) this operation must be reversable and conform to problem
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
int query(int i, int j, int cur = 1, int l = 0, int r = n-1) {
    int nl, nr, m = (l + r) / 2;

    if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
        return -0x3f3f3f3f;
    }

    if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
        return seg[cur];
    }

    nl = query(i, j, LEFT(cur), l, m);
    nr = query(i, j, RIGHT(cur), m + 1, r);

    return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
}

void solve(){
	cin >> n >> k;
	a.clear();
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		a.push_back(x);
	}

	if(n == k){
		for(int i = 1; i*2-1 <= n; i++){
			if(i != a[i*2-1]){
				cout << i << endl;
				return;
			}
		}
		cout << k/2 + 1 << endl;
		return;
	}

	build(1, 0, n-1);

	if(query(1, n-k+1) == 1) cout << 2 << endl;
	else cout << 1 << endl;
}

/*


[ 1 1 ][ 1 1 2 ][ 2 ][ 2 ][ 3 ][ 3 ]

1 1 1 1 2 2 2 3 3

[ 1 1 1 1 ][ 2 2 2 ][ 3 3 ]
[ 1 1 1 1 ][ 2 ][ 2 ][ 2 ][ 3 ][ 3 ]



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