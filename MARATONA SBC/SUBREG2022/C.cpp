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

int v[N+1][N+1];
int h[N+1][N+1];

int g[N+1][N+1][4];
int seen[N+1][N+1];

int dir[4][2] ={
	{0,-1},
	{0,1},
	{-1,0},
	{1,0}
};

int minX;
int maxX;
int minY;
int maxY;

bool inside(int x, int y){
	return y >= minY-1 and x >= minX-1 and y <= maxY and x <= maxX; 
}
 
int dfs(int x, int y){
	seen[x][y] = 1;
	int r = 1;
	int bad = 0;
	for(int d = 0; d < 4; d++){
 
 		if(g[x][y][d] == 0) continue;

		int nx, ny;
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

void printB(){
	for(int y = minY-1; y <= maxY; y++){
		for(int x = minX-1; x <= maxX; x++){
			if(seen[x][y]) cout << "#";
			else cout << ".";
			if(g[x][y][3] == 0) cout << "|";
			else cout << " ";
		}
		cout << endl;
		for(int x = minX-1; x <= maxX; x++){
			if(g[x][y][1] == 0){
				cout << "-";
				if(g[x+1][y][1] == 0) cout << "-";
				else cout << " ";
			}
			else cout << "  ";
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

	int cx,cy,lx,ly;
	cin >> lx >> ly;

	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			g[i][j][0] = g[i][j][1] = g[i][j][2] = g[i][j][3] = 1; 
			seen[i][j] = 0;
		}
	}

	minX = lx;
	maxX = lx;
	minY = ly;
	maxY = ly;

	for(int i = 0; i < n; i++){
		cin >> cx >> cy;
		if(lx == cx){
			v[cx][min(ly,cy)] += 1;
			v[cx][max(ly,cy)] -= 1;
		}
		if(ly == cy){
			h[cy][min(lx,cx)] += 1;
			h[cy][max(lx,cx)] -= 1;
		}

		minX = min(minX, cx);
		maxX = max(maxX, cx);
		minY = min(minY, cy);
		maxY = max(maxY, cy);

		lx = cx;
		ly = cy;
	}

	for(int y = 1; y <= 1000; y++){
		int cur = 0;
		for(int x = 0; x <= 1000; x++){
			cur += h[y][x];
			if(cur > 0){
				g[x][y  ][0] = 0;
				g[x][y-1][1] = 0;
			}
		}	
	}

	for(int x = minX; x <= maxX; x++){
		int cur = 0;
		for(int y = minY; y <= maxY; y++){
			cur += v[x][y];
			if(cur > 0){
				g[x  ][y][2] = 0;
				g[x-1][y][3] = 0;
			}
		}	
	}

	int ans = 0;
	for(int y = minY; y <= maxY; y++){
		for(int x = minX; x <= maxX; x++){
			if(!seen[x][y]){
				ans = max(ans, dfs(x,y));
			}
		}
	}
 
	cout << ans << endl;

    return 0;

}