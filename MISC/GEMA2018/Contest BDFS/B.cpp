#include <bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f

using namespace std;

vector<int> g[N+1];
int dist[N+1];

void bfs(int root){
    queue<int> q;
    dist[root] = 1;
    q.push(root);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    
    int n, m;

    scanf("%d%d", &n, &m);

    for(int i = 0; i < m; i++){
        int u, v;

        scanf("%d%d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }

    int count = 0;

    for(int i = 1; i <= n; i++){
        if(dist[i] == INF){
            count++;
            bfs(i);
        }
    }

    printf("%d\n", count);
    
    return 0;
}