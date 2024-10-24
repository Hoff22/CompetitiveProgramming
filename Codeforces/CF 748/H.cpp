#include <bits/stdc++.h>
 
#define N 400000
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
 
int n, k;
int sz[N+1];
int dist[N+1];
vector<int> g[N+1];
 
void solve(){
	scanf(" %d %d", &n, &k);
 
	for(int i = 1; i <= n; i++){
		g[i].clear();
		sz[i] = 0;
	}
 
	for(int i = 0; i < n-1; i++){
		int u,v;
		scanf(" %d %d", &u, &v);
 
		g[u].push_back(v);
		g[v].push_back(u);
		sz[u]++;
		sz[v]++;
	}
 
	queue<int> q;

	memset(dist, 0x3f, sizeof(dist));
 
	for(int i = 1; i <= n ; i++){
		if(sz[i] <= 1){
			dist[i] = 0;
			q.push(i);
		}
	}

	while(!q.empty()){

		int u = q.front();
		q.pop();

		for(int v : g[u]){
			if(sz[v] <= 1) continue;

			sz[v]--;
			
			if(sz[v] <= 1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
 
	int ans = 0;

	for(int u = 1; u <= n; u++){
		//printf("%d %d\n", u, dist[u]);
		if(dist[u] >= k) ans++;
	}

	printf("%d\n", ans);
}
 
int main(){
	
	int t;
	scanf(" %d", &t);
	
	while(t--){
		solve();
	}
    return 0;
 
}