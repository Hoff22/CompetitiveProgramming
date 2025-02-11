#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int in[N+1];
int seen[N+1];
int d[N+1];
vector<int> g[N+1];
int n, x;

void dfs(int u){
	
	seen[u] = 1;

	for(int v : g[u]){
		if(in[v] > 1){
			in[v]--;
			d[v] += d[u] + 1;
		}
		if(!seen[v] and in[v] == 1){
			dfs(v);
		}
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d %d", &n, &x);

		memset(seen, 0, sizeof(seen));
		memset(in, 0, sizeof(in));

		for(int i = 0; i < n-1; i++){
			int u, v;
			scanf("%d %d", &u, &v);

			in[u]++;
			in[v]++;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		for(int u = 1; u <= n; u++){
			if(!seen[u] and in[u] == 1){
				dfs(u);
			}
		}

		if(d[x]%2) printf("Ashish\n");
		else printf("Ayush\n");
	}

    
    return 0;
}