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
vector<int> p;

int dfs(int u){

	//printf("%d: %d\n", u, p[u]);
	for(int v : g[u]){
		//printf("\t%d\n", dfs(v));
		if(dfs(v) < p[u]) return 0;
	}

	return p[u];
}

bool comp(int i, int j){
	return (p[i] < p[j]);
}

void solve(){
	int n, k = 0;
	scanf("%d", &n);

	vector<int> v(n+1);
	vector<int> dist(n+1);
	vector<int> b(n+1);
	p.assign(n+1, 0);

	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	

	for(int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		b[i] = a;
		if(a == i) k = i;
		else{
			g[a].push_back(i);
		}
	}

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
		p[v[i]] = i;
	}

	if(!dfs(k)){
		printf("-1\n");
		return;
	}


	dist[v[1]] = 0;

	for(int i = 2; i <= n; i++){
		dist[v[i]] = dist[v[i-1]] + 1;
	}
	

	for(int i = 1; i <= n; i++){
		printf("%d ", dist[i] - dist[b[i]]);
	}
	printf("\n");

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