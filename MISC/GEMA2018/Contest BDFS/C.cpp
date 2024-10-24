#include <bits/stdc++.h>

#define V 100000
#define INF 0x3f3f3f3f

using namespace std;

// find bridges :

// given a graph of V vertices and E edges, count how many of those edges are brdiges.
// a bridge is a edge, that when removed increases the number of connected elements of the
// given graph

vector<int> g[V+1];

int dfs_time = 0;

int tin[V+1];
int low[V+1];
bool seen[V+1];

void is_bridge(int u, int v){
    printf("path %d - %d is a bridge\n", u, v);
}

void dfs(int u, int p = -1){
    seen[u] = true;
    low[u] = tin[u] = dfs_time++;

    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];

        if(u == p){
            continue;
        }
        if(seen[v]){
            low[u] = min(low[u], tin[v]);
        }
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]){
                is_bridge(u, v);
            }
        }
    }
}


int main(){
    
    int verts, e;

    scanf("%d%d", &verts, &e);

    for(int  i = 1; i <= e; i++){
        int u, v;
        scanf("%d%d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(seen, 0, sizeof(seen));
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    dfs_time = 0;

    dfs(1);

    return 0;
}