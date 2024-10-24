#include <bits/stdc++.h>

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

constexpr int N = 100000;

vector<int> g[N + 1];     // (Input)
int color[N + 1];         // color[u] contains the index of the cycle that u belongs to. It is 0 for vertices that don't belong to a cycle.
bool in_stack[N + 1];
int parent[N + 1];
bool seen[N + 1];
int nc;
int n; // (Input)

/* O(V + E) - Finds all the cycles of an undirected graph that doesn't have any composite cycles. */
void dfs(int u) {
    in_stack[u] = seen[u] = true;

    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];

        if (!seen[v]) { // Not seen yet.
            parent[v] = u;
            dfs(v);
        } else if (v != parent[u] and in_stack[v]) { // Not current node's parent and is currently in stack. Found cycle.
            nc++;
            int p = u;

            // Backtracking through the entire cycle.
            while (p != v) {
                color[p] = nc;
                p = parent[p];
            }

            color[v] = nc;
        }
    }

    in_stack[u] = false;
}

/* O(V + E). */
void cycles() {
    // Clearing.
    for(int i = 1; i <= n; i++){
    	seen[i] = 0;
    	color[i] = 0;
    }
    nc = 0;

    // Running a DFS for every unseen vertex.
    for (int u = 1; u <= n; u++) {
        if (!seen[u]) {
            parent[u] = 0;
            dfs(u);
        }
    }
}

int solve(int u, int t){

	if(u == t) return 1;

	seen[u] = 1;

	int r = 0;

	for(int v : g[u]){
		if(seen[v] or color[v] == color[u]) continue;

		r += solve(v, t);
	}

	return r;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    while(true){
    	int m, q;
    	cin >> n >> m >> q;
    	if(n + m + q == 0) break;

    	for(int i = 0; i <= n; i++){
    		g[i].clear();
    		gs[i].clear();
    	}

    	for(int i = 0; i < m; i++){
    		int u, v;
    		cin >> u >> v;

    		g[u].push_back(v);
    		g[v].push_back(u);
    	}

    	cycles();

    	for(int i = 1; i <= n; i++){
    		if(color[i] == 0){
    			nc++;
    			color[i] = nc;
    		}
    	}

    	for(int k = 0; k < q; k++){
    		int start, term;
    		cin >> start >> term;

    		// cout << start << ": " << color[start] << endl; 
    		// cout << term << ": " << color[term] << endl; 

    		if(color[start] == color[term]){
    			cout << "N" << endl;
    			continue;
    		}

    		for(int i = 1; i <=n ;i++) seen[i] = 0;

    		if(solve(start, term)) cout << "Y" << endl;
    		else cout << "N" << endl;
    	}

    	cout << "-" << endl;
    }

    return 0;

}