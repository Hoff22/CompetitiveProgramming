#include <bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int, int>> g[N+1];
bool inPath[N+1];
int dist[N+1];

struct state{
	int u;
	int dist;

	bool operator < (const state &b) const{
		return dist > b.dist;
	}
};

void dijkstra(int root){
	priority_queue<state> pq;

	memset(dist, INF, sizeof(dist));
	memset(inPath, 0, sizeof(inPath));

	dist[root] = 0;

	pq.push({root, dist[root]});

	while(!pq.empty()){
		int u = pq.top().u;
		pq.pop();

		if(!inPath[u]){

			inPath[u] = true;

			for(int i = 0 ; i < g[u].size(); i++){
				int v = g[u][i].first;
				int w = g[u][i].second;

				if(!inPath[v] and dist[u] + w < dist[v]){
					dist[v] = dist[u] + w;
					pq.push({v, dist[v]});
				}
			}
		}
	}
}

int main(){

	int n, m, a;

	scanf("%d%d%d", &n, &m, &a);

	for(int i = 1; i <= m; i++){
		int u, v, w;

		scanf("%d%d%d", &u, &v, &w);

		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	dijkstra(a);

	for(int i = 1; i <= n; i++){
		if(dist[i] == INF){
			printf("-1\n");
		}
		else{
			printf("%d\n", dist[i]);
		}
	}

	return 0;
}