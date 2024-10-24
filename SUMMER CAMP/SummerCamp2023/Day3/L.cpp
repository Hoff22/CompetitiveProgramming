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

int n, m;
vector<pair<int, char>> g[N + 1]; // (Input)

int dist1[N+1];
int dist2[N+1];

const int MOD = 1e9+7;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
const int r = uniform_int_distribution<int>(0, MOD-1)(rng);
struct hash_str{
	vector<long long> h; // hash of prefixes
	vector<long long> p; // powers of r (random value) for range querys of hash

	/* O(N) */
	hash_str(string s) : h(s.size()), p(s.size()){
		int n = s.size();
		h[0] = s[0];
		for(int i = 1; i < n; i++){
			h[i] = (h[i-1] * r + s[i]) % MOD;
		}

		p[0] = 1;
		for(int i = 1; i < n; i++){
			p[i] = (p[i-1] * r) % MOD;
		}
	}

	/* O(1) */
	long long sub_hash(int l, int r){
		if(l == 0){
			return h[r];
		}
		long long ans = (h[r] - h[l-1] * p[r-l+1]) % MOD;
		ans += MOD
		ans %= MOD;

		return ans;
	}
};


void bfs1(int u){

	queue<int> q;
	for(int i = 1; i <= n; i++){
		dist1[i] = INF;
	}


	dist1[u] = 0;
	q.push(u);

	while(!q.empty()){

		u = q.front();
		q.pop();

		for(auto i : g[u]){
			int v = i.first;

			if(dist1[v] > dist1[u] + 1){
				dist1[v] = dist1[u] + 1;
				q.push(v);
			}
		}

	}

}

void bfs2(int u){

	queue<int> q;
	for(int i = 1; i <= n; i++){
		dist2[i] = INF;
	}


	dist2[u] = 0;
	q.push(u);

	while(!q.empty()){

		u = q.front();
		q.pop();

		for(auto i : g[u]){
			int v = i.first;

			if(dist2[v] > dist2[u] + 1){
				dist2[v] = dist2[u] + 1;
				q.push(v);
			}
		}

	}

}

string dp[N+1][26];
int seen[N+1][26];

string go(int u, char addc){

	//cout << u << " " << addc << " " << endl;
	
	if(u == 1){
		string s = "";
		s += addc;
		return s;
	}



	if(seen[u][addc-'a']) return dp[u][addc-'a'];
	seen[u][addc-'a'] = 1;

	string r = "";

	for(auto i : g[u]){
		int v = i.fi;
		char c = i.se;

		if(dist2[u] + dist1[v] + 1 == dist1[n]){

			string v_s = go(v, c);
			//cout << u << " " << v << " v_s: " << v_s << endl;
			if(r == "" or v_s < r){
				r = v_s;
			}

		}
	}
	//cout << u << " return: " << r + addc << endl;
	return dp[u][addc-'a'] = r + addc;
}

void rec(int u, char addc){
	if(u == 1){
		cout << u << " ";
		return;
	}

	string r = "";
	int bestV;
	int bestC;

	for(auto i : g[u]){
		int v = i.fi;
		char c = i.se;

		if(dist2[u] + dist1[v] + 1 == dist1[n]){

			string v_s = go(v, c);
			//cout << u << " " << v << " v_s: " << v_s << endl;
			if(r == "" or v_s < r){
				bestV = v;
				bestC = c;
				r = v_s;
			}

		}
	}
	//cout << u << " return: " << r + addc << endl;
	rec(bestV, bestC);
	cout << u << " ";
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    memset(seen, 0 ,sizeof(seen));

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int u, v;
		char w;
		cin >> u >> v >> w;

		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	bfs1(1);
	bfs2(n);

	string s = go(n, 'a');
	cout << s.size()-1<<endl;
	rec(n,'a');
	cout << endl;
	cout << s.substr(0,s.size()-1) << endl;

    return 0;

}