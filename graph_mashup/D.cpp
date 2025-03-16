#include <bits/stdc++.h>

#define N 100000
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

vector<int> g[N+1];
pair<int,int> e[N+1];
int color[N+1];
// vector<pair<int,int>> g[N+1];

void dfs(int u, int c){
	color[u] = c;
	for(int v : g[u]){
		if(color[v] == 0){
			dfs(v, color[u] * -1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
	int m;

	cin >> n;
	cin >> m;

	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		e[i] = {u,v};
		// int w;
		// cin >> w;
		// g[u].push_back({v,w});
	}

	for(int i = 1; i <= n; i++){
		if(color[i] == 0) dfs(i, 1);
	}

	for(int i = 1; i <= m; i++){
		if(color[e[i].fi] == color[e[i].se]){
			cout << "-1\n";
			return 0;
		}
	}

	vector<int> ans1;
	vector<int> ans2;

	for(int i = 1; i <= n; i++){
		if(color[i] == 1){
			ans1.push_back(i);
		}
		else if(color[i] == -1){
			ans2.push_back(i);
		}
	}

	cout << ans1.size() << endl;
	for(int u : ans1) cout << u << " ";
	cout << endl;
	cout << ans2.size() << endl;
	for(int u : ans2) cout << u << " ";
	cout << endl;


    return 0;

}