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

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int u,v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(g[i].size() == 1) cnt++;
	}

	printf("%d\n", (cnt+1)/2);
	
    return 0;

}