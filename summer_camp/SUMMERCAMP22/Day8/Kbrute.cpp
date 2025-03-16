#include <bits/stdc++.h>

#define N 1000000
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

ifstream in; // ridiculo

vector<int> g[N+1];
int color[N+1];

int canPaint(int n, int m){
 
    // Create a visited array of n
    // nodes, initialized to zero
    vector<int> visited(n + 1, 0);
 
    // maxColors used till now are 1 as
    // all nodes are painted color 1
    int maxColors = 1;
 
    // Do a full BFS traversal from
    // all unvisited starting points
    for (int sv = 1; sv <= n; sv++){
 
        if (visited[sv]) continue;
 
        // If the starting point is unvisited,
        // mark it visited and push it in queue
        visited[sv] = 1;
        queue<int> q;
        q.push(sv);
 
        // BFS Travel starts here
        while (!q.empty()){
            int u = q.front();
            q.pop();
 
            // Checking all adjacent nodes
            // to "u" edge in our queue
           	for(int v : g[u]){
                // IMPORTANT: If the color of the
                // adjacent node is same, increase it by 1
                if(color[u] == color[v]) color[v] += 1;
 
                // If number of colors used shoots m, return
                // 0
                maxColors = max(maxColors, max(color[u], color[v]));
                if (maxColors > m) return 0;
 
                // If the adjacent node is not visited,
                // mark it visited and push it in queue
                if (!visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        } 
    }
    return 1;
}

void solve(){
	int n;
	in >> n;

	vector<int> h(n+1);

	for(int i = 1; i <= n; i++){
		int x;
		in >> x;
		h[i] = x;
		g[i].clear();
		color[i] = 1;
	}

	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(h[i] < h[j]){
				g[i].push_back(j);
				g[j].push_back(i);
				break;
			}
		}
		for(int j = i-1; j >= 1; j--){
			if(h[i] < h[j]){
				g[i].push_back(j);
				g[j].push_back(i);
				break;
			}
		}
	}

	for(int u = 1; u <= n; u++){
		cout << u << ": ";
		sort(g[u].begin(), g[u].end());
		for(int v : g[u]){
			cout << v << " ";
		}
		cout << endl;
	}
}

int main(){
	
	in.open("tour.in", ifstream::in);	

	int t;
	in >> t;
	
	while(t--){
		solve();
	}

	in.close();
    return 0;

}