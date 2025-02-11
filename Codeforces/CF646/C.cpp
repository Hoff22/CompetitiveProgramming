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

vector<int> g[N+1];

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, x;
		scanf("%d %d", &n, &x);

		for(int i = 1; i <= n; i++) g[i].clear();

		for(int i = 0; i < n-1; i++){
			int u, v;
			scanf("%d %d", &u, &v);

			g[u].push_back(v);
			g[v].push_back(u);
		}

		if(g[x].size() <= 1 or n%2 == 0){
			printf("Ayush\n");
		}
		else printf("Ashish\n");
	}

    
    return 0;
}