#include <bits/stdc++.h>

#define N 1000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<tuple<ll,int,int>> g[N+1][N+1];

vector<int> e[2][N+1];

void solve(){
	int n, s1, s2;
	cin >> n >> s1 >> s2;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			g[i][j].clear();
		}
		e[0][i].clear();
		e[1][i].clear();
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		e[0][u].push_back(v);
		e[0][v].push_back(u);
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		e[1][u].push_back(v);
		e[1][v].push_back(u);
	}
	for(int u1 = 1; u1 <= n; u1++){
		for(int u2 = 1; u2 <= n; u2++){
			for(int v1 : e[0][u1]){
				for(int v2 : e[1][u2]){
					g[u1][u2].push_back({-abs(v1-v2), v1, v2});
				}
			}
		}
	}
	// dij
	vector<vector<ll>> dist(n+1, vector<ll>(n+1,0x3f3f3f3f3f3f3f3f));
	vector<vector<bool>> in_spt(n+1, vector<bool>(n+1, 0));
	priority_queue<tuple<ll,int,int>> pq;
	pq.push({0, s1, s2});
	dist[s1][s2] = 0;
	while(pq.size()){
		int u1, u2;
		ll d;
		tie(d,u1,u2) = pq.top();
		pq.pop();
		d = -d;
		if(in_spt[u1][u2]) continue;
		in_spt[u1][u2] = 1;
		for(auto [w, v1, v2] : g[u1][u2]){
			w = -w;
			if(in_spt[v1][v2]) continue;
			if(d + w < dist[v1][v2]){
				dist[v1][v2] = d + w;
				pq.push({-(d+w),v1,v2});
			}
		}
	}
	ll ans = -1;
	for(int u1 = 1; u1 <= n; u1++){
		for(int u2 = 1; u2 <= n; u2++){
			if(u1 != u2 or !in_spt[u1][u2]) continue;
			for(int v1 : e[0][u1]){
				for(int v2 : e[1][u2]){
					if(v1 != v2) continue;
					if(ans == -1 or ans > dist[u1][u2]){
						ans = dist[u1][u2];
					}
				}
			}
		}
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
    return 0;
}