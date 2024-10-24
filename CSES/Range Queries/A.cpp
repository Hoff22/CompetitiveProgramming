#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int N = 500000;
constexpr int M = 1000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;

#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

typedef long long ll;

int seg[4 * N + 1];

// O(1)
int merge(int nl, int nr) {
    return nl + nr; // (input) this operation must be reversable and conform to problem
}

// O(N)
void build(int cur, int l, int r) {
    int m = (l + r) / 2;

    if (l == r) {
        seg[cur] = 0;
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

// O(log(N))
void update(int cur, int l, int r, int i, int x) {
    int m = (l + r) / 2;

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

void solve(){
	int n, q;
	cin >> n >> q;

	vector<int> v;
	vector<int> a(n+1);

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		v.push_back(a[i]);
	}

	vector<tuple<char,int,int>> qrs;

	for(int i = 0; i < q; i++){
		char op;
		int x, y;
		cin >> op >> x >> y;

		qrs.push_back({op,x,y});

		if(op == '?'){
			v.push_back(x);
		}
		v.push_back(y);
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	for(int& i : a) i = (int)(lower_bound(v.begin(), v.end(), i) - v.begin());
	for(auto& [op, x, y] : qrs){
		if(op == '?'){
			x = (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
		}
		y = (int)(lower_bound(v.begin(), v.end(), y) - v.begin());
	}

	build(1,0,(int)v.size());

	int m = (int)v.size();	

	for(int i = 1; i <= n; i++){
		update(1, 0, m, a[i], +1);
	}

	for(auto [op, x, y] : qrs){
		if(op == '!'){
			update(1, 0, m, a[x], -1);
			update(1, 0, m, y,    +1);
			a[x] = y;
		}
		else{
			cout << query(1, 0, m, x, y) << endl;
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}