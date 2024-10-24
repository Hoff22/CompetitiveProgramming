#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
 
//Hashing stuff
const ll MOD[3] = {999727999, 1070777777, 1000000007};
ll B[3];

void hash_init(){
	for(int i = 0; i < 3; i++){
		B[i] = rng() % MOD[i];
	}
}

vector<ll> hash(vector<int>& v){
	vector<ll> h(3, 0);

	for(int k = 0; k < 3; k++){
		for(int i = v.size()-1; i >= 0; i--){
			h[k] = (h[k] * B[k] + v[i]) % MOD[k]; 
		}
	}

	return h;
}

/*

((v[1])(b) + v[2])(b) + v[3] ... == (v[1]b + v[2])(b) + v[3] == v[1]b^2 + v[2]b + v[3] ...

*/

vector<ll> add(vector<ll>& hs_a, vector<ll>& hs_b){
	vector<ll> h(3);

	for(int k = 0; k < 3; k++){
		h[k] = (hs_a[k] + hs_b[k]) % MOD[k];
	}

	return h;
}

vector<ll> sub(vector<ll>& hs_a, vector<ll>& hs_b){
	vector<ll> h(3);

	for(int k = 0; k < 3; k++){
		h[k] = (hs_a[k] - hs_b[k]) % MOD[k];
		h[k] = (h[k] + MOD[k]) % MOD[k];
	}

	return h;
}

vector<int> g[N+1];
int parent[N+1];
vector<ll> dp[N+1];
vector<ll> dp2[N+1];

void dfs(int u){
	for(int v : g[u]){
		if(v == parent[u]) continue;
		parent[v] = u;
		dfs(v);
		dp[u] = add(dp[u] , dp[v]) % MOD[k];
	}

	if(g[u].size() == 1 and u != 1){
		dp[u] = {1,1,1};
	}

	for(int k = 0; k < 3; k++){
		dp[u][k] = (B[k] * dp[u][k]) % MOD;
	}
}

void dfs2(int u){
	if(u != 1){
		dp2[u][k] = sub(dp[parent[u]][k] , dp[u][k]) % MOD[k];
		for(int k = 0; k < 3; k++){
			dp2[u][k] = (B[k] * dp2[u][k]) % MOD;
		}
	}
	for(int v : g[u]){
		if(v == parent[u]) continue;
		dfs2(v);

	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    hash_init();

    int n;
    cin >> n;
	vector<int> a(n-1);
	vector<int> cnt(n+1, 0);

	for(int i = 0 ; i < n-1; i++) {cin >> a[i]; cnt[a[i]]++;} 

	for(int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vecotr<vector<ll>> list_hashes;
	vector<ll> base_hash = hash(cnt);

	vector<ll> cur = {1,1,1};
	for(int i = 0; i < n; i++){
		list_hashes.push_back(add(base_hash, cur));
		for(int k = 0; k < 3; k++){
			cur[k] = (cur[k] * B[k]) % MOD[k];
		}
	}

	for(int i = 1; i <= n; i++) dp[i] = {1,1,1};
	for(int i = 1; i <= n; i++) dp2[i] = {1,1,1};

	parent[1] = 0;
	dfs(1);
	dfs2(1);

    return 0;

}