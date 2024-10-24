#include <bits/stdc++.h>

#define N 505
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

vector<pair<int,int>> gv[N+1][N+1];
vector<pair<int,int>> gh[N+1][N+1];
int color[N+1][N+1];

void dfsv(int i, int j, int c){
	color[i][j] = c;
	//cout << i << " " << j << endl;
	for(auto [ni, nj] : gv[i][j]){
		if(color[ni][nj] == -1){
			dfsv(ni,nj,!c);
		}
	}
}
void dfsh(int i, int j, int c){
	color[i][j] = c;
	// cout << i << " " << j << endl;
	for(auto [ni, nj] : gh[i][j]){
		if(color[ni][nj] == -1){
			dfsh(ni,nj,!c);
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < max(n,m); i++){
		for(int j = 0; j < max(n,m); j++){
			gh[i][j].clear();
			gv[i][j].clear();
			color[i][j] = -1;
		}
	}

	vector<vector<char>> a(n, vector<char>(m));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}	

	vector<int> lc(n+1, -1);
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			if(a[i][j] == 'U'){
				gv[i][j].push_back({i+1,j});

				if(lc[i] != -1){
					gv[i][j].push_back({i, lc[i]});
					gv[i][lc[i]].push_back({i,j});
				}

				lc[i] = j;
			}
			if(a[i][j] == 'D'){
				gv[i][j].push_back({i-1,j});
				if(lc[i] != -1){
					gv[i][j].push_back({i, lc[i]});
					gv[i][lc[i]].push_back({i,j});
				}
				lc[i] = j;
			}
		}
	}

	vector<int> lr(m+1, -1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'L'){
				gh[i][j].push_back({i,j+1});

				if(lr[j] != -1){
					gh[i][j].push_back({lr[j], j});
					gh[lr[j]][j].push_back({i, j});
				}
				lr[j] = i;
			}
			if(a[i][j] == 'R'){
				gh[i][j].push_back({i,j-1});
				if(lr[j] != -1){
					gh[i][j].push_back({lr[j], j});
					gh[lr[j]][j].push_back({i, j});
				}
				lr[j] = i;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'U' and color[i][j] == -1){
				//cout << "!!! " << i << " " << j << endl;
				dfsv(i,j,0);
			}
			if(a[i][j] == 'L' and color[i][j] == -1){
				dfsh(i,j,0);
			}
		}
	}

	for(int i = 0; i < n; i++){
		int cnt = 0;
		for(int j = 0; j < m; j++){
			if(a[i][j] == '.') continue;
			if(color[i][j] == 1) cnt++;
			else if(color[i][j] == 0) cnt--;
		}
		if(cnt != 0){
			cout << -1 << endl;
			return;
		}
	}

	for(int j = 0; j < m; j++){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(a[i][j] == '.') continue;
			if(color[i][j] == 1) cnt++;
			else if(color[i][j] == 0) cnt--;
		}
		if(cnt != 0){
			cout << -1 << endl;
			return;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == '.') cout << ".";
			else if(color[i][j]) cout << "W";
			else cout << "B";
		}
		cout << endl;
	}
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