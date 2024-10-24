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


pair<string, string> parse(string s){
	pair<string, string> u;

	string cur;
	cur = "";
	for(int j = 0; j < s.size(); j++){
		if(s[j] == ':'){
			u.fi = cur;
			cur = "";
			j++;
		}
		else{
			cur += s[j];
		}
	}
	u.se = cur;

	return u;
}

map<pair<string,string>, vector<pair<string,string>>> g;
map<pair<string,string>, bool> seen;

void dfs(pair<string,string> u){
	seen[u] = true;

	for(auto v : g[u]){
		if(seen[v]) continue;
		dfs(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<pair<string, string>> beg;

    for(int i = 0; i < n; i++){
    	string s;
    	int q;
    	cin >> s >> q;

    	pair<string,string> u = parse(s);
    	seen[u] = false;

    	if(u.se == "PROGRAM") beg.push_back(u);

    	for(int j = 0; j < q; j++){
    		cin >> s;
    		pair<string,string> v = parse(s);

    		g[v].push_back(u);
    	}
    }


    for(auto u : beg){
    	if(!seen[u]) dfs(u);
    }

    int ans = 0;
    for(auto u : g){
    	if(seen[u.fi] == false) ans++;
    }

    cout << ans << endl;

    return 0;

}