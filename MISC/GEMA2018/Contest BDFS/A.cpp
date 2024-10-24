#include <bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f

using namespace std;

vector<int> g[N];
bool seen[N];

bool dfs(int a, int b){
	seen[a] = true;

	if(a == b){
		return true;
	}

	for(int i = 0; i < g[a].size(); i++){
		int v = g[a][i];

		if(!seen[v]){
			if(dfs(v, b)){
				return true;
			}
		}
	}

	return false;
}

int main(){
    
    int n, m, a, b;

    scanf("%d%d%d%d", &n, &m, &a, &b);

    for(int i = 0; i < m; i++){
    	int u, v;

    	scanf("%d%d", &u, &v);

    	g[u].push_back(v);
    }

    if(dfs(a,b)){
    	printf("SIM\n");
    }
    else{
    	printf("NAO\n");
    }

    
    return 0;
}