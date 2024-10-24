#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 200000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;

int j[32][N+1];
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

void dfs3(int u, vector<int>& pos){
	for(int v : g[u]){
		if(pos[v] != -1 or color[u] != color[v]) continue;
		pos[v] = pos[u] + 1;
		dfs3(v, pos);
	}
}

void solve(){
	int q;
	cin >> n >> q;

	vector<int> t(n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		g[i].push_back(t[i]);
	}

	for(int i = 1; i <= n; i++){
		j[0][i] = t[i];
	}

	for(int p = 1; p <= 31; p++){
		for(int i = 1; i <= n; i++){
			j[p][i] = j[p-1][j[p-1][i]];
		}
	}

	kosaraju();

	vector<int> pos(n+1, -1);
	for(int i = 1; i <= nc; i++){
		pos[comp[i][0]] = 0;
		dfs3(comp[i][0], pos);
	}

	auto f = [&](int i, int k){
		int p = 0;
		while(k){
			if(k&1){
				i = j[p][i];				
			}
			p++;
			k>>=1;
		}
		return i;
	};

	// for(int i = 1; i <= n; i++){
	// 	cout << pos[i] << " ";
	// }
	// cout << endl;

	while(q--){
		int a, b;
		cin >> a >> b;

		int ans_a = -1;
		int ans_b = a;
		if(color[a] != color[b]){
			int l = 0;
			int r = n;
			while(l <= r){
				int m = (l + r) / 2;
				// cout << "\t" << l << " " << r << " " << m << " " << f(a,m); 

				if(color[b] == color[f(a,m)]){
					ans_a = m;
					ans_b = f(a,m);
				}
				if(color[b] <= color[f(a,m)]){
					// cout << " hit" << endl;
					r = m-1;
				}
				else{
					// cout << " miss" << endl; 
					l = m+1;
				}
			}
		}
		else ans_a = 0;

		if(ans_a == -1){
			cout << -1 << endl;
		}
		else{
			a = ans_b;
			// cout << a << " " << b << " " << ans_a << endl;  
			if(pos[a] <= pos[b]){
				ans_a += pos[b]-pos[a];
			}
			else{
				ans_a += comp[color[a]].size() - pos[a] + pos[b];
			}

			cout << ans_a << endl;
		}
	}
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