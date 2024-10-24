#include <bits/stdc++.h>

#define N 10000
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

typedef long long ll;

vector<pair<int,ll>> g[N+1];

struct State {
	int u;
	ll d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

priority_queue<State> pq;
bool in_spt[N + 1];
ll dist1[N + 1];
ll dist2[N + 1];
int n, m, k;

/* O(E + E * Log(V)). */
void dijkstra(int u, ll* dist) {
	// Initializing.
	memset(in_spt, false, sizeof(in_spt));
	memset(dist, 0x3f, sizeof(ll) * (n+1));

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
				ll w = g[u][i].second;

				// If a better path was found to add the vertex v to the Shortest Path Tree.
				if (!in_spt[v] and dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.push({v, dist[v]});
				}
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
    	int t; cin >> t;
    }

    vector<tuple<int,int,ll>> edges;

    for(int i = 0; i < m; i++){
    	int u,v;
    	ll w;
    	cin >> u >> v >> w;

    	edges.push_back(make_tuple(u,v,w));

    	g[u].push_back({v,w});
    	g[v].push_back({u,w});
    }

    dijkstra(1, dist1);
    dijkstra(n, dist2);

    int cnt = 0;
    for(auto e : edges){
    	int u, v;
    	ll w;

    	tie(u,v,w) = e;

    	if(dist1[u] + dist2[v] + w == dist1[n]){
    		cnt++;
    	}
    	else if(dist1[v] + dist2[u] + w == dist1[n]){
    		cnt++;
    	}
    }

    if(cnt > k-1){
    	cout << "yes\n";
    }
    else{
    	cout << "no\n";
    }

    return 0;

}