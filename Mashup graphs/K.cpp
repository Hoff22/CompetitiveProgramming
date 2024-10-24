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

vector<pair<int,int>> g[N+1];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back({v, i});
    	g[v].push_back({u, i});
    }

    


    return 0;

}