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

long long soma(long long cur, char w){
	return (cur * 26) + (w-'a'+1);
}

vector<pair<int, char>> g[N + 1]; // (Input)
priority_queue<State> pq;
bool in_spt[N + 1];
long long dist[N + 1];
int parent[N + 1];

void path(vector<int>& v, int u){
	v.push_back(u);
	if(u == 1) return;
	else{
		path(v, parent[u]);
	}
}

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
				char w = g[u][i].second;

				int nDist = soma(dist[u], w);

				if(!in_spt[v]){
					if(nDist < dist[v]){
						dist[v] = nDist;
						pq.push({v, dist[v]});
						parent[v] = u;
					}
				}
			}
		}
	}
}

int main(){
	
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int u, v;
		char w;

		cin >> u >> v >> w;

		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	dijkstra(1);

	vector<int> ans;
	path(ans, n);
	reverse(ans.begin(), ans.end());



	cout << ans.size()-1 << endl;
	for(int i : ans) cout << i << " ";
	cout << endl;
	int last = 1;
	for(int i : ans){
		if(i != 1){
			for(int v = 0; v < g[last].size(); v++){
				if(g[last][v].first == i) cout << g[last][v].second;
			}
		}
		last = i;
	}
	cout << endl;

    return 0;

}