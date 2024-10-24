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

pair<int,int> distX[N+1];
vector<int> g[N+1];
int distOne[N+1];
int seen[N+1];

set<int> s;

bool dfs(int u){
	seen[u] = 1;
	//printf("%d\n", u);

	if(distOne[u] >= distX[u].fi){
		s.insert(distX[u].se);
		return 0;
	}

	bool r = false;
	for(int v : g[u]){
		if(seen[v]) continue;
		r |= dfs(v);
	}

	return (r or (g[u].size() == 1 and u != 1));
}

void solve(){
	int n, k;
	scanf(" %d %d", &n, &k);

	for(int i = 0; i <= n; i++) g[i].clear();
	for(int i = 0; i <= n; i++) seen[i] = 0;
	for(int i = 0; i <= n; i++) distOne[i] = distX[i].fi = INF;
	s.clear();

	vector<int> x(k);
	for(int i = 0; i < k; i++) scanf(" %d", &x[i]);

	for(int i = 1; i < n; i++){
		int u,v;
		scanf(" %d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	queue<int> q;

	distOne[1] = 0;
	q.push(1);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v : g[u]){
			if(distOne[v] > distOne[u] + 1){
				distOne[v] = distOne[u] + 1;
				q.push(v);
			}
		}
	}

	for(int i = 0; i < k; i++){
		distX[x[i]].fi = 0;
		distX[x[i]].se = i;
		q.push(x[i]);
	}

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v : g[u]){
			if(distX[v].fi > distX[u].fi + 1){
				distX[v].fi = distX[u].fi + 1;
				distX[v].se = distX[u].se;
				q.push(v);
			}
		}
	}

	// for(int i = 1; i <= n; i++){
	// 	printf("%d ", distX[i].se);
	// }
	// printf("\n");

	// printf("friends needed:\n");
	// for(int i : s) printf("%d ", i);
	// printf("\n");

	if(dfs(1)){
		printf("-1\n");
	}
	else{
		printf("%d\n", ((int)s.size()));
	}
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