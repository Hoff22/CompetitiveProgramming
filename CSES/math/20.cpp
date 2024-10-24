#include <bits/stdc++.h>
 
#define fi first
#define se second
#define MOD 1000000007
#define N 100
#define T 32
 
using namespace std;
 
typedef long long ll;

vector<int> g[N+1];
ll cnt[T+1][N+1][N+1 ];

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for(int u = 1; u <= n; u++){
        for(int v : g[u]){
            cnt[0][u][v] += 1;
        }
    }

    for(int i = 1; i <= 31; i++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                for(int w = 1; w <= n; w++){
                    cnt[i][u][w] += (cnt[i-1][u][v] * cnt[i-1][v][w]) % MOD;
                    cnt[i][u][w] %= MOD;
                }
            }
        }
    }

    int i = 0;
    vector<ll> last(n+1,0);
    vector<ll> cur(n+1,0);
    last[1] = 1;
    while(k){
        if(k & 1){
            for(int u = 1; u <= n; u++) cur[u] = 0;
            for(int u = 1; u <= n; u++){
                for(int v = 1; v <= n; v++){
                    cur[v] += (last[u] * cnt[i][u][v]) % MOD;
                    cur[v] %= MOD;
                }
            }
            swap(cur,last);
        }
        i++;
        k >>= 1;
    }
    cout << last[n] % MOD << endl;
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