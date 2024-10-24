#include<bits/stdc++.h>
 
using namespace std;
 
#define N 100000
 
int n, m;
vector<int> g[N+1];
int spt[N+1]; 
 
void bfs(int root){
    memset(spt, 0, sizeof(spt));
 
    queue<int> q;
    q.push(root);
    spt[root] = -1;
 
    while(q.size()){
        int u = q.front(); q.pop();
 
        for(int v : g[u]){
            if(spt[v] != 0) continue;
            spt[v] = u;
            q.push(v);
        }
    }
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
 
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    bfs(1);
 
    if(spt[n] == 0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> pa;
        int cur = n;
        while(cur != -1){
            pa.push_back(cur);
            cur = spt[cur];
        }
        cout << pa.size() << endl;
        reverse(pa.begin(), pa.end());
        for(int i : pa) cout << i << ' ';
        cout << endl;
    }
 
    return 0;
}