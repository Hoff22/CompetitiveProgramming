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

vector<int> g[N+1];

void solve(){
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++) g[i].clear();

	vector<long long> c(n+1, 0);
	vector<long long> d(n+1, 0);

	for(int i = 1; i <= n; i++){
		int u;
		cin >> u;
		g[i].push_back(u);
	}

	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}

	for(int i = 1; i <= n; i++){
		for(int v : g[i]){
			d[v] += c[i];
		}
	}

	priority_queue<pair<long long,int>> pq;

	for(int i = 1; i <= n; i++){
		pq.push({-d[i], i});
	}

	vector<int> rem(n+1, 0);

	while(pq.size()){
		long long amt = -pq.top().fi;
		int u = pq.top().se;

		pq.pop();

		if(rem[u] or amt > d[u]) continue;

		cout << u << " ";
		rem[u] = 1;

		for(int v : g[u]){
			if(rem[v]) continue;
			d[v] -= c[u];
			pq.push({-d[v], v});
		}
	}
	cout << endl;
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