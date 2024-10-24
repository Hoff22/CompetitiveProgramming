#include <bits/stdc++.h>

#define N 300000
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

string c;
long long qnt[N+1];
int color[N+1];
vector<int> g[N+1];
// vector<pair<int,int>> g[N+1];

bool testCycle(int u){
	if(color[u] == 1) return true;
	if(color[u] == 2) return false;
	color[u] = 1;

	bool r = false;
	for(int v : g[u]){
		r |= testCycle(v);
	}

	color[u] = 2;

	return r;
}

long long solve(int u, char ch){

	if(qnt[u] != -1) return qnt[u];	
	qnt[u] = (ch == c[u-1]);

	long long r = 0;
	for(int v : g[u]){
		r = max(r, solve(v, ch));
	}

	return qnt[u] += r;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
	int m;

	cin >> n;
	cin >> m;
	cin >> c;



	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		// g[v].push_back(u);
		// int w;
		// cin >> w;
		// g[u].push_back({v,w});
	}

	for(int i = 1; i <= n; i++){
		if(color[i] == 0){
			if(testCycle(i)){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	long long ans = 0;
	for(char ch = 'a'; ch <= 'z'; ch++){
		long long cur = 0;
		for(int i = 1; i <= n; i++){
			qnt[i] = -1;
		}
		for(int i = 1; i <= n; i++){
			if(qnt[i] == -1){
				cur = max(cur, solve(i, ch));
			}
		}
		// if(cur > 0){
		// 	cout << ch << ":\n";
		// 	for(int i = 1; i <= n; i++){
		// 		cout << qnt[i] << " ";
		// 	}
		// 	cout << endl;
		// }
		ans = max(ans, cur);
	}

	cout << ans << endl;

    return 0;

}