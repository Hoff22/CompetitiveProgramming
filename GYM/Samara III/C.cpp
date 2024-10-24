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

vector<pair<int,int>> g[N+1];

unordered_set<char> names[N+1];

struct State {
	int u, d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

priority_queue<State> pq;
bool in_spt[N + 1];
int dist[N + 1];
int path[N+1];

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
				if (!in_spt[v] and dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.push({v, dist[v]});
					path[v] = u;
				}
			}
		}
	}
}

int main(){
	
	int n, m;

	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;

		for(int j = 0; j < s.length(); j++){
			if(s[j] <= 'Z') s[j] += ('a'-'A');
			names[i].insert(s[j]);
		}
	}

	for(int i = 1; i <= m; i++){
		int u, v;

		cin >> u >> v;

		int w = 0;

		for(auto c : names[u]){
			if(names[v].count(c)) w++;
		}

		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	int s, e;
	cin >> s >> e;

	dijkstra(s);

	cout << dist[e] << endl;

    return 0;

}