#include <bits/stdc++.h>

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC optimize("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve(){
    ll n, m, t0; cin >> n >> m >> t0;
    
    // edge inf
    vector<ll> open(m);
    vector<ll> close(m);
    vector<ll> cycle(m);
    
    // what edges this vector has 
    vector< vector< pair<ll,ll> > > adj(n+1);
    vector<ll> time_to(n+1, 1e15);
    
    for(int i = 0; i < m; ++i){
        ll a, b; cin >> a >> b;
        ll x, y; cin >> x >> y;
        
        open[i] = x;
        close[i] = y;
        cycle[i] = x + y;
        
        adj[a].push_back({i,b});
        adj[b].push_back({i,a});
    }
    
    //   vertex, time;
    priority_queue< pll, vector<pll>, greater<pll>> pq;
    
    pq.push({1, t0});
    
    while( !pq.empty() ){
        ll v = pq.top().first;
        ll t = pq.top().second;
        pq.pop();
        
        // already visited this v
        if( time_to[v] <= t ) continue;
        
        for(auto & [e,w] : adj[v] ){
            // if already open, then 0 wait, else it's the time to finish the cycle
            ll t_cycle = t % cycle[e]; 
            ll t_open =  t_cycle < open[e] ? 0 : cycle[e] - t_cycle;
            
            if( time_to[ w ] > t + t_open )
                pq.push({w, t + t_open});
        }
        
        time_to[ v ] = t;
        // cout <<" Time to " << v << " is " << t << "\n";
    }
    cout << time_to [  n  ] << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
        
    return 0;
}