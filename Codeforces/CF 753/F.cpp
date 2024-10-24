#include <bits/stdc++.h>

#define N 2000
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
vector<pair<int,int>> g[N+1][N+1];
vector<pair<int,int>> gT[N+1][N+1];

int seen[N+1][N+1];

void reverseGraph(){
	for(int i  = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(pair<int,int> v : g[i][j]){
				gT[v.fi][v.se].push_back({i,j});
			}
		}
	}
}

stack<pair<int,int>> s;

void dfs(int i, int j){
	seen[i][j] = 1;

	for(pair<int,int> v : g[i][j]){
		if(!seen[v.fi][v.se]){
			dfs(v.fi, v.se);
		}
	}

	s.push({i, j});
}

int dfs2(int i, int j, int color){
	seen[i][j] = color;

	int r = 0;
	for(pair<int,int> v : gT[i][j]){
		if(!seen[v.fi][v.se]){
			r += dfs2(v.fi, v.se);
		}
		else if(seen[i][j] != seen[v.fi][v.se]){
			f[seen[v.fi][v.se]].push_back(seen[i][j]);
		}
	}

	return r+1;
}

struct nodo{
	int i, j;
	int size;
};

nodo info[(N+1)*(N+1)];

vector<int> f[(N+1)*(N+1)];

bool seenF[(N+1)*(N+1)];

int dfs3(int u){
	seenF[u] = true;

	int r = 0;
	for(int v : f[u]){
		if(!seenF[v]){
			r = max(r, dfs3(v));
		}
		else{
			r = max(r, )
		}
	}

	return r + info[u].size;
}


void solve(){
	
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; k++){
			char c;
			scanf(" %c", &c);
			if(c == 'U'){
				g[i][j].push_back({i-1,j});
			}
			if(c == 'R'){
				g[i][j].push_back({i,j+1});
				
			}
			if(c == 'D'){
				g[i][j].push_back({i+1,j});
				
			}
			if(c == 'L'){
				g[i][j].push_back({i,j-1});
		
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; k++){
			if(!seen[i][j]){
				dfs(i, j);
			}
		}
	}
	
	reverseGraph();

	memset(seen, 0, sizeof(seen));

	int c = 0;
	while(!s.emtpy()){
		int i = s.top().fi;
		int j = s.top().se;

		s.pop();

		if(!seen[i][j]){
			c++;
			info[c] = {i, j, dfs2(i,j,c)};
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; k++){
			if(!seen[i][j]){
				dfs(i, j);
			}
		}
	}

}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}

    return 0;

}