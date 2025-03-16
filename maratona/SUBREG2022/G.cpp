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

struct point{
	int x, y;

	bool operator < (const point& b) const{
		if(x == b.x) return y < b.y;
		return x < b.x;
	}
};

map<pair<point,point>, int> lines;

vector<int> g[N+1];

void addLine(point a, point b, int i){
	if(a < b){
		if(lines.count({a,b})){
			g[lines[{a,b}]].push_back(i);
			g[i].push_back(lines[{a,b}]);
		}
		else{
			lines[{a,b}] = i;
		}
	}
	else{
		if(lines.count({b,a})){
			g[lines[{b,a}]].push_back(i);
			g[i].push_back(lines[{b,a}]);
		}
		else{
			lines[{b,a}] = i;
		}
	}
}

void root_tree(int u, int p){
	vector<int> ngu;
	for(int i : g[u]){
		if(p == i) continue;
		ngu.push_back(i);
		root_tree(i, u);
	}
	g[u] = ngu;
}

typedef long long ll;

ll DP[N+1][2];
int seen[N+1][2];
ll c[N+1];

ll dp(int u, bool took){

	if(g[u].size() == 0) return c[u];
	
	if(seen[u][took]) return DP[u][took];
	seen[u][took] = 1;
		
	ll take = c[u];
	ll not_take = 0;
	for(int v : g[u]){
		take += dp(v, 1);
		not_take += dp(v, 0);
	}	
	
	if(took and g[u].size() > 1){
		return DP[u][took] = min(take, not_take);
	}
	return DP[u][took] = take;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
	cin >> n;

	for(int i = 1 ; i <= n; i++){
		ll x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		point p1 = {x1,y1};
		point p2 = {x2,y2};
		point p3 = {x3,y3};

		addLine(p1, p2, i);
		addLine(p2, p3, i);
		addLine(p3, p1, i);

		// shoelace area
		c[i] = abs(x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1);
	}

	int root = 0;

	for(int i = 1; i <= n; i++){
		if(g[i].size() <= 1){
			root = i;
			break;
		}
	}

	root_tree(root, 0);

	cout << fixed << setprecision(1);

	// for(int i = 1; i <= n; i++){
	// 	cout << c[i] << " " << i << ": ";
	// 	for(int v : g[i]){
	// 		cout << v << " ";
	// 	}
	// 	cout << endl;
	// }
	
	memset(seen, 0, sizeof(seen));

	cout << 1.0*dp(root,1)/2 << endl;

    return 0;

}