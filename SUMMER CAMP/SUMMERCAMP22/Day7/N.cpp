#include <bits/stdc++.h>

#define N 60
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

map<string, tuple<long long,long long,long long>> pos;
map<string, set<string>> wholes;

struct State {
	string u;
	double d;

	bool operator < (const State &b) const {
		return d > b.d;
	}
};


/* O(E + E * Log(V)). */
double dijkstra(string u, string b) {
	// Initializing.
	priority_queue<State> pq;
	map<string, bool> in_spt;
	map<string, double> dist;

	for(auto p : pos){
		dist[p.first] = 0x3f3f3f3f3f3f3f3fll;
	}
	for(auto p : pos){
		in_spt[p.first] = false;
	}

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
			for(auto p : pos){
				string v = p.first;
				
				if(v != u){

					int x1, y1, z1;
					int x2, y2, z2;
					tie(x1, y1, z1) = pos[u];
					tie(x2, y2, z2) = p.second;

					long long x3 = (x2-x1);
					long long y3 = (y2-y1);
					long long z3 = (z2-z1);

					double w = sqrt(x3*x3 + y3*y3 + z3*z3); 
					
					if(wholes[u].count(v)){
						w = 0;
					}
					// If a better path was found to add the vertex v to the Shortest Path Tree.
					if (!in_spt[v] and dist[u] + w < dist[v]) {
					//	cout << u <<" "<< v <<" " << w << endl;
						dist[v] = dist[u] + w;
						pq.push({v, dist[v]});
					}
				}
			}
		}
	}

	return dist[b];
}

void solve(int j){
	wholes.clear();
	pos.clear();

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;

		long long x, y, z;
		cin >> x >> y >> z;

		pos[s] = {x, y, z};
	}

	int m;
	cin >> m;

	for(int i = 0; i < m; i++){
		string a, b;
		cin >> a >> b;

		wholes[a].insert(b);
	}

	int q;
	cin >> q;

	cout << "Case " << j << ":" << endl;

	for(int i = 0; i < q; i++){
		string u, v;
		cin >> u >> v;

		cout << "The distance from " << u << " to " << v << " is " << llround(dijkstra(u,v)) << " parsecs.\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}