#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)


using namespace std;

int n, k;
int t[N+1];
pair<int,int> g[N+1];
int dp[N+1][N+1];


int g_idx[N+1];
int t_idx[N+1];

vector<pair<int,int>> ans;

int solve(int i, int j){
	if(i > n or j > k) return 0;

	if(dp[i][j] != -1) return dp[i][j]; 

	if(t[t_idx[j]] >= g[g_idx[i]].fi){
		return dp[i][j] = max(solve(i+1, j), solve(i+1,j+1) + g[g_idx[i]].se);
	}
	return dp[i][j] = max(solve(i+1, j), solve(i, j+1));
}

void rec(int i, int j){


	if(i > n or j > k) return;

	if(t[t_idx[j]] >= g[g_idx[i]].fi){
		if(solve(i+1, j) > solve(i+1,j+1) + g[g_idx[i]].se){
			rec(i+1, j);
		}
		else{
			ans.push_back({g_idx[i], t_idx[j]});
			rec(i+1, j+1);
		}
		return;
	}
	if(solve(i+1, j) > solve(i, j+1)){
		rec(i+1, j);
	}
	else{
		rec(i, j+1);
	}

}

bool mysortG(int a, int b){
	if(g[a].fi == g[b].fi) return g[a].se < g[b].se;
	return g[a].fi < g[b].fi;
}
bool mysortT(int a, int b){
	return t[a] < t[b];
}


int main(){
	
	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int c,p;
		scanf("%d %d", &c, &p);
		g[i] = {c,p};
		g_idx[i] = i;
	}

	scanf("%d", &k);
	for(int i = 1; i <= k; i++){ scanf("%d", &t[i]); t_idx[i] = i;}

	sort(t_idx+1, t_idx+k+1, mysortT);
	sort(g_idx+1, g_idx+n+1, mysortG);

	solve(1,1);
	rec(1,1);

	printf("%d %d\n", (int)ans.size(), solve(1,1));

	for(auto p : ans){
		printf("%d %d\n", p.fi, p.se);
	}

    return 0;
}