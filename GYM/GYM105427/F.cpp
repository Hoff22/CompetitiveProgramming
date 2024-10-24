#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

vector<int> g[N+1];
long long ans[N+1];
long long p[N+1];
long long d[N+1];

vector<long long> prs;

void dfs(long long u, int ant = -1){
	if(ans[u] == 1 and u != 1){
		d[u] = d[p[u]] + 1;
	}
	else{
		d[u] = 0;
	}
	for(long long v : g[u]){
		if(v==ant) continue;
		dfs(v,u);
	}
}

void dfsp(int u, int ant = -1){
	p[u] = ant;
	for(long long v : g[u]){
		if(v==ant) continue;
		dfsp(v,u);
	}
}

void solve(){
	long long n;
	cin >> n;

	for(long long i = 2; i <= 500; i++){
		prs.push_back(i);
		for(long long div = 2; div*div <= i; div++){
			if(i%div == 0){
				prs.pop_back();
				break;
			}
		}
	}

	p[1] = -1;

	for(long long i = 1; i < n; i++){
		long long v, u;
		cin >> u >> v;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	dfsp(1);

	for(long long i = 1; i <= n; i++){
		ans[i] = 1;
	}

	long long pr = 0;
	while(true){
		for(long long i = 0; i <= n; i++){
			d[i] = 0;
		}

		dfs(1);

		long long u = 0;
		for(long long i = 1; i <= n; i++){
			if(d[i] > d[u]) u = i;
		}

		if(!u) break;

		// cout << u << ": ";
		vector<long long> path;
		long long i;
		for(i = u; i != 1 and ans[i] == 1; i = p[i]){
			path.push_back(i);
			// cout << i << " ";
			for(long long j : path) {
				ans[j] *= prs[pr];
			}
		}
		// cout << i;

		// cout << endl;
		for(long long j : path) ans[j] *= ans[i];
		pr++;
	}

	for(long long i = 1; i <= n; i++){
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