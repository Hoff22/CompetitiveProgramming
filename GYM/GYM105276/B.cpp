#include <bits/stdc++.h>

#define N 300000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

vector<int> seg[4 * N + 1];
int a[N + 1]; // (input) an array of data to operate querys and updates over
int k,x,n;

// O(1)
vector<int> merge(vector<int>& nl, vector<int>& nr) {
	vector<int> p;

	int i = 0, j = 0;
	while(i < nl.size() or j < nr.size()){
		// cout << nl[i] << " " << nr[j] << endl;
		if(i < nl.size() and j < nr.size()){
			if(nl[i] < nr[j]){
				if(nr[0] - nl[i] <= x) p.push_back(nl[i]);
				i++;
			}
			else{
				if(nl[0] - nr[j] <= x) p.push_back(nr[j]);
				j++;
			}
		}
		else if(j < nr.size()){ // so j
			if(nl[0] - nr[j] <= x) p.push_back(nr[j]);
			j++;
		}
		else{ // so i
			if(nr[0] - nl[i] <= x) p.push_back(nl[i]);
			i++;
		}
	}

	return p;
}

// O(N)
void build(int cur, int l, int r) {
    int m = (l + r) / 2;

    if (l == r) {
        seg[cur].push_back(a[l]);
        return;
    }

    build(LEFT(cur), l, m);
    build(RIGHT(cur), m + 1, r);

    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

void solve(){
	cin >> k >> x;
	n = (1<<k);

	vector<int> ans(n,0);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	build(1, 0, n-1);


	// cout << query(0, 0) << " " << query(1, 1)<< " " << query(2, 2)<< " " << query(3, 3) << " " << query(4, 4) << " " << query(5, 5)<< " " << query(6, 6)<< " " << query(7, 7) << endl;
	// cout << " " << query(0, 1) << "   " << query(2, 3) << "   " << query(4, 5) << "   " << query(6, 7) << endl;
	// cout << "  " << " " << query(0, 3) << "       " << query(4, 7) << endl;
	// cout << "       " << query(0,7) << endl; 

	// for(int i : seg[2]) cout << i << " ";
	// cout << endl;

	for(int i = 0; i < n; i++){
		int l = 0, r = n-1;
		// cout << i << ": " << endl;
		int cur = 1;
		while(l < r){
			int m = (l + r) / 2;
			// cout << l << " " << r << " " << m << endl;
			if(i > m){ // ta na direita;
				ans[i] += (seg[LEFT(cur)][0] - a[i] > x);
				l = m+1;
				cur = RIGHT(cur);
			}
			else{
				ans[i] += (seg[RIGHT(cur)][0] - a[i] > x);
				r = m;
				cur = LEFT(cur);
			}
			
			// cout << i << ": ";
			// for(int j : q) cout << j << " ";
			// cout << endl; 
		}
	}	

	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}