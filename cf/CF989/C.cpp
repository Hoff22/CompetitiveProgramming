#include <bits/stdc++.h>

#define N 1000
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

vector<int> dir[4] = {
	{0,-1},
	{0,1},
	{-1,0},
	{1,0}
};

map<char,int> cd{
	{'?', -1},
	{'L', 0},
	{'R', 1},
	{'U', 2},
	{'D', 3}
};

bool inside(int i, int j){
	return (i >= 0 and i < n and j >= 0 and j < m);
}

int a[N+1][N+1];
int col[N+1][N+1];

void dfs(int i, int j){
	// cout << "> " << i << " " << j << endl;
	col[i][j] = 1;

	if(a[i][j] == -1){
		for(int d = 0; d < 4; d++){
			int ni = i + dir[ d ][0];
			int nj = j + dir[ d ][1];

			if(!inside(ni,nj)) continue;

			if(col[ni][nj] == 0) dfs(ni,nj);
			
			if(col[ni][nj] == 3){
				a[i][j] = d;
				col[i][j] = 3;
				return;
			}
		}

		a[i][j] = 0;
		col[i][j] = 2;
		return;
	}


	int ni = i + dir[ a[i][j] ][0];
	int nj = j + dir[ a[i][j] ][1];

	if(!inside(ni,nj)){
		col[i][j] = 2;
		return;
	}

	if(col[ni][nj] == 0) dfs(ni,nj);
	else if(col[ni][nj] == 1){
		col[i][j] = 3;
		return;
	}
	
	col[i][j] = col[ni][nj];
}

void printt(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			switch(a[i][j]){
			case -1:
				cout << '?';
				break;
			case 0:
				cout << 'L';
				break;
			case 1:
				cout << 'R';
				break;
			case 2:
				cout << 'U';
				break;
			case 3:
				cout << 'D';
			default:
				break;
			}
		}
		cout << endl;
	}

	cout << endl;
}

void solve(){

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			a[i][j] = cd[c];
			col[i][j] = 0;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == -1){
				for(int d = 0; d < 4; d++){
					int ni = i + dir[d][0];
					int nj = j + dir[d][1];
					if(!inside(ni,nj)) continue;

					if(a[ni][nj] == -1){
						a[i][j] = d;
						break;
					}

					if(ni + dir[a[ni][nj]][0] == i and nj + dir[a[ni][nj]][1] == j){
						a[i][j] = d;
						break;
					}
				}
			}
		}
	}

	// printt();

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(col[i][j] == 0){
				// cout << "dfs: " << i << " " << j << endl;
				dfs(i,j);
			}
		}
	}

	int ans = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans += (col[i][j] == 3);
		}
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}