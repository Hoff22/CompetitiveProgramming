#include <bits/stdc++.h>

#define N 300000
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

int a[N+1];
int b[N+1];

long long seg[4 * (2000+1) + 1][5];

long long merge(long long nl, long long nr) {
	return nl + nr; // (input) this operation must be reversable and conform to problem
}

void build(int cur, int l, int r) {
	int m = (l + r) / 2;

	if (l == r) {
		seg[cur][0] = 0;
		seg[cur][1] = 0;
		seg[cur][2] = 0;
		seg[cur][3] = 0;
		seg[cur][4] = 0;
		return;
	}

	build(LEFT(cur), l, m);
	build(RIGHT(cur), m + 1, r);

	seg[cur][0] = merge(seg[LEFT(cur)][0], seg[RIGHT(cur)][0]);
	seg[cur][1] = merge(seg[LEFT(cur)][1], seg[RIGHT(cur)][1]);
	seg[cur][2] = merge(seg[LEFT(cur)][2], seg[RIGHT(cur)][2]);
	seg[cur][3] = merge(seg[LEFT(cur)][3], seg[RIGHT(cur)][3]);
	seg[cur][4] = merge(seg[LEFT(cur)][4], seg[RIGHT(cur)][4]);
}

long long query(int cur, int l, int r, int i, int j, int k) {
	long long nl, nr;
	int m = (l + r) / 2;

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return 0;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		return seg[cur][k];
	}

	nl = query(LEFT(cur), l, m, i, j, k);
	nr = query(RIGHT(cur), m + 1, r, i, j, k);

	return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
}

void update(int cur, int l, int r, int i, int k, int x) {
	int m = (l + r) / 2;

	if (r < i or l > i) {
		return;
	}

	if (l == r) {
		seg[cur][k] += x;
		return;
	}

	update(LEFT(cur), l, m, i, k, x);
	update(RIGHT(cur), m + 1, r, i, k, x);

	seg[cur][0] = merge(seg[LEFT(cur)][0], seg[RIGHT(cur)][0]);
	seg[cur][1] = merge(seg[LEFT(cur)][1], seg[RIGHT(cur)][1]);
	seg[cur][2] = merge(seg[LEFT(cur)][2], seg[RIGHT(cur)][2]);
	seg[cur][3] = merge(seg[LEFT(cur)][3], seg[RIGHT(cur)][3]);
	seg[cur][4] = merge(seg[LEFT(cur)][4], seg[RIGHT(cur)][4]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i] += 1000;
	}
	

	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
		b[i] += 1000;
	}


	build(1, 0, 2000+1);
	long long ans = 0;

	for(int i = 1; i <= n; i++){
		
		update(1, 0, 2000+1, a[i], 1, 1);	// update dp[a[i]][1] += 1
		long long k1 = query(1, 0, 2000+1, 0, a[i] - 1, 1);
		update(1, 0, 2000+1, a[i], 2, k1);	// update dp[a[i]][2] += k1
		long long k2 = query(1, 0, 2000+1, 0, a[i] - 1, 2);
		update(1, 0, 2000+1, a[i], 3, k2);	// update dp[a[i]][3] += k2
		long long k3 = query(1, 0, 2000+1, 0, a[i] - 1, 3);
		update(1, 0, 2000+1, a[i], 4, k3);	// update dp[a[i]][4] += k3		

	}

	ans = query(1, 0, 2000+1, 0, *max_element(a+1, a+n+1), 4);

	printf("%lld\n", ans);

	return 0;

}