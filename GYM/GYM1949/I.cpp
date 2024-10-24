#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

constexpr int N = 1000;

vector<int> g[N+1];
int seen[N+1];

pair<int,int> dfs(int u, int c){
	seen[u] = c;
	int x = 0, y = 0;
	for(int v : g[u]){
		if(seen[v] == c) tie(x,y) = make_pair(-INF,-INF);
		if(seen[v]) continue;

		int a,b;

		if(c == 1) tie(a,b) = dfs(v, 2); 
		if(c == 2) tie(a,b) = dfs(v, 1); 
		
		x += a;
		y += b;
	}

	if(c == 1){
		return {x+1, y};
	}
	return {x,y+1};
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<tuple<ll,ll,ll>> c(n);
	for(int i = 0; i < n; i++){
		ll x, y, r;
		cin >> x >> y >> r;
		c[i] = {x,y,r};
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;

			ll x,y,r,x_,y_,r_;

			tie(x,y,r) = c[i];
			tie(x_,y_,r_) = c[j];

			if((x_-x)*(x_-x) + (y_-y)*(y_-y) == (r+r_)*(r+r_)){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(!seen[i]){
			int x,y;
			tie(x,y) = dfs(i, 1);
			if(x < 0) continue;
			if(x != y){
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;

}