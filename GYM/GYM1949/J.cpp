#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

#define N 2500
#define M 50
char a[M+1][M+1];
char b[M+1][M+1];

// Seen:
bool seen[M+1][M+1];
// Discovery Time:
int tin[M+1][M+1];
// Lowest tin achivable by node v:
int low[M+1][M+1];
int ap[M+1][M+1];
int timer = 0;
int r, c;

bool is_inside(int i, int j){
	return (i < r and i >= 0 and j < c and j >= 0 and a[i][j] != 'X');
}

// O(N+M);
void tarjan(int i, int j, int pi, int pj){

	seen[i][j] = true;

	tin[i][j] = low[i][j] = timer++;

	int child = 0;

	int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
	cout << i << " " << j << endl;

	for(int d = 0; d < 4; d++){
		int ni, nj;
		ni = i + dir[d][0];
		nj = j + dir[d][1];


		if(!is_inside(ni,nj)) continue;
		if(ni == pi and nj == pj) continue;
		if(a[ni][nj] != '*') continue;
		
		if(!seen[ni][nj]){
			//parent[ni][nj] = u;
			child++;
			tarjan(ni, nj, i, j);
			low[i][j] = min(low[i][j], low[ni][nj]);

			// u is root with more than 1 child or there's no path from subtree of node v to u using back-edges.
			// so removing u is going to disconect v's subtree
			if(((pi == -1) and child >= 2) or ((pi != -1) and low[ni][nj] >= tin[i][j])){
				ap[i][j] = 1;
			}

		}// v is a back-edge:
		else{
			low[i][j] = min(tin[ni][nj], low[i][j]);
		}
	}
}


pair<int,int> whoremove(){
	memset(seen, 0, sizeof(seen));
	memset(tin, 0, sizeof(tin));
	memset(low, 0, sizeof(low));
	memset(ap, 0, sizeof(ap));
	timer = 0;

	cout << "WHO REMOVE: " << endl;

	int stop = 0;
	for(int i = 0; i < r and !stop; i++){
		for(int j = 0; j < c and !stop; j++){
			if(a[i][j] == '*'){
				tarjan(i,j, -1, -1);
				stop = 1;
			}
		}
	}
	
	for(int i = 0; i < r and !stop; i++){
		for(int j = 0; j < c and !stop; j++){
			if(a[i][j] == '*' and !ap[i][j]){
				return {i,j};
			}
		}
	}

	return {-1, -1};
}

pair<int,int> dfs(int i, int j){
	seen[i][j] = true;
	int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

	for(int d = 0; d < 4; d++){
		int ni, nj;
		ni = i + dir[d][0];
		nj = j + dir[d][1];

		if(!is_inside(ni,nj)) continue;
		if(b[ni][nj] == '*') return {ni,nj};
		

		if(!seen[ni][nj]){
			int ri, rj;
			tie(ri,rj) = dfs(ni,nj);
			if(ri != -1){
				if(a[i][j] == '.'){
					return {i,j};
				}
				return {ri,rj};
			}
		}
	}

	return {-1,-1};
}

pair<int,int> whoadd(){
	memset(seen, 0, sizeof(seen));
	int stop = 0;

	int ri = -1, rj = -1;

	for(int i = 0; i < r and !stop; i++){
		for(int j = 0; j < c and !stop; j++){
			if(a[i][j] == '*'){
				tie(ri, rj) = dfs(i,j);
				stop = 1;
			}
		}
	}

	return {ri, rj};
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> r >> c;

	int cnt = 0;

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> b[i][j];
			if(b[i][j] == '*' and a[i][j] == '.') cnt++;
		}
	}

	vector<tuple<int,int,int,int>> moves;

	while(cnt){
		int x1, y1, x2, y2;
		tie(x1,y1) = whoremove();
		tie(x2,y2) = whoadd();

		if(x2 == -1){
			cout << "NO" << endl;
			return 0;
		}

		cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

		if(b[x2][y2] == '*'){
			b[x2][y2] = '.';
			cnt--;
		}
		a[x1][y1] = '.';
		a[x2][y2] = '*';

		moves.push_back({x1,y1,x2,y2});
	}

	cout << "YES" << endl;
	cout << moves.size() << endl;
	for(auto [x1,y1,x2,y2] : moves){
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	}


}