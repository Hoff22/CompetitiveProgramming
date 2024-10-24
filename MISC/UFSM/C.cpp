#include <bits/stdc++.h>

#define N 22
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

int DP[(1<<22)][N+1];
vector<pair<int, int>> g[N + 1]; // (Input)
int dist[N + 1][N + 1];
int n; // (Input)

/* O(V^3) - Returns true if there's a negative cycle in the graph. */
bool floyd_warshall() {
    // Initializing.
    memset(dist, 0x3f, sizeof(dist));

    // Filling distance matrix with the edges.
    for (int u = 0; u < n; u++) {
        dist[u][u] = 0;

        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            int w = g[u][i].second;
            dist[u][v] = w;
        }
    }

    // For every intermediate vertex k.
    for (int k = 0; k < n; k++) {
        // For every starting vertex i.
        for (int i = 0; i < n; i++) {
            // For every ending vertex j.
            for (int j = 0; j < n; j++) {
                // If there is a better path using k as intermediate vertex.
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Checking for negative cycles.
    for (int u = 0; u < n; u++) {
        if (dist[u][u] < 0) {
            return true; // u belongs to a negative cycle.
        }
    }

    // No negative cycles.
    return false;
}

void solve(){
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			long long x; cin >> x;
			if(i == j) continue;
			g[i].push_back({j, x});
		}
	}

	floyd_warshall();

	vector<int> masks;

	for(int i = 1; i < (1<<n); i++){
		masks.push_back(i);
	}

	sort(masks.begin(), masks.end(), [&](int a, int b){
		return __builtin_popcount(a) < __builtin_popcount(b);
	});

	for(int i = 0; i < n; i++){
		for(int m = 0; m < (1<<n); m++){
			DP[m][i] = 0x3f3f3f3f;
		}
	}

	DP[1][0] = 0;

	// cout << masks.size() * 22 * 22 << endl;

	for(int m : masks){
		for(int i = 0; i < n; i++){
			if(((m >> i) & 1) == 0) continue;
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				if(((m >> j) & 1) == 0) continue;

				DP[m][j] = min(DP[m][j], DP[m ^ (1<<j)][i] + dist[i][j]);
			}
		}
	}

	int ans = 0x3f3f3f3f;
	for(int i = 0; i < n; i++){
		ans = min(ans, DP[(1<<n)-1][i]);
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}