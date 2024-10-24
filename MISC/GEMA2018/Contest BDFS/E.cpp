#include <bits/stdc++.h>

#define N 1000
#define INF 0x3f3f3f3f

using namespace std;

vector<int> g[N+1];
int adj[N+1][N+1];
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

            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            scanf("%d", &adj[i][j]);
            if(i == j and adj[i][j] != 0){
                printf("nao\n");
                return 0;
            }
            if(adj[i][j] == 1){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= n; i++){ // 10³
        memset(dist, -1, sizeof(dist));
        bfs(i); // 10³ + 10³
        for(int j = 1; j <= n; j++){ // 10³
            if(adj[i][j] != dist[j]){
                printf("nao\n");
                return 0;
            }
        }
    }

    printf("sim\n");

    return 0;
}