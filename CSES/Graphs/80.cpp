#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int N = 1000;
constexpr int M = 200000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;

typedef long long ll;

int n, m;
char a[N+1][N+1];


void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	vector<vector<int>> dm(n, vector<int>(m,0x3f3f3f3f));
	vector<vector<int>> dx(n, vector<int>(m,0x3f3f3f3f));
	vector<vector<tuple<int,int,char>>> parent(n, vector<tuple<int,int,char>>(m));

	int dir[4][2] = {
		{-1,0},
		{0,-1},
		{1, 0},
		{0, 1}
	};
	char dirc[4] = {'U', 'L', 'D', 'R'};

	auto inside = [&](int ni, int nj){ return (ni >= 0 and ni < n and nj >= 0 and nj < m and a[ni][nj] != '#');};

	queue<pair<int,int>> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'M'){
				dm[i][j] = 0;
				q.push({i,j});
			}
		}
	}

	while(q.size()){
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for(int d = 0; d < 4; d++){
			int ni = i + dir[d][0];
			int nj = j + dir[d][1];

			if(!inside(ni, nj)) continue;

			if(dm[ni][nj] > dm[i][j] + 1){
				dm[ni][nj] = dm[i][j] + 1;
				q.push({ni,nj});
			}
		}
	}

	// ------------------------------------------------------------------

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'A'){
				dx[i][j] = 0;
				q.push({i,j});
			}
		}
	}

	while(q.size()){
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for(int d = 0; d < 4; d++){
			int ni = i + dir[d][0];
			int nj = j + dir[d][1];

			if(!inside(ni, nj)) continue;

			if(dx[ni][nj] > dx[i][j] + 1){
				dx[ni][nj] = dx[i][j] + 1;
				parent[ni][nj] = {i,j,dirc[d]};
				q.push({ni,nj});
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 or j == 0 or i == n-1 or j == m-1){
				if(inside(i,j) and dm[i][j] > dx[i][j]){

					cout << "YES" << endl;
					cout << dx[i][j] << endl;

					int ci = i;
					int cj = j;
					char mov;

					string ans = "";

					while(a[ci][cj] != 'A'){
						tie(ci, cj, mov) = parent[ci][cj];
						ans += mov;
					}

					reverse(ans.begin(), ans.end());

					if(ans.size()) cout << ans << endl;

					return;
				}
			}
		}
	}

	cout << "NO" << endl;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}
