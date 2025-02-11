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

struct point
{
	int x;
	int w;
	int idx;

	bool operator < (const point &b) const {
		return w < b.w;
	}
};

bool sort_x(point p1, point p2){
	return p1.x < p2.x;
}

void solve(){
	int n, m;
	scanf("%d %d", &n, &m);

	vector<point> ps;

	for(int i = 0; i < m; i++){
		int x, w;
		scanf("%d %d", &x, &w);

		point p;
		p.x = x;
		p.w = w;
		p.idx = i+1;

		ps.push_back(p);
	}

	sort(ps.begin(), ps.end());

	sort(ps.begin(), ps.begin() + 2*n, sort_x);

	int sum = 0;

	for(int i = 0; i < 2*n; i++){
		sum += ps[i].w;
	}
	printf("%d\n", sum);
	for(int i = 0; i < n; i++){
		printf("%d %d\n", ps[i].idx, ps[2*n-1-i].idx);
	}
	printf("\n");
}

/*
1  0 10
2  -2 1
3  4 10
4  11 20
5  7 -1
6  9 1
7  2 3
8  5 -2

8  5 -2
5  7 -1
2 -2  1
6  9  1
7  2  3
1  0 10
3  4 10
4 11 20


*/ 

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}