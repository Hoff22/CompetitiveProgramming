#include <bits/stdc++.h>

#define N 4000
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

vector<int> g[N+1];
int color[N+1];

long long cnt = 0;

long long dfs(int u){

	int r = color[u];

	for(int v : g[u]){
		r += dfs(v);
	}

	if(r == 0) cnt++;

	return r;
}

void solve(){
	int n;
	cin >> n;
	string s;

	for(int i = 1; i <= n; i++) g[i].clear();

	for(int i = 2; i <= n; i++){
		int p;
		cin >> p;
		g[p].push_back(i);
	}

	cin >> s;

	for(int i = 1; i <= n; i++){
		if(s[i-1] == 'W') color[i] = 1;
		else color[i] = -1;
	}

	cnt = 0;

	dfs(1);

	cout << cnt << endl;
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >>t;
	
	while(t--){
		solve();
	}
    return 0;

}