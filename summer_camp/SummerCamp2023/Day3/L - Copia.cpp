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

struct myString{
	string s;
	bool operator < (const myString &b) const {
		if(b.s.size() == s.size()) return s < b.s;
		return s.size() < b.s.size();
	}
	bool operator > (const myString &b) const {
		if(b.s.size() == s.size()) return s > b.s;
		return s.size() > b.s.size();
	}
};

struct State {
	int u;
	myString d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};

int n, m;
vector<pair<int, char>> g[N + 1]; // (Input)
priority_queue<State> pq;
bool in_spt[N + 1];
myString dist[N + 1];
int rec[N+1];
int seen[N+1];

/* O(E + E * Log(V)). */
void dijkstra(int u) {
	// Initializing.
	memset(in_spt, false, sizeof(in_spt));
	for(int i = 0; i <= n; i++){
		dist[i] = {""};
	}

	// Initializing and pushing source vertex. Cost of adding the first vertex u to Shortest Path Tree is 0.
	dist[u] = {""};
	seen[u] = 1;
	pq.push({u,dist[u]});

	// While there are vertices to visit.
	while (!pq.empty()) {
		// Retrieving vertex u from current State.
		u = pq.top().u;
		pq.pop();
		//printf("u: %d\n", u);
		// If vertex u still doesn't belong to Shortest Path Tree.
		if (!in_spt[u]) {
			// Vertex u now belongs to Shortest Path Tree.
			in_spt[u] = true;

			// For every vertex v adjacent to u.
			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].first;
				char w = g[u][i].second;
				//printf("\tv: %d w: %c\n", v,w);

				//printf("\tdist[v]: %d\n", dist[v].fi);

				myString ndist;

				ndist.s = dist[u].s + w;

				// If a better path was found to add the vertex v to the Shortest Path Tree.
				if (!in_spt[v] and (!seen[v] or ndist < dist[v])) {
					seen[v] = 1;
					dist[v] = ndist;
					rec[v] = u;
					pq.push({v, dist[v]});
				}
			}
		}
	}
}

void printAns(int u){

	if(u!=1) printAns(rec[u]);

	printf("%d ", u);

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int u, v;
		char w;
		scanf(" %d %d %c", &u, &v, &w);

		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	dijkstra(1);

	printf("%d\n", (int)dist[n].s.size());
	printAns(n);
	printf("\n");
	for(int i = 0; i < dist[n].s.size(); i++){
		printf("%c", dist[n].s[i]);
	}
	printf("\n");

    return 0;

}