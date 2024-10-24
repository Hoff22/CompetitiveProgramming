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

char c[N+1];
vector<int> g[N+1];

int l_find(int u, int p, int l, char ch){
	if(c[u] == ch) l = u;
}

int paliSize(int l, int r){

	if(l == r) return 1;



}

int dfs(int u, int p, int l){



}

void solve(){
	memset(cnt, 0, sizeof(cnt));

	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scnaf(" %c", &c[i]);
		g[u].clear();
	}

	for(int i = 1; i < n; i++){
		int u, v;
		scanf(" %d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	depth[0] = 0;
	pop_count(1, 1);

	printf("%d\n", dfs(1,1));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}