#include <bits/stdc++.h>

#define N 1000
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
vector<int> inv_g[N+1];
vector<int> order;
int seen[N+1];

void dfs(int u){
	seen[u] = 1;
	
	for(int v : g[u]){
		if(seen[v]) continue;
		dfs(v);
	}

	order.push_back(u);
}

void dfs2(int u, vector<int>& cur){
	seen[u] = 1;
	cur[u] = 1;

	for(int v : inv_g[u]){
		if(seen[v]) continue;
		dfs2(v, cur);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
    	int v1, v2;
    	cin >> v1 >> v2;
    	g[i].push_back(v1);
    	g[i].push_back(v2);
    	inv_g[v1].push_back(i);
    	inv_g[v2].push_back(i);
    }	

    vector<char> ans(n+1, 'N');

	memset(seen, 0 ,sizeof(seen));
	dfs(1);
	reverse(order.begin(), order.end());

	memset(seen, 0 ,sizeof(seen));
   	for(int i : order){
   		
   		if(seen[i] == 0){
   			vector<int> cur(n+1, 0);
   			dfs2(i, cur);

   			for(int j = 1; j <= n; j++){
   				if(cur[j]){
   					if(cur[ g[j][0] ] and cur[ g[j][1] ]) ans[j] = 'Y';
   				}
   			}
   		}
   		
   	}

   	for(int i = 1; i <= n; i++){
   		cout << ans[i];
   	}
   	cout << endl;

    return 0;

}