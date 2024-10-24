#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

vector<int> g[N+1];
int p[N+1];
long long ans[N+1];
int spt[N+1];
int d[N+1];

vector<long long> prs;

void dfs(int u, int dp){
	d[u] = dp;
	for(int v : g[u]){
		dfs(v,dp+1);
	}
}

void dfs2(int u){
	for(int v : g[u]){
		if(ans[v] % ans[u]){
			ans[v] *= ans[u];
		}
	}
}

void solve(){
	int n;
	cin >> n;

	for(int i = 2; i <= 281; i++){
		prs.push_back(i);
		for(int div = 2; div*div <= i; div++){
			if(i%div == 0){
				prs.pop_back();
				break;
			}
		}
	}

	
	for(int i = 1; i <= n; i++){
		spt[i] = -1;
	}

	for(int i = 1; i < n; i++){
		int par, u;
		cin >> par >> u;
		p[u] = par;
		g[par].push_back(u);
	}

	for(int i = 1; i <= n; i++){
		ans[i] = 1;
	}

	dfs(1,0);
	set<pair<int,int>> leaf;
	for(int i = 1; i <= n; i++){
		if(g[i].empty()) leaf.insert({-d[i],i});
	}

	priority_queue<tuple<int,int,int>> pq;

	int pi = 0;
	for(auto [dp,u] : leaf){
		pq.push({d[u],-prs[pi],u});
		pi++;
	}

	while(pq.size()){
		int dp, u, pr;
		tie(dp, pr, u) = pq.top();
		pr *= -1;
		pq.pop();

		
		if(u == 1) continue;
		
		for(int i = u; i != -1; i = spt[i]) ans[i] *= pr*ans[p[u]];
		
		// cout << u << ": " << endl;
		// for(int i = 1; i <= n; i++){
		// 	cout << ans[i] << " ";
		// }
		// cout << endl;
		
		int v = p[u];

		if(spt[v] == -1){
			pq.push({d[v],-pr,v});
			spt[v] = u;
		}
	}

	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
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