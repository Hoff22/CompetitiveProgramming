#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

constexpr int N = 1000;
constexpr int M = 1000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;

typedef long long ll;

int dir[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

int n, m;
int a[N+1][N+1];

void dfs(int i, int j){
	a[i][j] = 1;

	for(int d = 0; d < 4; d++){
		int ni, nj;
		ni = i + dir[d][0];
		nj = j + dir[d][1];

		if(ni >= 0 and ni < n and nj >= 0 and nj < m){
			if(!a[ni][nj]) dfs(ni, nj);
		}
	}
}

void solve(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			a[i][j] = (int)(c=='#');
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!a[i][j]){
				ans++;
				dfs(i, j);
			}
		}
	}

	cout << ans << endl;
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