#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

constexpr int N = 200000;

set<int> g[N+1];
int seen[N+1];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> amt(n+1, 1);
	vector<int> deg(n+1, 0);

	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}

	if(n == 1){
		cout << "YES" << endl;
		return 0;
	}

	priority_queue<pair<int,int>> q;

	for(int i = 1; i <= n; i++){
		if(g[i].size() == 1) q.push({-1,i});
	}

	while(q.size()){
		int u = q.top().second;
		q.pop();

		seen[u] = 1;

		// cout << u << endl;

		if(g[u].empty()) continue;

		int v = *g[u].begin();

		if(amt[u] <= amt[v]){
			g[v].erase(u);
			amt[v] += amt[u];
			if(g[v].size() == 1) q.push({-amt[v], v});
		}
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++) cnt += seen[i];
	// for(int i = 1; i <= n; i++) cout << amt[i] << " ";
	// cout << endl;

	if(cnt != n){
		cout << "NO" << endl; 
	}
	else{
		cout << "YES" << endl;
	}
}