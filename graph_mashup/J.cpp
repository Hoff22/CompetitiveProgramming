#include <bits/stdc++.h>

#define N 100
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

int vis[N+1][N+1];
int g[N+1][N+1];
vector<int> moves;
int n, m;

int dir[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

bool inside(int i, int j){
	return (1 <= i and i <= n and 1 <= j and j <= m);
}

char mv[4] = {'U', 'D', 'L', 'R'};

int find_ex(int i, int j){
	vis[i][j] = 1;

	if(g[i][j] == 1) return 0;
	if(g[i][j] == 2) return 1;

	for(int k = 0; k < 4; k++){
		int ni, nj;
		ni = i+dir[k][0];
		nj = j+dir[k][1];

		if(!inside(ni, nj) or vis[ni][nj]) continue;

		if(find_ex(ni,nj)){
			moves.push_back(k);
			return 1;
		}
	}

	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
		string row;
		cin >> row;
    	for(int j = 1; j <= m; j++){
    		if(row[j-1] == '.') g[i][j] = 0;
    		if(row[j-1] == '*') g[i][j] = 1;
    		if(row[j-1] == 'F') g[i][j] = 2;
    	}
    }

    memset(vis, 0, sizeof(vis));
    moves.clear();

    find_ex(1,1);
    reverse(moves.begin(), moves.end());

    
    int LR = 0;
    int UD = 0;
    int i = 1;
    int j = 1;
    for(int q = 0; q < moves.size(); q++){

    	int ni, nj;

    	if(moves[q] < 2 and UD == 0){
    		cout << mv[moves[q]] << endl;
    		cout.flush();

    		cin >> ni >> nj;

    		if(i == ni and j == nj){
				swap(mv[0], mv[1]);
				q--;
				UD = 1;
    		}

    	}
    	else if(moves[q] >= 2 and LR == 0){
    		cout << mv[moves[q]] << endl;
    		cout.flush();

    		cin >> ni >> nj;

    		if(i == ni and j == nj){
				swap(mv[2], mv[3]);
				q--;
				LR = 1;
    		}
    	}
    	else{
    		cout << mv[moves[q]] << endl;
    		cin >> ni >> nj;
    	}

    	i = ni;
    	j = nj;
    }


    return 0;

}