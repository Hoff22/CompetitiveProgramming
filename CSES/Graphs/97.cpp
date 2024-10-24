#include <bits/stdc++.h>
 
#define fi first
#define se second
 
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

void test(int u){
	seen[u] = true;
	for(int v : g[u]){
		if(!seen[v]) test(v);
	}
}

void solve(){
	int m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	kosaraju();
	
	if(nc == 1){
		cout << "YES" << endl;
		return;
	}

	int a = 1, b;
	for(int i = 1; i <= n; i++){
		if(color[a] != color[i]){
			b = i;
			break;
		}
	}

	memset(seen, false, sizeof(seen));

	test(a);
	if(seen[b]) swap(a,b);

	cout << "NO" << endl;
	cout << a << " " << b << endl;
}
 
int main(){
 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t = 1;
 
	while(t--){
		solve();
	}
 
	return 0;
}