#include <bits/stdc++.h>

#define N 1000
#define MAX 10000000000
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

struct State {
	int u, d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

vector<pair<int, int>> g[N + 1]; // (Input)
priority_queue<State> pq;
bool in_spt[N + 1];
int dist[N + 1];
int n, m; 

/* O(E + E * Log(V)). */
void dijkstra(int u) {
	// Initializing.
	memset(in_spt, false, sizeof(in_spt));
	memset(dist, 0x3f, sizeof(dist));

	// Initializing and pushing source vertex. Cost of adding the first vertex u to Shortest Path Tree is 0.
	dist[u] = 0;
	pq.push({u, 0});

	// While there are vertices to visit.
	while (!pq.empty()) {
		// Retrieving vertex u from current State.
		u = pq.top().u;
		pq.pop();

		// If vertex u still doesn't belong to Shortest Path Tree.
		if (!in_spt[u]) {
			// Vertex u now belongs to Shortest Path Tree.
			in_spt[u] = true;

			// For every vertex v adjacent to u.
			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].first;
				int w = g[u][i].second;

				// If a better path was found to add the vertex v to the Shortest Path Tree.
				if(dist[u] >= w){
					if (!in_spt[v] and dist[u] < dist[v]) {
						dist[v] = dist[u];
						pq.push({v, dist[v]});
					}
				}
				else{
					if (!in_spt[v] and w < dist[v]) {
						dist[v] = w;
						pq.push({v, dist[v]});
					}
				}
			}
		}
	}
}

int main(){
	
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);

		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	dijkstra(0);

	printf("%d\n", dist[n-1]);

	return 0;
}

// 4 3 - 0.75 seg
// 5 2 - 0.20 seg
// 6 1 - 0.16 seg + (0.2 * 5) = 1 + 1 - 1.2 = 0.8

// 4 2.2 - 0.55 seg
// 5 0.0 - 0.00 seg
// 6 0.8 - 0.13 seg