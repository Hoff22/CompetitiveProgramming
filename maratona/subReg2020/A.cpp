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

// k + 1 = TOP
// k + 2 = RIGHT
// k + 3 = BOT
// k + 4 = LEFT

int s[N+1][3];
vector<int> g[N+7];
bool seen[N+1];
bool walls[4];
int m,n;

void dfs(int u){
	seen[u] = true;

	if(s[u][0] <= s[u][2]){

		walls[3] = true;

	}
	if(m - s[u][0] <= s[u][2]){

		walls[1] = true;

	}
	if(s[u][1] <= s[u][2]){

		walls[0] = true;

	}
	if(n - s[u][1] <= s[u][2]){

		walls[2] = true;

	}

	for(int i : g[u]){
		if(!seen[i]){
			dfs(i);
		}
	}
}

int main(){
	
	int k;

	scanf("%d %d %d", &m, &n, &k);

	for(int i = 0; i < k; i++){
		scanf("%d %d %d", &s[i][0], &s[i][1], &s[i][2]);
	}

	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			if(j == i) continue;

			if(abs(s[i][0] - s[j][0]) * abs(s[i][0] - s[j][0]) + abs(s[i][1] - s[j][1]) * abs(s[i][1] - s[j][1]) <=	(s[i][2] + s[j][2]) * (s[i][2] + s[j][2])){

				g[i].push_back(j);

			}
		}
	}

	for(int i = 0; i < k; i++){
		memset(seen, 0, sizeof(seen));
		memset(walls, 0, sizeof(walls));
	
		dfs(i);

		if((walls[0] and walls[2]) or
			(walls[0] and walls[3]) or 
			(walls[1] and walls[2]) or
			(walls[1] and walls[3])){

			printf("N\n");
			return 0;
		}
	}

	printf("S\n");


    return 0;

}