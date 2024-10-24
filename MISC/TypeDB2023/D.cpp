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

vector<int> a;
vector<int> color;
vector<int> cnt;
int n;	
int one_out;


void paint(int u){
	if((u > n or u < 1) or color[u] != 0){
		if(u > n or u < 1) one_out = 1;
		return;
	}
	color[u] = u;
	paint(u+a[u]);
}

int findOneOut(int u){

	if(u > n or u < 1){
		return -1;
	}
	if(color[u] != 0) return color[u];

	color[u] = -2;

	return color[u] = findOneOut(u+a[u]);

}

int seg[4 * N + 1];

int merge(int nl, int nr) {
	return nl + nr; // (input) this operation must be reversable and conform to problem
}

void build(int cur, int l, int r) {
	int m = (l + r) / 2;

	if (l == r) {
		seg[cur] = cnt[l];
		return;
	}

	build(LEFT(cur), l, m);
	build(RIGHT(cur), m + 1, r);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

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
	scanf("%d", &n);
	a.assign(n+1, 0);
	color.assign(n+1, 0);
	cnt.assign(n+1, 0);
	one_out = 0;

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	paint(1);

	int cnt_ones = 0;
	vector<int> ones_idx;
	for(int i = 1; i <= n; i++){
		if(color[i] >= 1){
			ones_idx.push_back(i);
			cnt_ones++;
		}
	}

	for(int i = 1; i <= n; i++){
		if(!color[i]) findOneOut(i);
	}

	int cnt_outs = 0;
	for(int i = 1; i <= n; i++){
		if(color[i] == -1) cnt_outs++;
	}

	//return;
	long long ans = 0;

	// for(int i = 1; i <= n; i++){
	// 	printf("%d ", color[i]);
	// }
	// printf("\n");

	for(int i : ones_idx){
		ans += (n - ((n+1) - i) + 1);
		ans += (n - (i - 0) + 1);
	}

	ans += cnt_ones * cnt_outs;
	
	if(one_out){
		for(int i = 1; i <= n; i++){
			if(color[i] >= 1){
				cnt[color[i]]++;
			}
		}

		build(1, 1, n);

		// printf("cnt: ");
		
		// for(int i = 1; i <= n; i++){
		// 	printf("%d ", cnt[i]);
		// }
		// printf("\n");

		for(int i : ones_idx){
			ans += query(1, 1, n, i+1, n);
		}

		for(int i = 1; i <= n-ones_idx.size(); i++){
			ans += 2*n+1;
		}
	}

	printf("%lld\n", ans);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}