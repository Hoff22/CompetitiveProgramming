#include <bits/stdc++.h>

#define V 1000
#define INF 0x3f3f3f3f

using namespace std;

// find bridges :

// given a graph of V vertices and E edges, count how many of those edges are brdiges.
// a bridge is a edge, that when removed increases the number of connected elements of the
// given graph

vector<int> g[V+1];
bool seen[V+1];
pair<int, int> edges[V+1];

void dfs(int u, pair<int, int> edge){
	seen[u] = true;

	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];

		if(edge.first == u and edge.second == v) continue;
		if(edge.first == v and edge.second == u) continue;

		if(!seen[v]){
			dfs(v, edge);
		}
	}
}

int main(){
    
    int verts, e, a, b;

    scanf("%d%d%d%d", &verts, &e, &a, &b);

    if(e == 0){
    	printf("NAO\n");
		return 0;
    }

    for(int i = 1; i <= e; i++){
    	int u, v;

    	scanf("%d%d", &u, &v);

    	g[u].push_back(v);
    	g[v].push_back(u);

    	edges[i] = make_pair(u, v);
    }

    for(int i = 1; i <= e; i++){
    	memset(seen, 0, sizeof(seen));

    	dfs(a, edges[i]);

    	if(!seen[b]){
    		printf("NAO\n");
    		return 0;
    	}
    }

    printf("SIM\n");	

    return 0;
}