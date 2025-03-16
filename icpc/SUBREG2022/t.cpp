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

// generates a graph gs of the conected components in G
// aka find cycles

constexpr int N = 100000;

vector<int> g[N+1];     // (input)
vector<int> gt[N+1];    // transposed graph
vector<int> gs[N+1];    // (output) conected components graph
vector<int> comp[N+1];  // comp[c] stores which vertices belong to component c
stack<int> s;
bool seen[N+1];
int color[N+1];         // color[u] stores which component vertex u belongs to
int nc;                 // number of components
int n;                  // (input)

/* O(V + E). */
void dfs1(int u){
    seen[u] = true;

    for(int v : g[u]){
        if(!seen[v]) dfs1(v);
    }

    s.push(u);
}

/* O(V + E). */
void dfs2(int u){
    color[u] = nc;
    comp[nc].push_back(u);

    for(int v : gt[u]){
        // color 0 means not visited yet
        if(color[v] == 0) dfs2(v);
        else if(color[u] != color[v]){
            gs[color[v]].push_back(color[u]);
        }
    }
}

/* O(V + E). */
void kosaraju() {
    // Clearing.
    for (int u = 1; u <= n; u++) {
        gt[u].clear();
        gs[u].clear();
        comp[u].clear();
    }

    memset(seen, false, sizeof(seen));
    memset(color, 0, sizeof(color));
    nc = 0;

    // Building the transposed graph.
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            gt[v].push_back(u);
        }
    }

    // Running first DFS to fill the Stack s.
    for (int u = 1; u <= n; u++) {
        // If vertex u wasn't already visited.
        if (!seen[u]) {
            dfs1(u);
        }
    }

    // Running second DFS to build the Strongly Connected Components.
    while (!s.empty()) {
        int u = s.top();
        s.pop();

        // If vertex u wasn't already visited.
        if (!color[u]) {
            nc++;
            dfs2(u);
        }
    }
}



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    scanf("%d %d", &n, &m);

    unordered_set<int> has_in;

    for(int i = 0; i < m; i++){
    	int u, v;
    	scanf("%d %d", &u, &v);
    	g[u].push_back(v);
    }

    kosaraju();

    for(int u = 0; u <= nc; u++){
        if(gs[u].size() == 0) continue;
        printf("%d:\n", u);
        for(int v : gs[u]){
            printf("%d ", v);
        }
        printf("\n");
    }

    return 0;

}