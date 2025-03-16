#include <bits/stdc++.h>

#define N 18
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

bool g[N][N];
int dp[(1 << N)];

int n , m;

int lsb(int mask) {
    return mask & (-mask);
}

bool dpClique[(1 << N)];
bool seenClique[(1 << N)];
bool isClique(int s){
	if(__builtin_popcount(s) == 1) return true;

	if(seenClique[s]) return dpClique[s];
	seenClique[s] = true;

	int i;
	for(i = 0; i < n; i++){
		if((s >> i) & 1){
			break;
		}
	}

	if(!isClique(s - (1 << i))){
		return dpClique[s] = false;
	}
	for(int j = 0; j < n; j++){
		if(i != j and (s>>j) & 1){
			if(!g[i][j]) return dpClique[s] = false;
		}
	}

	return dpClique[s] = true;
}

// int solve(int mask){
// 	if(isClique(mask)) return 1;

// 	if(dp[mask] != -1) return dp[mask];

// 	int r = INF;
// 	for(int s = (mask-1)&mask; s > 0; s = (s-1)&mask){
// 		r = min(solve(s) + solve(mask - s), r);
// 	}

// 	return dp[mask] = r;
// }

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 0 ; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		g[u][v] = g[v][u] = true;
	}

	memset(dp, 0x3f, sizeof(dp));

	for(int mask = 1; mask < (1 << n); mask++){
		if(isClique(mask)) {
			dp[mask] = 1;
			continue;
		}

		for(int s = (mask-1)&mask; s > 0; s = (s-1)&mask){
			dp[mask] = min(dp[s] + dp[mask - s], dp[mask]);
		}
	}

	printf("%d\n", dp[(1 << n)-1]);


	//printf("%d\n", solve((1 << n)-1));
    
    return 0;
}