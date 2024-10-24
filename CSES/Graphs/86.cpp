#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 100000;
constexpr int M = 200000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;
 
 
struct State {
	int u;
	long long d;
 
	bool operator < (const State &b) const {
		return d > b.d;
	}
};
 
int k;
vector<pair<int, long long>> g[N + 1]; // (Input)
priority_queue<State> pq;
int in_spt[N+1];
multiset<ll> dist[N + 1];
 
/* O(E + E * Log(V)). */
void dijkstra(int u) {
 
	dist[u] = {0};
	pq.push({u,0});
 
	while (!pq.empty()) {
		ll du;
		u = pq.top().u;
		du = pq.top().d;
		pq.pop();
 
		if(in_spt[u]) continue;
 
		dist[u].insert(du);
		if(dist[u].size() == k+1) in_spt[u] = true;
 
		for(auto [v,w] : g[u]){
			if(!in_spt[v]){
				pq.push({v, du + w});
			}
		}
	}	
 
}
 
void solve(){
	int n, m;
	cin >> n >> m >> k;
	
	for(int i = 0; i < m; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}
 
	dijkstra(1);
	
	for(ll d : dist[n]){
		cout << d << " ";
		k--;
		if(!k) break;
	}
	cout << endl;
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