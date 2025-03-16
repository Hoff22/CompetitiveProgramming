#include <bits/stdc++.h>

#define N 300000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

/*
	segmented_tree(int n, T identity_element, vector<T>& input, T (*m)(T,T))

	n = size of input
	identity_element = identity for merge query outside of range
	input = data vector 1 indexed
	m = merge function pointer 

	seg.update(i, x) = point update with X
	seg[{i,j}] = range query i, j
*/

template <class T>
class segmented_tree{
public:
	int s;
	T (*merge)(T,T);
	T ie;
	vector<T> seg;

	void build(int cur, int l, int r, vector<T>& input) {
		int m = (l + r) / 2;

		if (l == r) {
			seg[cur] = input[l];
			return;
		}

		build(LEFT(cur), l, m, input);
		build(RIGHT(cur), m + 1, r, input);

		seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}

	void build(int cur, int l, int r) {
		int m = (l + r) / 2;

		if (l == r) {
			seg[cur] = ie;
			return;
		}

		build(LEFT(cur), l, m);
		build(RIGHT(cur), m + 1, r);

		seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}

	segmented_tree(int n, T identity_element, vector<T>& input, T (*m)(T,T)){
		s = n;
		merge = m;
		ie = identity_element;
		seg.resize(s*4+1);
		build(1,0,n-1,input);
	}

	segmented_tree(int n, T identity_element, T (*m)(T,T)){
		s = n;
		merge = m;
		ie = identity_element;
		seg.resize(s*4+1);
		build(1,0,n-1);
	}

	T query_(int cur, int l, int r, int i, int j) {
		T nl, nr; 
		int m = (l + r) / 2;

		if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
			return ie;
		}

		if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
			return seg[cur];
		}

		nl = query_(LEFT(cur), l, m, i, j);
		nr = query_(RIGHT(cur), m + 1, r, i, j);

		return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
	}

	T query(int i, int j){
		return query_(1,0,s-1,i,j);
	}

	void update(int i, T x){
		update_(1,0,s-1,i,x);
	}

	void update_(int cur, int l, int r, int i, T x) {
		int m = (l + r) / 2;

		if (r < i or l > i) {
			return;
		}

		if (l == r) {
			seg[cur] = x;
			return;
		}

		update_(LEFT(cur), l, m, i, x);
		update_(RIGHT(cur), m + 1, r, i, x);

		seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}

	T operator[](const pair<int,int> i){
		return query_(1,0,s-1,i.fi,i.se);
	}

};

void solve(){
	int n;
	cin >> n;

	segmented_tree<int> sg(n, 0x3f3f3f3f, [](int x, int y){return min(x,y);});
	
	vector<int> a;
	int z = 0;

	for(int i = 0; i < n; i++){
		int x; cin >> x;

		if(x == 0){
			if(!z){
				z = 1;
				a.push_back(x);
			}
		}
		else{
			sg.update((int)a.size(), x);
			a.push_back(x);
		}
	}	
	// for(int i = 0; i < a.size(); i++) cout << a[i] <<" ";
	// cout << endl;

	set<int> mex; 
	for(int i = 0; i <= n; i++) mex.insert(i);

	for(int i = a.size()-1; i >= 1; i--){
		mex.erase(a[i]);
		int m = *(mex.begin());
		if(sg.query(0, i-1) < m){
			cout << (int)a.size()-1 << endl;
			return;
		}
	}
	cout << (int)a.size() << endl;	
}

/*
6
2 2 4 5 3 2
.
. .
. . . .



*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc;
	cin >> tc;
	
	while(tc--){
		solve();
	}
    return 0;

}