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

struct State {
	int u;
	long long d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

vector<int> pv;
vector<pair<int, long long>> g[N + 1];
long long g2Dist[17][17];
priority_queue<State> pq;
bool in_spt[N + 1];
long long dist[N + 1];
long long n, p, m, G, t;

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
				long long w = g[u][i].second;

				// If a better path was found to add the vertex v to the Shortest Path Tree.
				if (!in_spt[v] and dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.push({v, dist[v]});
				}
			}
		}
	}
}

/*
11111

*/
long long DP[17][(1ll<<16)][2];

long long solve(int u, int vis, int jump){
	if(vis == (1ll<<(p+1)) - 1){
		if(u == 0) return 0;
		return INF;
	}

	if(DP[u][vis][jump] != -1) return DP[u][vis][jump];

	long long r = INF;
	for(int v = 0; v < pv.size(); v++){
		long long w = g2Dist[u][v];

		if(v == u or (vis>>v) & 1) continue;

		if(jump == 0){
			r = min(r, solve(v, vis | (1ll<<v), 1) + t);
		}
		r = min(r, solve(v, vis | (1ll<<v), jump) + w);
	}

	return DP[u][vis][jump] = r;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> p >> m >> G >> t;

	pv.push_back(0);
	for(int i = 0; i < p; i++){
		int x, t1;
		cin >> x >> t1;
		pv.push_back(x);
		G -= t1;
	}

	for(int i = 0; i < m; i++){
		int u, v;
		long long w;

		cin >> u >> v >> w;

		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	for(int u = 0; u < pv.size(); u++){
		dijkstra(pv[u]);

		for(int v = 0; v < pv.size(); v++){
			if(v == u) continue;

			g2Dist[u][v] = dist[pv[v]];
		}
	}

	memset(DP, -1, sizeof(DP));

	if(solve(0,0,1) <= G){
		cout << "possible without taxi" << endl;
	}
	else if(solve(0,0,0) <= G){
		cout << "possible with taxi" << endl;
	}
	else{
		cout << "impossible" << endl;
	}

	return 0;

}