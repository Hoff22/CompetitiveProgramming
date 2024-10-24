#include <bits/stdc++.h>

#define N 2000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF LLONG_MAX
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N+1][N+1];
long long dist[N+1][N+1]; // 16 megabytes
bool seen[N+1][N+1];
int n, m, w;
long long pI = INF;
long long pO = INF;
long long ans = INF;

long long bfs(){
	queue<pair<int,int>> q;
	int i, j, x, y;

	bool p1,p2,p;
	p1 = p2 = p = false;

	dist[1][1] = 0;
	seen[1][1] = true;
	if(a[1][1] > 0) pI = min(pI, 1ll*a[1][1]);
	q.push({1,1});
	while(!q.empty()){
		i = q.front().first; 
		j = q.front().second;
		q.pop();

		if(a[i][j] > 0) p1 = true;

		for(x = -1; x <= 1; x++){
			for(y = -1; y <= 1; y++){
				if((x==0 or y==0) and i+x > 0 and i+x <= n and j+y > 0 and j+y <= m){
					if(!seen[i+x][j+y] and a[i+x][j+y] != -1){
						seen[i+x][j+y] = true;
						dist[i+x][j+y] = dist[i][j] + w;
						if(a[i+x][j+y] > 0) pI = min(pI, dist[i+x][j+y] + a[i+x][j+y]);
						q.push({i+x, j+y});
					}
				}
			}
		}
	}

	if(seen[n][m]) p = true;
	ans = dist[n][m];

	memset(seen, 0, sizeof(seen));
	dist[n][m] = 0;
	seen[n][m] = true;
	if(a[n][m] > 0) pO = min(pO, 1ll*a[n][m]);
	q.push({n,m});
	while(!q.empty()){
		i = q.front().first; 
		j = q.front().second;
		q.pop();

		if(a[i][j] > 0) p2 = true;
		
		for(x = -1; x <= 1; x++){
			for(y = -1; y <= 1; y++){
				if((x==0 or y==0) and i+x > 0 and i+x <= n and j+y > 0 and j+y <= m){
					if(!seen[i+x][j+y] and a[i+x][j+y] != -1){
						seen[i+x][j+y] = true;
						dist[i+x][j+y] = dist[i][j] + w;
						if(a[i+x][j+y] > 0) pO = min(pO, dist[i+x][j+y] + a[i+x][j+y]);
						q.push({i+x, j+y});
					}
				}
			}
		}
	}

	if(p or (p1 and p2)){
		if(p1 and p2){
			return min(ans, pI + pO);
		}
		return ans;
	}
	return -1;
}

int main(){
	
	scanf("%d %d %d", &n, &m, &w);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=m; j++){
			dist[i][j] = INF;
		}
	}

	printf("%lld\n", bfs());

    return 0;
}