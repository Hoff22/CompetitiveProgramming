#include <bits/stdc++.h>

#define N 200000
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

vector<int> g[N+1];
pair<int,int> best[N+1];

int solve(int k){
	if(k >= n){
		return 0;
	}

	if(best[best[k].fi].se > k){
		
	}

	return 1 + min(solve(), solve(k+k));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, m;
	int q;
	scanf("%d %d %d", &n, &m, &q);

	for(int i = 0; i < q; i++){
		int u, v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	best[1].fi = 1+1;
	for(int v : g[1]) if(v == 1) best[1].fi++;
	best.se = 1;

	for(int i = 2; i <= max(n,m); i++){
		best[i] = max(min(n,i)+min(m,i), best[i-1]);

		if(best[i].fi <= min(n,i)+min(m,i)){
			best[i].fi = min(n,i)+min(m,i);
			best[i].se = max(min(n,i), min(m,i));
		}

		for(int j : g[i]){
			if(j < i and best[i].fi <= i+j+1){
				best[i].fi = i+j+1;
				best[i].se = max(i, j);
			}
		}

	}

	for(int i = 1; i <= max(n,m); i++){
		printf("%d ", best[i].se);
	}
	printf("\n");

	printf("%d\n", solve(1));
   
    return 0;

}