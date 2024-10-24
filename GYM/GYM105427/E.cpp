#include <bits/stdc++.h>
#include <bit>

#define N 1000
#define M 10000
#define MAXN 10000
#define K 15
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

typedef long long ll;

int n;
ll c[N+1];
int qnt[N+1];
vector<int> order;
ll DP[2][M+2];

// O(1)
int merge(int nl, int nr) {
	if(DP[0][nl] < DP[0][nr]) return nl;
	return nr;
}

namespace evens{
	int seg[4 * M + 1];

	// O(N)
	void build(int cur, int l, int r) {
	    int m = (l + r) / 2;

	    if (l == r) {
	    	if(l%2) seg[cur] = M+1;
	    	else seg[cur] = l;
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
	        return M+1;
	    }

	    if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
	        return seg[cur];
	    }

	    nl = query(LEFT(cur), l, m, i, j);
	    nr = query(RIGHT(cur), m + 1, r, i, j);

	    return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
	}
}

namespace odds{
	int seg[4 * M + 1];

	// O(N)
	void build(int cur, int l, int r) {
	    int m = (l + r) / 2;

	    if (l == r) {
	    	if(l%2 == 0) seg[cur] = M+1;
	    	else seg[cur] = l;
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
	        return M+1;
	    }

	    if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
	        return seg[cur];
	    }

	    nl = query(LEFT(cur), l, m, i, j);
	    nr = query(RIGHT(cur), m + 1, r, i, j);

	    return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
	}
}

void solve(){
	cin >> n;
	int mx = 0;
	for(int i = 1; i <= n; i++){
		cin >> qnt[i] >> c[i];
		order.push_back(i);
		mx = max(mx, qnt[i]);
	}

	sort(order.begin(), order.end(), [&](int i, int j){
		return c[i] > c[j];
	});
	
	for(int q = 0; q <= 10001; q++){
		ll ans = 0x3f3f3f3f3f3f3f3f;
		DP[0][q] = ans;
	}
	DP[0][qnt[order[0]]] = qnt[order[0]] * c[order[0]];

	for(int i = 1; i < n; i++){
		// cout << i << ": " << endl; 

		for(int q = 0; q <= 10001; q++){
			DP[1][q] = 0x3f3f3f3f3f3f3f3f;
		}

		evens::build(1,0,10000);
		odds::build(1,0,10000);

		for(int q = 0; q <= mx; q++){
			ll ans = 0x3f3f3f3f3f3f3f3f;
			// q = 10
			// qnt[i] = 20
			// y => quantos eu vou dar match nessa

			// q - qoi + 2y >= 0
			// 2y >= qoi-q
			// y >= (qoi-q)/2

			/*
				q - qnt[order[i]] + 2*y >= y

				y >= qnt[order[i]] - q


			*/
			// cout << " " << q << ": " << endl;
			// cout << max(qnt[order[i]]-q, 0) << " - " << qnt[order[i]] << endl;

			int lastQ, y;
			int l = q - qnt[order[i]] + 2*max(qnt[order[i]]-q, 0);
			int r = q - qnt[order[i]] + 2*qnt[order[i]];

			// cout << l << " - " << r << endl;

			// for(int j = l; j <= r; j++){
			// 	cout << DP[0][j] << " ";
			// }
			// cout << endl;

			if((q-qnt[order[i]]) % 2){
				lastQ = odds::query(1,0,10000,l,r);
			}
			else{
				lastQ = evens::query(1,0,10000,l,r);
			}


			// lastQ = q - qnt[] + 2y
			// (lastQ - q + qnt) / 2 = y

			y = (lastQ - q + qnt[order[i]]) / 2;

			// cout << " " << lastQ << " " << y << " " << DP[0][lastQ] + (qnt[order[i]] - y) * c[order[i]] << endl;

			DP[1][q] = DP[0][lastQ] + (qnt[order[i]] - y) * c[order[i]];
			continue;

			for(int y = max(qnt[order[i]]-q, 0); y <= qnt[order[i]]; y++){
				int lastQ = q - qnt[order[i]] + 2*y;
				// cout << lastQ << " ";
				// cout  << "  > " << lastQ << " " << y << " > " << DP[i-1][lastQ] << endl;
				ans = min(DP[0][lastQ] + (qnt[order[i]] - y) * c[order[i]], ans);
			}
			// cout << endl;
			// cout << "  " << ans << endl;
			DP[1][q] = ans;
		}

		swap(DP[0], DP[1]);
	}

	ll ans = 0x3f3f3f3f3f3f3f3f;
	for(int q = 0; q <= 10000; q++){
		ans = min(DP[0][q], ans);
	}

	cout << ans << endl;
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