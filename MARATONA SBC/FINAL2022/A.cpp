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
int geto[N+1][N+1];
int seen[N+1];
vector<int> f1(N+1);
vector<int> f2(N+1);

void dfs(int u, int i){
	geto[i][u] = 1;
	
	for(int v : g[u]){
		if(geto[i][v]) continue;
		dfs(v, i);
	}
}

void dfs2(int u, int p, vector<int>& f){
	seen[u] = 1;

	if(geto[u][p]) f[u] = 1;
	
	for(int v : inv_g[u]){
		if(seen[v] or v == p) continue;
		dfs2(v, p, f);
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
	memset(geto, 0 ,sizeof(geto));

   	for(int i = 1; i <= n; i++){
   		dfs(i, i);
   	}

   	for(int i = 1; i <= n; i++){

   		int v1, v2;
   		v1 = g[i][0];
   		v2 = g[i][1];

   		memset(seen, 0, sizeof(seen));
   		dfs2(v1, i, f1);
   		memset(seen, 0, sizeof(seen));
   		dfs2(v2, i, f2);

   		for(int j = 1; j <= n; j++){
   			if(j == i) continue;
   			if(f1[j] == 1 and f2[j] == 1) ans[i] = 'Y';
   		}


   		for(int j = 1; j <= n; j++){
   			f1[j] = 0;
   			f2[j] = 0;
   		}
   	}

   	for(int i = 1; i <= n; i++){
   		cout << ans[i];
   	}
   	cout << endl;

    return 0;

}