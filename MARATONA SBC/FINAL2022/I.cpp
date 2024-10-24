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

int n, m;
int a[N+1][N+1];
int seen[N+1][N+1];
int seen2[N+1][N+1];

int dir[4][2]{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

bool inside(int i, int j){
	return (i >= 0 and i < n and j >= 0 and j < m);
}

int bfs(int ri, int rj){

	memset(seen, 0, sizeof(seen));
	int min_d = 0;

	set<tuple<int,int,int>> q;

	q.insert(make_tuple(a[ri][rj], ri, rj));

	int ans = 0;

	while(!q.empty()){
		int i, j, cur;

		do{
			tie(cur, i, j) = (*q.begin());
			q.erase(make_tuple(cur, i, j));
		}while(!q.empty() and cur < min_d);

		if(cur < min_d) break;

		min_d = cur;
		seen[i][j] = 1;
		seen2[i][j] = 1;
		ans++;

		for(int d = 0; d < 4; d++){
			int ni, nj;
			ni = i + dir[d][0];
			nj = j + dir[d][1];

			if(inside(ni,nj) and !seen[ni][nj]){
				q.insert(make_tuple(a[ni][nj], ni, nj));
			}
		}
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin >> n >> m;
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> a[i][j];
    	}
    }
    memset(seen2, 0, sizeof(seen2));
    int ans = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(seen2[i][j]) continue;
    		ans = max(ans, bfs(i, j));
    	}
    }

	
    cout << ans << endl;

    return 0;

}