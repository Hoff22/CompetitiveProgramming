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
	{-1, 0},
	{1, 0},
	{0,-1},
	{0, 1}
};

int n, m, k;

int dfs(int i, int j, vector<vector<int>>& v, vector<vector<int>>& s, int q){
	if(i == n-1 and j == m-1) return 1;

	s[i][j] = 1;

	for(int d = 0; d < 4; d++){
		int ni = i + dir[d][0];
		int nj = j + dir[d][1];

		if(ni >= 0 and ni < n and nj >= 0 and nj < m and !s[ni][nj] and q >= v[ni][nj]){
			if(dfs(ni,nj,v,s,q)) return 1;
		}
	}

	return 0;
}

void solve(){
	cin >> n >> m >> k;
	
	vector<vector<int>> v(n, vector<int>(m, INF));
	vector<vector<int>> s(n, vector<int>(m, 0));

	queue<pair<int,int>> q;

	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		v[x][y] = 0;
		q.push({x,y});
	}


	while(q.size()){
		int i = q.front().fi;
		int j = q.front().se;
		q.pop();


		if(s[i][j]) continue;
		s[i][j] = 1;

		for(int d = 0; d < 4; d++){
			int ni = i + dir[d][0];
			int nj = j + dir[d][1];

			if(ni >= 0 and ni < n and nj >= 0 and nj < m and v[ni][nj] > v[i][j]){
				v[ni][nj] = v[i][j] + 1;
				q.push({ni,nj});
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			s[i][j] = 0;
		}
	}

	int l = 0;
	int r = 2000000;
	int ans = INF;

	while(l <= r){
		int mid = (l + r) / 2;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				s[i][j] = 0;
			}
		}
		if(dfs(0,0,v,s,mid)){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}

	cout << ans << endl;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}