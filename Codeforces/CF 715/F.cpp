#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int q(int l, int r){
	int r;
	printf("? %d %d\n", l, r)
	fflush(stdout);
	scanf("%d", &r);
	return r;
}

pair<int,int> seg[4*N+1];

void build(int cur, int l, int r, int fr){

	int m = (r + l) / 2;

	int ls = fr + q(l, r);

	seg[cur] = {fr+1, ls};

	if(fr > ls or l == r) return;

	build(LEFT(cur), l, m, fr);
	build(RIGHT(cur), m+1, r, seg[LEFT(cur)].second);
}

int find(int cur, int l, int r, int k){
	
	int m = (r + l) / 2;

	if(seg[cur].first > k or seg[cur].second < k){
		return -1;
	}

	if(l == r){
		return seg[cur].first;
	}

	return max(find(LEFT(cur), l, m, k), find(RIGHT(cur), m+1, r, k));
}

// 1 1 0 0 0 0 1 1 0 1

// 1101
// 0010

int main(){
	
	int n, t;

	scanf("%d%d", &n, &t);

	while(t--){
		int k;
		scanf("%d", &k);

		build(1, 1, n, 0);

		printf("! %d\n", find(1, 1, n, k))
	}

    return 0;
}