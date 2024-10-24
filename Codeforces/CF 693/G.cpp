#include<bits/stdc++.h>

#define N 200000
#define INF 0x3f3f3f3f

using namespace std;

vector<int> g[N+1];
vector<int> inv[N+1];
int dist[N+1];
set<int> seen;
int n, m;

void bfs(int root){
	queue<int> q;
	seen.clear();
	q.push(root);
	seen.insert(root);
	dist[root] = -1;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		seen.insert(u);
		for(int v : g[u]){
			if(!seen.count(v)){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

void solve(){
	queue<int> q;
	seen.clear();
	q.push(1);
	seen.insert(1);
	dist[1] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		seen.insert(u);
		for(int v : inv[u]){
			if(!seen.count(v)){
				dist[v] = min(dist[u] + 1, dist[v] + 1);
				q.push(v);
			}
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &n, &m);

		for(int i = 1; i <= m; i++){
			int u, v;
			scanf("%d %d", &u, &v);

			g[u].push_back(v);
			inv[v].push_back(u);
		}

		bfs(1);
		solve();

		for(int i = 1; i <= n; i++){
			printf("%d ", dist[i]);
		}



	}

	return 0;
}