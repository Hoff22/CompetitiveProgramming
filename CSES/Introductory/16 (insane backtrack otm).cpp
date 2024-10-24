#include <bits/stdc++.h>

#define N 7
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


int dir[4][2] ={
	{-1,0},	// 00
	{1,0},	// 11
	{0,-1},	// 10
	{0,1}	// 01
};

int seen[N+1][N+1];
string s;

bool inside(int i, int j){
	return (i >= 0 and i < N and j >= 0 and j < N);
}

int bt(int i, int j, int q, int last){
	if(i == 6 and j == 0){
		return (q == 49);
	}
	if(q == 49) return 0;

	int res = 0;

	if(s[q-1] == 'U'){
		int d = 0;
		int ni = i+dir[d][0];
		int nj = j+dir[d][1];

		if(!inside(ni, nj) or seen[ni][nj]) return 0;

		seen[ni][nj] = 1;
		res += bt(ni, nj, q+1, d);
		seen[ni][nj] = 0;
		return res;
	}
	if(s[q-1] == 'D'){
		int d = 1;
		int ni = i+dir[d][0];
		int nj = j+dir[d][1];

		if(!inside(ni, nj) or seen[ni][nj]) return 0;

		seen[ni][nj] = 1;
		res += bt(ni, nj, q+1, d);
		seen[ni][nj] = 0;
		return res;
	}
	if(s[q-1] == 'L'){
		int d = 2;
		int ni = i+dir[d][0];
		int nj = j+dir[d][1];

		if(!inside(ni, nj) or seen[ni][nj]) return 0;

		seen[ni][nj] = 1;
		res += bt(ni, nj, q+1, d);
		seen[ni][nj] = 0;
		return res;
	}
	if(s[q-1] == 'R'){
		int d = 3;
		int ni = i+dir[d][0];
		int nj = j+dir[d][1];

		if(!inside(ni, nj) or seen[ni][nj]) return 0;

		seen[ni][nj] = 1;
		res += bt(ni, nj, q+1, d);
		seen[ni][nj] = 0;
		return res;
	}

	if(last == 0 and !(inside(i+dir[0][0], j+dir[0][1]) and !seen[i+dir[0][0]][j+dir[0][1]]) and (inside(i+dir[2][0], j+dir[2][1]) and !seen[i+dir[2][0]][j+dir[2][1]]) and (inside(i+dir[3][0], j+dir[3][1]) and !seen[i+dir[3][0]][j+dir[3][1]])) return 0;
	if(last == 1 and !(inside(i+dir[1][0], j+dir[1][1]) and !seen[i+dir[1][0]][j+dir[1][1]]) and (inside(i+dir[2][0], j+dir[2][1]) and !seen[i+dir[2][0]][j+dir[2][1]]) and (inside(i+dir[3][0], j+dir[3][1]) and !seen[i+dir[3][0]][j+dir[3][1]])) return 0;
	if(last == 2 and !(inside(i+dir[2][0], j+dir[2][1]) and !seen[i+dir[2][0]][j+dir[2][1]]) and (inside(i+dir[0][0], j+dir[0][1]) and !seen[i+dir[0][0]][j+dir[0][1]]) and (inside(i+dir[1][0], j+dir[1][1]) and !seen[i+dir[1][0]][j+dir[1][1]])) return 0;
	if(last == 3 and !(inside(i+dir[3][0], j+dir[3][1]) and !seen[i+dir[3][0]][j+dir[3][1]]) and (inside(i+dir[0][0], j+dir[0][1]) and !seen[i+dir[0][0]][j+dir[0][1]]) and (inside(i+dir[1][0], j+dir[1][1]) and !seen[i+dir[1][0]][j+dir[1][1]])) return 0;

	for(int d = 0; d < 4; d++){
		int ni = i+dir[d][0];
		int nj = j+dir[d][1];

		if(!inside(ni, nj) or seen[ni][nj]) continue;

		seen[ni][nj] = 1;
		res += bt(ni, nj, q+1, d);
		seen[ni][nj] = 0;
	}

	return res;
}

// ????????????????????????????????????????????????
// D???????????????????????????????????????????????
// ??????R??????U??????????????????????????LD????D?

void solve(){
	cin >> s;

	seen[0][0] = 1;
	cout << bt(0,0,1,2) << endl;
}

int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	while(t--){
		solve();
	}
    return 0;

}