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

int n, m;
vector<vector<int>> seg;
vector<vector<int>> a;

void build_y(int curx, int cury, int xi, int yi, int xf, int yf){
	int my = (yi + yf)/2;

	if(yi == yf){ // fixed y

		if(xi == xf){
			seg[curx][cury] = a[yi][xi];
		}
		else{
			seg[curx][cury] = min(seg[LEFT(curx)][cury], seg[RIGHT(curx)][cury]);
		}

		return;
	}

	build_y(curx, LEFT(cury), xi, yi, xf, my);
	build_y(curx, RIGHT(cury), xi, my+1, xf, yf);

	seg[curx][cury] = min(seg[curx][LEFT(cury)], seg[curx][RIGHT(cury)]);
}

void build_x(int curx, int xl, int xr){
	int mx = (xl + xr) / 2;


	if(xl != xr){
		build_x(LEFT(curx), xl, mx);
		build_x(RIGHT(curx), mx+1, xr);
	}

	build_y(curx, 1, xl, 1, xr, n); // build the y axis from 1 to n
}

int query_y(int curx, int cury, int yl, int yr, int yi, int yf){
	int my = (yl + yr) / 2;

	if(yr < yi or yf < yl){
		return INF;
	}

	if(yi <= yl and yr <= yf){
		return seg[curx][cury];
	}

	int nyl = query_y(curx, LEFT(cury), yl, my, yi, yf);
	int nyr = query_y(curx, RIGHT(cury), my+1, yr, yi, yf);

	return min(nyl, nyr);
}

int query_x(int curx, int xl, int xr, int xi, int yi, int xf, int yf){
	int mx = (xl + xr) / 2;

	if(xr < xi or xf < xl){
		return INF;
	}

	if(xi <= xl and xr <= xf){
		return query_y(curx, 1, 1, n, yi, yf);
	}

	int nxl = query_x(LEFT(curx), xl, mx, xi, yi, xf, yf);
	int nxr = query_x(RIGHT(curx), mx+1, xr, xi, yi, xf, yf);

	return min(nxl, nxr);
}

void solve(){
	scanf("%d %d", &n, &m);

	a.assign(n+1, vector<int>(m+1, 0));
	seg.assign(4*m+1, vector<int>(4*n+1, 0));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
		}
	}

	build_x(1, 1, m);

	int l = 1;
	int r = 1000;
	int ans = 0;

	while(l <= r){
		int mid = (l+r) / 2;

		bool found = 0;
		for(int y = 1; y <= n-mid+1; y++){
			for(int x = 1; x <= m-mid+1; x++){
				if(query_x(1, 1, m, x, y, x+mid-1, y+mid-1) >= mid){
					ans = mid;
					l = mid + 1;
					found  = true;
					break;
				}
			}
			if(found) break;
		}
		if(!found) r = mid - 1;
	}

	printf("%d\n", ans);
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