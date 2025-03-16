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

typedef long long ll;

ll xs[N+1];
ll ys[N+1];
int seen[N+1];
vector<tuple<ll,ll,ll>> g[N+1];


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
    	ll u, v, x, y;
    	cin >> u >> v >> x >> y;
    	g[u].push_back({v,x,y});
    	g[v].push_back({u,-x,-y});
    }

    xs[1] = ys[1] = 0;
    queue<int> q;
    q.push(1);
    seen[1] = 1;

    while(q.size()){
    	int u = q.front();
    	q.pop();

    	for(auto [v, dx, dy] : g[u]){
    		if(seen[v]) continue;
    		seen[v] = 1;
    		xs[v] = xs[u]+dx;
    		ys[v] = ys[u]+dy;
    		q.push(v);
    	}
    }

    for(int i = 1; i <= n; i++){
    	if(!seen[i]) cout << "undecidable" << endl;
    	else cout << xs[i] << " " << ys[i] << endl;
    }

    return 0;

}