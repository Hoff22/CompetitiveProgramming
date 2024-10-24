#include <bits/stdc++.h>
 
#define fi first
#define se second
#define MOD 1000000007
#define N 100
#define T 32
 
using namespace std;
 
typedef long long ll;

int n, m, k;
pair<ll,ll> cnt[T+1][N+1][N+1];

void debug(int i, string pre = ""){
    for(int u = 1; u <= n; u++){
        cout << pre << u << ": ";
        for(int v = 1; v <= n; v++){
            ll a = cnt[i][u][v].fi, b = cnt[i][u][v].se;
            if(a == 0x3f3f3f3f3f3f3f3f){
                cout << "(" << "inf" << "," << b << ") ";
            }
            else{
                cout << "(" << a << "," << b << ") ";
            }
        }
        cout << endl;
    }
}

void solve(){
    cin >> n >> m >> k;
   
    for(int i = 0; i <= 31; i++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                cnt[i][u][v] = {0x3f3f3f3f3f3f3f3f,0};
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        if(w == cnt[0][u][v].fi){
            cnt[0][u][v].se++;
        }
        if(w < cnt[0][u][v].fi){
            cnt[0][u][v].se = 1;
            cnt[0][u][v].fi = w;
        }
    }

    // cout << 0 << ": " << endl;
    // debug(0, " ");
    // cout << endl;

    for(int i = 1; i <= 31; i++){
        for(int u = 1; u <= n; u++){
            for(int w = 1; w <= n; w++){
                for(int v = 1; v <= n; v++){
                    ll d = cnt[i-1][u][v].fi + cnt[i-1][v][w].fi; 
                    if(d == cnt[i][u][w].fi){
                        cnt[i][u][w].se += (cnt[i-1][u][v].se * cnt[i-1][v][w].se);
                    }
                    if(d < cnt[i][u][w].fi){
                        cnt[i][u][w].se = (cnt[i-1][u][v].se * cnt[i-1][v][w].se);
                        cnt[i][u][w].fi = d;
                    }
                }
            }
        }
        // if(i > 4) continue;
        // cout << i << ": " << endl;
        // debug(i, " ");
        // cout << endl;
    }

    int i = 0;
    vector<pair<ll,ll>> last(n+1,{0x3f3f3f3f3f3f3f3f,0});
    vector<pair<ll,ll>> cur(n+1,{0x3f3f3f3f3f3f3f3f,0});
    last[1] = {make_pair(0,1)};
    while(k){
        if(k & 1){
            for(int u = 1; u <= n; u++) cur[u] = make_pair(0x3f3f3f3f3f3f3f3f,0);
            for(int u = 1; u <= n; u++){
                for(int v = 1; v <= n; v++){
                    ll d = last[u].fi + cnt[i][u][v].fi;
                    if(d == cur[v].fi){
                        cur[v].se += (last[u].se * cnt[i][u][v].se); 
                    }
                    if(d < cur[v].fi){
                        cur[v].se = (last[u].se * cnt[i][u][v].se);
                        cur[v].fi = d;
                    }
                }
            }
            swap(cur,last);
        }
        i++;
        k >>= 1;
    }
    if(last[n].fi == 0x3f3f3f3f3f3f3f3f){
        cout << -1 << endl;
        return;
    }
    cout << last[n].fi << endl;
}
 
//  64   -  12   +   4   - 1
// 4!/1! - 4!/2! + 4!/3! - 1
 
int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}