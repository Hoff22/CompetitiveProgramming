#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

map<string, vector<string>> g;
map<string, bool> seen;
map<string, int> in;
int ans;

void dfs(string u){
	seen[u] = true;
	ans++;

	for(string v : g[u]){
		if(!seen[v]){
			in[v]--;
			if(!in[v]){
				dfs(v);
			}
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;

	cin >> n;

	unordered_set<string> start;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		start.insert(s);
		in[s] = 0;
	}

	int m;

	cin >> m;

	for(int i = 0; i < m; i++){
		string u;
		int k;

		cin >> u >> k;

		unordered_set<string> s;
		for(int j = 0; j < k; j++){
			string v;

			cin >> v;

			if(!s.count(v)){
				s.insert(v);
				g[v].push_back(u);
				in[u]++;
				//cout << "insert " << v << endl;
			}
		}
	}

	// for(auto node : in){
	// 	string u = node.first;
	// 	cout << u << ":" << node.second << endl;
	// }

	for(auto node : g){
		string u = node.first;
		vector<string> vs = node.second;

		if(!seen[u] and !in[u]){
			if(start.count(u) == 0) in[u] = 1;
		}
	}

	ans = 0;
	for(auto node : g){
		string u = node.first;
		vector<string> vs = node.second;

		if(!seen[u] and !in[u]){
			dfs(u);
		}
	}

	for(string i : start){
		if(seen[i] == 0) ans++;
	}

	cout << ans << endl;

    return 0;
}