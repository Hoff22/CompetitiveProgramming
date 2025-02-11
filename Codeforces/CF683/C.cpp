#include <bits/stdc++.h>

#define N 200000
#define MAX 200000
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

#define LOG_MAX 30

struct bit_trie{
	int sz, child[2];

	bit_trie(){
		this->sz = 0;
		this->child[0] = this->child[1] = -1;
	}
};

vector<bit_trie> bt = {bit_trie()};

// O(log(N));
void insert(int n, vector<bit_trie>& t){
	int cur = 0;
	for(int i = LOG_MAX; i >= 0; i--){
		t[cur].sz++;
		if(t[cur].child[0] == -1){
			t[cur].child[0] = t.size();
			t.push_back(bit_trie());
			t[cur].child[1] = t.size();
			t.push_back(bit_trie());
		}
		cur = t[cur].child[(n>>i) & 1];
	}
	t[cur].sz++;
}

void erase(int n, vector<bit_trie>& t){
	int cur = 0;
	for(int i = LOG_MAX; i >= 0; i--){
		if(t[cur].sz == 0) return;
		t[cur].sz--;
		cur = t[cur].child[(n>>i) & 1];
	}
	t[cur].sz--;
}

// O(log(N));
int xor_min(int n, vector<bit_trie>& t){
	int cur = 0;
	long long ans = 0;
	if(t[cur].sz == 0) return -1;
	for(int i = LOG_MAX; i >= 0; i--){
		if(t[t[cur].child[((n>>i) & 1)]].sz > 0){
			cur = t[cur].child[((n>>i) & 1)];
		}
		else{
			ans += (1<<i);
			cur = t[cur].child[!((n>>i) & 1)];
		}
	}
	return ans;
}

int v[N+1];
int g[N+1];
set<int> p[N+1];
int del[N+1];

int dfs(int u){
	erase(u,bt);
	int x = xor_min(u, bt);
	cout << u << endl;
	if(p[u].count(u^x)){
		cout << " > delete" << endl;
		del[u] = 1;
		int res = 1;
		for(int d : p[u]) res += dfs(d); 
		return res;
	}
	cout << " > point to " << (int)(u^x) << endl;
	g[u] = u^x;
	p[u^x].insert(u);
	insert(u, bt);
	return 0;
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		insert(v[i], bt);
		g[v[i]] = -1;
	}

	for(int i = 1; i <= n; i++){
		erase(v[i], bt);
		int x = xor_min(v[i], bt);
		insert(v[i], bt);
		if(x == -1 or g[v[i] ^ x] == v[i]) continue;
		g[v[i]] = v[i] ^ x;
		p[v[i] ^ x].insert(v[i]);
	}

	for(int i = 1; i <= n; i++){
		cout << v[i] << ": " << g[v[i]] << endl; 
	}

	int ans = 0;

	for(int i = 1; i <= n; i++){
		if(g[v[i]] == -1 and !del[v[i]]){
			ans += dfs(v[i]);
		}
	}

	cout << ans << endl;
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