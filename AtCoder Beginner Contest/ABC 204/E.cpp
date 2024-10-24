#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

using namespace std;

struct State {
	long long u, d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

vector<pair<int, int>> g[N + 1]; // (Input)
map<pair<int,int>, long long> ds;
priority_queue<State> pq;
bool in_spt[N + 1];
long long dist[N + 1];

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

				int t;
				if(dist[u]+1 >= ds[{u,v}]) t = 0;
				else{
					t = ds[{u,v}] - dist[u] - 1;
					if((ds[{u,v}] / (dist[u] + t)) - (ds[{u,v}] / (dist[u] + t + 1)) < 1){
						t--;
					}
				}

				// If a better path was found to add the vertex v to the Shortest Path Tree.
				if (!in_spt[v] and dist[u] + w + t + (ds[{u,v}] / (dist[u] + t + 1)) < dist[v]) {
					dist[v] = dist[u] + w + t + (ds[{u,v}] / (dist[u] + t + 1));
					pq.push({v, dist[v]});
				}
			}
		}
	}
}

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int u, v, c, d;
		scanf("%d %d %d %d", &u, &v, &c, &d);
		g[u].push_back({v, c});
		g[v].push_back({u, c});
		ds[{u, v}] = d;
		ds[{v, u}] = d;
	}

	dijkstra(1);

	if(dist[n] == 0x3f) printf("-1\n");
	else printf("%lld\n", dist[n]);

    return 0;
}