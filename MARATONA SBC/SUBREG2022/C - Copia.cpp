#include <bits/stdc++.h>

#define N 1015
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

// cima baixo esquerda direita


int minX;
int maxX;
int minY;
int maxY;

vector<pair<int,int>> v[N+1];
vector<pair<int,int>> h[N+1];

int seen[N+1][N+1];

int dir[4][2] ={
	{0,-1},
	{0,1},
	{-1,0},
	{1,0}
};
bool inside(int x, int y){
	return y >= minY-1 and x >= minX-1 and y <= maxY and x <= maxX; 
}

int dfs(int x, int y){
	seen[x][y] = 1;
	int r = 1;
	int bad = 0;

	for(int d = 0; d < 4; d++){

		int nx, ny;
		
		if(d == 0){ // going up check line on current Y
			auto p = lower_bound(h[y].begin(), h[y].end(), make_pair(x,x));
			if(p != h[y].end() and p->first <= x and x < p->second) continue;
			if(p != h[y].begin()){
				p--;
				if(p->first <= x and x < p->second) continue;
			}
		}	
		if(d == 1){ // going down check line on Y+1
			auto p = lower_bound(h[y+1].begin(), h[y+1].end(), make_pair(x,x));
			if(p != h[y+1].end() and p->first <= x and x < p->second) continue;
			if(p != h[y+1].begin()){
				p--;
				if(p->first <= x and x < p->second) continue;
			}
		}
		if(d == 2){ // going left check line on current X
			auto p = lower_bound(v[x].begin(), v[x].end(), make_pair(y,y));
			if(p != v[x].end() and p->first <= y and y < p->second) continue;
			if(p != v[x].begin()){
				p--;
				if(p->first <= y and y < p->second) continue;
			}
		}
		if(d == 3){ // going right check line on X+1
			auto p = lower_bound(v[x+1].begin(), v[x+1].end(), make_pair(y,y));
			if(p != v[x+1].end() and p->first <= y and y < p->second)continue;
			if(p != v[x+1].begin()){
				p--;
				if(p->first <= y and y < p->second) continue;
			}
		}

		nx = x + dir[d][0];
		ny = y + dir[d][1];

		if(!inside(nx, ny)){
			bad = 1;
			continue;
		}

		if(seen[nx][ny]) continue;

		int nxt = dfs(nx, ny);
		if(nxt == -1) bad = 1;

		r += nxt;
	}

	if(bad) return -1;

	return r;
}

void pb(){
	for(int y = minY-1; y <= maxY; y++){
		for(int x = minX-1; x <= maxX; x++){
			if(seen[x][y]) cout << "#";
			else cout << ".";
		}
		cout << endl;
	}
	cout << endl;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;

	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			seen[i][j] = 0;
		}
	}

	int lasx, lasy;
	int curx, cury;
	cin >> lasx >> lasy;

	minX = lasx;
	maxX = lasx;
	minY = lasy;
	maxY = lasy;

	n--;
	while(n-- > -1){
		cin >> curx >> cury;

		minX = min(minX, curx);
		minY = min(minY, cury);

		maxX = max(maxX, curx);
		maxY = max(maxY, cury);

		if(curx == lasx){ // vertical line
			v[curx].push_back({min(cury, lasy), max(cury, lasy)});
		}
		else{ // horizontal line
			h[cury].push_back({min(curx, lasx), max(curx, lasx)});
		}

		lasx = curx;
		lasy = cury;
	}

	for(int i = 0; i <= N; i++){
		sort(v[i].begin(), v[i].end());
		sort(h[i].begin(), h[i].end());
	}

	int ans = 0;
	for(int y = minY-1; y <= maxY; y++){
		for(int x = minX-1; x <= maxX; x++){
			if(!seen[x][y]){
				ans = max(ans, dfs(x,y));
			}
		}
	}

	cout << ans << endl;

    return 0;

}