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

char dirc[4] = {
	'U',
	'D',
	'L',
	'R'
};

int n, m;
char a[N+1][N+1];
tuple<int,int,char> p[N+1][N+1];

void solve(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			p[i][j] = {-1,-1,' '};
		}
	}

	queue<pair<int,int>> q;

	pair<int,int> ex;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'A'){
				q.push({i,j});
				p[i][j] = {0, -1, ' '};
			}
			if(a[i][j] == 'B'){
				ex = {i,j};
			}
		}
	}

	while(q.size()){
		int i = q.front().fi;
		int j = q.front().se;
		q.pop();

		for(int d = 0; d < 4; d++){
			int ni, nj;
			ni = i + dir[d][0];
			nj = j + dir[d][1];
	 
			//cout << i << " " << j << ": " << ni << "," << nj << endl;

			if(ni >= 0 and ni < n and nj >= 0 and nj < m and a[ni][nj] != '#'){
				if(get<0>(p[ni][nj]) == -1){
					p[ni][nj] = {i, j, dirc[d]};
					q.push({ni,nj});
				}
			}
		}
	}

	if(get<0>(p[ex.fi][ex.se]) != -1){
		vector<char> ans;
		int i = ex.fi;
		int j = ex.se;
		while(a[i][j] != 'A'){
			ans.push_back(get<2>(p[i][j]));
			int ni = get<0>(p[i][j]);
			int nj = get<1>(p[i][j]);
			i = ni;
			j = nj;
		}
		reverse(ans.begin(), ans.end());
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for(char c : ans) cout << c;
		cout << endl;
	}
	else{
		cout << "NO" << endl;
	}
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