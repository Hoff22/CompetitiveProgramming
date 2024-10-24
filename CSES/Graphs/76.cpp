#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1, vector<int>());
    vector<int> seen(n+1,0);
 
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    function<void(int)> dfs = [&](int u){
        seen[u] = 1;
        for(int v : g[u]){
            if(seen[v]) continue;
            dfs(v);
        }
    };  
 
    vector<int> ans;
 
    for(int i = 1; i <= n; i++){
        if(!seen[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
 
    cout << ans.size() - 1 << endl;
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i] << " " << ans[i-1] << endl;
    }
 
    return 0;
}