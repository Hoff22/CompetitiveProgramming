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
int a[N+1][N+1];
int dist[N+1][N+1];

bool seen[N+1][N+1];

int dir[4][2] = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int valid(int i, int j){
	return (i >= 0 and i < n and j >= 0 and j < m and a[i][j] != 1);
}

int bfs(int ri, int rj){
	
	int t[N+1][N+1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			t[i][j] = INF;
		}
	}
	
	queue<pair<int,int>> fila;
	fila.push({ri, rj});
	t[ri][rj] = 0;

	while(!fila.empty()){
        int i = fila.front().fi;
        int j = fila.front().se;
        fila.pop();
        	
        //printf("%d %d\n", i, j);   

        for(int d = 0; d < 4; d++){
			int ni = dir[d][0] + i;
			int nj = dir[d][1] + j;
			//printf(" \t%d %d %d %d\n", ni, nj, dist[ni][nj], a[ni][nj]);
			if(valid(ni, nj) and t[ni][nj] > t[i][j] + 1 and t[i][j] + 1 < dist[ni][nj]){
				t[ni][nj] = t[i][j] + 1;
                fila.push({ni,nj});
			}
		}
    }

 //    for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		if(t[i][j] == INF){
	// 			printf("\tx");
	// 		}
	// 		else{
	// 			printf("\t%d",t[i][j]);
	// 		}

	// 	}
	// 	printf("\n");
	// }

	int r = INF;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 or i == n-1 or j == 0 or j == m-1){
				r = min(r, t[i][j]);
			}
		}
	}

	if(r == INF) return INF;
	return r+1;
}

void solve(){
	scanf("%d %d", &m, &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			dist[i][j] = INF;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			seen[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			a[i][j] = 0;
		}
	}

	queue<pair<int,int>> fila;
	
	int bi, bj;
	bi = bj = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			scanf(" %c", &c);

			if(c == '#'){
				a[i][j] = 1;
			}
			else if(c == '*'){
				a[i][j] = 2;
				fila.push({i, j});
				dist[i][j] = 0;
			}
			else if(c == '@'){
				a[i][j] = 3;
				bi = i;
				bj = j;
			}
		}
	}

    while(!fila.empty()){
        int i = fila.front().fi;
        int j = fila.front().se;
        fila.pop();
        	
        //printf("%d %d\n", i, j);   

        for(int d = 0; d < 4; d++){
			int ni = dir[d][0] + i;
			int nj = dir[d][1] + j;
			//printf(" \t%d %d %d %d\n", ni, nj, dist[ni][nj], a[ni][nj]);
			if(valid(ni, nj) and dist[ni][nj] > dist[i][j] + 1){
				dist[ni][nj] = dist[i][j] + 1;
                fila.push({ni,nj}); 
			}
		}
    }

 //    for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		if(dist[i][j] == INF){
	// 			printf("\tx");
	// 		}
	// 		else{
	// 			printf("\t%d",dist[i][j]);
	// 		}

	// 	}
	// 	printf("\n");
	// }

	int ans = bfs(bi, bj);

	if(ans == INF){
		printf("IMPOSSIBLE\n");
	}
	else{
		printf("%d\n", ans);
	}
}

int main(){
	
	int q;
	scanf("%d",&q);
	while(q--){
		solve();
	}

    return 0;

}