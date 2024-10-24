#include <bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f

using namespace std;

vector<int> g[N+1];
//bool seen[N+1];
int dist[N+1];

void bfs(int root){
    queue<int> q;
    //seen[root] = true;
    dist[root] = 0;
    q.push(root);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];

            if(dist[v] > dist[u]){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    
    int verts, e, a, b;

    scanf("%d%d%d%d", &verts, &e, &a, &b);

    for(int i = 1; i <= e; i++){
        int u, v;

        scanf("%d%d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(dist, INF, sizeof(dist));

    bfs(a);

    if(dist[b] == INF){
        printf("-1\n");
        return 0;
    }

    printf("%d\n", dist[b]);

    return 0;
}