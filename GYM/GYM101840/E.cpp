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

typedef long long ll;

int mp[N + 1]; // mp[i] stores the minimum prime number which divides i. i is prime if it's not 0 and mp[i] == i.

/* O(N). */
vector<int> linear_sieve(int n) {
    vector<int> p; // Stores prime numbers.

    for (int i = 2; i <= n; i++) {
        if (!mp[i]) { // i is prime if we haven't found any smaller factors of it.
            mp[i] = i;
            p.push_back(i);
        }

        // Since every number x can be written as x = i * mp[x] we can iterate over every prime mp[x] (prime[j]).
        for (int j = 0; j < p.size() and p[j] <= mp[i] and i * p[j] <= n; j++) {
            mp[i * p[j]] = p[j];
        }
    }

    return p;
}

/* O(Log(N)). */
vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> f; // Sorted vector of pairs (prime, exponent).

    // Asserting that linear_sieve was executed before factorizing.
    assert(mp[2] == 2);

    // While there are still prime factors.
    while (n > 1) {
        if (!f.empty() and mp[n] == f.back().first) {
            f.back().second++;
        } else {
            f.push_back({mp[n], 1});
        }

        // Dividing n by its smallest prime factor.
        n /= mp[n];
    }

    return f;
}

vector<pair<int,int>> g[N+1]; 
map<ll,ll> prs[N+1];
ll ones[N+1];
ll dbls[N+1];
ll parent[N+1];
ll sz[N+1];
ll ans;

void dfs(int u, int p){
	if(p) parent[u] = p;

	int heavy = -1;
	int heavy_v = 0;

	sz[u] = 1;
	vector<pair<int,int>> ng;
	for(auto e : g[u]){
		int v = e.fi;
		if(v == p) continue;
		ng.push_back({v,e.se});
		dfs(v,u);

		if(sz[v] > heavy_v){
			heavy_v = sz[v];
			heavy_v = ng.size();
		}

		sz[u] += sz[v];
	}

	if(heavy != -1){
		swap(ng[0], ng[heavy]);
	}

	g[u] = ng;
}

void solve(int u){

	ones[u] = 1;
	sz[u] = 1;

	if(g[u].empty()){
		return;
	}

	int v = g[u][0].fi;
	int w = g[u][0].se;
	solve(v);

	vector<pair<int,int>> f = factor(w);

	if(w == 1){
		ans += dbls[u] * ones[v];
		ans += dbls[v] * ones[u];

		ones[u] += ones[v];
		dbls[u] += dbls[v];
		swap(prs[u], prs[v]);
		sz[u] += sz[v];
	}
	else if(f.size() == 1 and f[0].se == 1){

		// cout << u << " - " << ones[u] << " " << sz[u] << " " << dbls[u] << ": " << endl;
		// for(auto p : prs[u]){
		// 	cout << "\t" << p.fi << " " << p.se << endl;
		// }
		// cout << v << " - " << ones[v] << " " << sz[v] << " " << dbls[v] << ": " << endl;
		// for(auto p : prs[v]){
		// 	cout << "\t" << p.fi << " " << p.se << endl;
		// }
		// cout << endl;

		ans += (sz[v] - prs[v][f[0].fi] - ones[v] - dbls[v]) * ones[u]; 
		ans += (sz[u] - prs[u][f[0].fi] - ones[u] - dbls[u]) * ones[v]; 

		prs[u][f[0].fi] += ones[v];
		dbls[u] += (sz[v] - prs[v][f[0].fi] - ones[v] - dbls[v]);
		sz[u] += sz[v] - dbls[v];
	}
	else if(f.size() == 2 and f[0].se + f[1].se == 2){
		ans += ones[u] * ones[v];

		dbls[u] += ones[v];
		sz[u] += ones[v];
	}

	for(int i = 1; i < g[u].size(); i++){
		v = g[u][i].fi;
		w = g[u][i].se;

		solve(v);

		f = factor(w);

		if(w == 1){
			for(auto p : prs[v]){
				ans += (sz[u] - ones[u] - dbls[u] - prs[u][p.fi]) * p.se;
			}

			ans += dbls[u] * ones[v];
			ans += dbls[v] * ones[u];

			ones[u] += ones[v];
			dbls[u] += dbls[v];
			for(auto p : prs[v]) prs[u][p.fi] += p.se;
			sz[u] += sz[v];
		}
		else if(f.size() == 1 and f[0].se == 1){
			ans += (sz[v] - prs[v][f[0].fi] - ones[v] - dbls[v]) * ones[u]; 
			ans += (sz[u] - prs[u][f[0].fi] - ones[u] - dbls[u]) * ones[v]; 

			prs[u][f[0].fi] += ones[v];
			dbls[u] += (sz[v] - prs[v][f[0].fi] - ones[v] - dbls[v]);
			sz[u] += sz[v] - dbls[v];
		}
		else if(f.size() == 2 and f[0].se + f[1].se == 2){
			ans += ones[u] * ones[v];

			dbls[u] += ones[v];
			sz[u] += ones[v];
		}
		else{
			continue;
		}
	}
	// cout << u << " - " << ones[u] << " " << sz[u] << " " << dbls[u] << ": " << endl;
	// for(auto p : prs[u]){
	// 	cout << "\t" << p.fi << " " << p.se << endl;
	// }

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    linear_sieve(100000);

	ifstream file("evaluations.in");

    int t;

    file >> t;

    for(int ts = 1; ts <= t; ts++){
    	int n;
    	file >> n;
    	for(int i = 1; i <= n; i++){
    		g[i].clear();
    		prs[i].clear();
    		parent[i] = 0;
    		ones[i] = 0;
    		dbls[i] = 0;
    		sz[i] = 0;
    	}

    	for(int i = 0; i < n-1; i++){
    		int u, v, w;
    		file >> u >> v >> w;
    		g[u].push_back({v,w});
    		g[v].push_back({u,w});
    	}

    	dfs(1,0);

    	for(int i = 1; i <= n; i++){
    		sz[i] = 0;
    	}

    	ans = 0;
    	solve(1);
    	cout <<"Case " << ts << ": " << ans << endl;
    }
    return 0;

}