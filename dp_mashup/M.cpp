#include <bits/stdc++.h>

#define N 5000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7)
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)


using namespace std;

int n, m, t;
long long dp[N+1][N+1];
vector<pair<int,long long>> g[N+1];

long long solve(int u, int s){
	if(s < 0){
		return 0x3f3f3f3f3f3f3f3f;
	}
	if(u == n){
		if(s == 0){
			return 0;
		}
		return 0x3f3f3f3f3f3f3f3f;
	}

	if(dp[u][s] != -1) return dp[u][s];

	long long r = 0x3f3f3f3f3f3f3f3f;
	for(auto e : g[u]){
		int v = e.fi;
		long long w = e.se;
		r = min(r, solve(v, s-1) + w);
	}

	return dp[u][s] = r;
}

void rec(int u, int s){
	
	if(u == n or s<=0){
		return;
	}

	int best = 0;	
	long long r = 0x3f3f3f3f3f3f3f3f;
	for(auto e : g[u]){
		int v = e.fi;
		long long w = e.se;
		if(r > solve(v, s-1) + w){
			best = v;
			r = solve(v, s-1) + w;
		}
	}

	printf("%d ", best);
	rec(best, s-1);

}

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	scanf("%d %d %d", &n, &m, &t);

	for(int i = 1; i <= m; i++){
		int u,v;
		long long w;
		scanf("%d %d %lld", &u,&v, &w);

		g[u].push_back({v,w});
	}
	int ans = 0;

	for(int i = N; i >= 1; i--){
		if(solve(1, i) <= t){
			ans = i;
			break;
		}
	}

	printf("%d\n", ans+1);
	printf("1 ");
	rec(1, ans);
	printf("\n");

    return 0;
}