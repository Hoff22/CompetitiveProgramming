#include <bits/stdc++.h>

using namespace std;

#define N 100000

vector<int> g[N+1];
int deg[N+1];

struct State{
    int u;

    bool operator<(const State& b) const{
        if(deg[u] == deg[b.u]) return u < b.u;
        return deg[u] < deg[b.u];
    }
};

void solve(){

    int n, m, a, b;

    cin >> n >> m >> a >> b;

    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    set<State> dq;

    for(int i = 1; i <= n; i++){
        dq.insert({i});
    }
    
    while(dq.size() and (deg[dq.begin()->u] < a or (dq.size() - 1) - deg[dq.rbegin()->u] < b)){
        if(deg[dq.begin()->u] < a){
            int u = dq.begin()->u;
            for(int v : g[u]){
                if(!dq.erase({v})) continue;
                deg[v]--;
                dq.insert({v});
            }
            dq.erase({u});
        }
        else if((dq.size() - 1) - deg[dq.rbegin()->u] < b){
            int u = dq.rbegin()->u;
            for(int v : g[u]){
                if(!dq.erase({v})) continue;
                deg[v]--;
                dq.insert({v});
            }
            dq.erase({u});
        }
    }

    cout << dq.size() << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}