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

vector<pair<int,string>> g[N+1];
string s;

int dfs(int u, int a, int b, int ab, int ba){

	if(u == s.size()){
		if(a == 0 and b == 0 and ab == 0 and ba == 0){
			return 1;
		}
		else{
			return 0;
		}
	}

	if(a < 0 or b < 0 or ab < 0 or ba < 0) return 0;

	int r = 0;

	for(pair<int,string> e : g[u]){

		int v = e.fi;
		string w = e.se;

		if(w == "A"){
			r += dfs(v, a-1, b, ab, ba);
		}
		if(w == "B"){
			r += dfs(v, a, b-1, ab, ba);
		}
		if(w == "AB"){
			r += dfs(v, a, b, ab-1, ba);
		}
		if(w == "BA"){
			r += dfs(v, a, b, ab, ba-1);
		}

	}

	return r;
}

void solve(){
	int a,b,ab,ba;
	cin >> a >> b >> ab >> ba;
	cin >> s;
	/*
		ababa	= 2x aba
				= 2x ab
				= 2x ba
	*/

	for(int i = 0; i < s.size(); i++){
		g[i].clear();

		if(s[i] == 'A'){
			g[i].push_back({i+1, "A"});

			if(i < s.size()-1 and s[i+1] == 'B'){
				g[i].push_back({i+2, "AB"});
			}
		}
		else{
			g[i].push_back({i+1, "B"});

			if(i < s.size()-1 and s[i+1] == 'A'){
				g[i].push_back({i+2, "BA"});
			}	
		}
	}

	if(dfs(0, a, b, ab, ba)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}

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