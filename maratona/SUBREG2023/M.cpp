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



void solve(){
	int n; cin >> n;
	vector<vector<long long>> dist(n+1, vector<long long>(n+1,0));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> dist[i][j];
		}
	}

	int ans = 0;

	vector<vector<bool>> rem(n+1, vector<bool>(n+1,false));

	// For every intermediate vertex k.
    for (int k = 1; k <= n; k++) {
        // For every starting vertex i.
        for (int i = 1; i <= n; i++) {
            // For every ending vertex j.
            for (int j = 1; j <= n; j++) {
                // If there is a better path using k as intermediate vertex.
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    cout << -1 << endl;
                    return;
                }
                if(dist[i][k] + dist[k][j] == dist[i][j] and i!=k and j!=k){
                	if(!rem[i][j]){
                		rem[i][j] = true;
                		ans++;
                	}
                }
            }
        }
    }

    cout << ans/2 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    solve();

    return 0;

}