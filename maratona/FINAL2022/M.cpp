#include <bits/stdc++.h>

#define N 1000
#define M 100
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
string h;
vector<string> g;
int seen[N+1][N+1];
vector<int> ofs;

int dir[4][2]{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

bool inside(int i, int j){
	return (i >= 0 and i <= n and j >= 0 and j < m);
}

bool test(int i , int r){
	for(int j = 0; j < m; j++){
		if(g[i][j] == '1' and h[(j+(m-r)) % m] == '1') return 0;
	}
	return 1;
}

void print(int r){
	for(int j = 0; j < m; j++){
		cout << h[(j+(m-r))%m];
	}
	cout << endl;
}

bool dfs(int i, int j){
	seen[i][j] = 1;
	if(i == n) return 1;
	// cout << i << " " << j << endl;
	int ans = 0;
	for(int d = 0; d < 4; d++){
		int ni = i + dir[d][0];
		int nj = (j + dir[d][1] + m) % m;

		if(!inside(ni, nj) or seen[ni][nj]) continue;

		int good = 1;
		for(int one : ofs){
			if(g[ni][(nj + one + m) % m] == '1') good = 0;
		}

		if(!good) continue;

		ans += dfs(ni, nj);
	}

	return ans;
}

bool dfs2(int i, int j){
	seen[i][j] = 1;
	if(i == n) return 1;
	// cout << i << " " << j << endl;
	int ans = 0;
	for(int d = 0; d < 4; d++){
		int ni = i + dir[d][0];
		int nj = (j + dir[d][1] + m) % m;

		if(!inside(ni, nj) or seen[ni][nj]) continue;

		int good = 1;
		for(int one : ofs){
			if(g[ni][(nj - one + m) % m] == '1') good = 0;
		}

		if(!good) continue;

		ans += dfs2(ni, nj);
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin >> n >> m;

	cin >> h;
	g.push_back("");
	for(int i = 0; i < 3*n; i++){
		g[0] += '0';
	}
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		g.push_back(s+s+s);
	}

	memset(seen, 0, sizeof(seen));

	int cur = 0;
	for(int i = 0; i < m; i++){
		if(h[i] == '1'){
			if(ofs.empty()){
				cur = 0;
			}
			ofs.push_back(cur);
		}
		cur++;
	}

	if(dfs(0,0)){
		cout << "Y\n";
		return 0;
	}

	memset(seen, 0, sizeof(seen));

	if(dfs2(0,0)){
		cout << "Y\n";
	}
	else{
		cout << "N\n";
	}
	
    return 0;

}