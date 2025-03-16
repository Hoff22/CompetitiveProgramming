#include <bits/stdc++.h>

#define N 100000
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

int n;	
int m;	
long long a[N+1];
long long dist[N+1];
vector<pair<int,long long>> g[N+1];

struct State {
	int u;
	long long d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

priority_queue<State> pq;
bool in_spt[N + 1];

/* O(E + E * Log(V)). */
void dijkstra(int u) {
	// Initializing.
	memset(in_spt, false, sizeof(in_spt));
	memset(dist, 0x3f, sizeof(dist));

	// Initializing and pushing source vertex. Cost of adding the first vertex u to Shortest Path Tree is 0.
	dist[u] = 0ll;
	pq.push({u, 0ll});

	// While there are vertices to visit.
	while (!pq.empty()) {
		// Retrieving vertex u from current State.
		u = pq.top().u;
		pq.pop();

		// cout << "u: " << u <<" dist: " << dist[u] << endl; 
		// cout << "best: " << best <<" dist: " << dist[best] << endl;
		// for(int i = 1; i <= n; i++){
		// 	cout << dist[i] << " ";
		// }
		// cout << endl;

		// If vertex u still doesn't belong to Shortest Path Tree.
		if (!in_spt[u]) {
			// Vertex u now belongs to Shortest Path Tree.
			in_spt[u] = true;
			// cout << "push: ";
			// For every vertex v adjacent to u.
			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].first;
				int w = g[u][i].second;
				// cout << v << " ";
				// If a better path was found to add the vertex v to the Shortest Path Tree.
				if (!in_spt[v] and dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.push({v, dist[v]});
				}
			}
			// cout << endl;
		}
		// cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int k;

	cin >> n;
	cin >> m;
	cin >> k;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v; 
		long long w;
		cin >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	int s;
	for(int i = 0; i < k; i++){
		cin >> s;

		dijkstra(s);

		int best = s;

		for(int j = 1; j <= n; j++){
			if(dist[j] + a[j] < dist[best] + a[best]) best = j;
		}

		for(int j = 1; j <= n; j++){
			if(j == best) continue;
			g[best].push_back({j, a[best] + a[j]});
			g[j].push_back({best, a[j] + a[best]});
		}

		dijkstra(s);

		for(int v = 1; v <= n; v++){
			cout << dist[v] << " ";
		}
		cout << endl;
	}



    return 0;

}