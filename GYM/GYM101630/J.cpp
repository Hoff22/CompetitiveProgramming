#include <bits/stdc++.h>

#define N 3000
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

struct State {
	int u;
	long long d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

vector<pair<int, long long>> g[N + 1]; // (Input)
priority_queue<State> pq;
bool in_spt[N + 1];
multiset<long long> path[N+1];
long long dist[N + 1];
int k;

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

			long long small = 0;
			int sz = path[u].size();

			if(sz) small = *path[u].begin();

			// For every vertex v adjacent to u.
			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].first;
				long long w = g[u][i].second;

				if(in_spt[v]) continue;

				if(sz < k){
					// If a better path was found to add the vertex v to the Shortest Path Tree.
					if (dist[u] + w < dist[v]) {
						dist[v] = dist[u] + w;
						path[v] = path[u];
						path[v].insert(w);
						pq.push({v, dist[v]});
					}
				}
				else if(w > small){
					// cout << u << ": ";
					// for(int j : path[u]) cout << j << " ";
					// cout << "| " << dist[u];
					// cout << "\t";
					// for(int j : path[6]) cout << j << " ";
					// cout << "| " << dist[6];
					// cout << endl;
					// If a better path was found to add the vertex v to the Shortest Path Tree.
					if (dist[u] + w - small < dist[v]) {
						dist[v] = dist[u] + w - small;
						path[v] = path[u];
						path[v].erase(path[v].lower_bound(small));
						path[v].insert(w);
						pq.push({v, dist[v]});
					}
				}
				else{
					// If a better path was found to add the vertex v to the Shortest Path Tree.
					if (dist[u] < dist[v]) {
						dist[v] = dist[u];
						path[v] = path[u];
						pq.push({v, dist[v]});
					}
				}

			}
		}
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, m;
	cin >> n >> m >> k;

	for(int i = 1; i <= m; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	dijkstra(1);

	// for(int i : path[n]) cout << i << " ";
	// cout << endl;

	cout << dist[n] << endl;


    return 0;

}