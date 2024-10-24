#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 200000;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;
 
int n;
ll p[N+1];
int g[N+1];
ll DP[N+1];
 
ll dp(int i){
    if(i > n) return 0;
 
    if(DP[i] != -1) return DP[i];
 
    return DP[i] = max(dp(i+1), dp(g[i]) + p[i]);
}
 
void solve(){
    memset(DP, -1, sizeof(DP));
 
    cin >> n;
 
    vector<tuple<int,int,int>> ps;
    for(int i = 0; i < n; i++){
        int l, r, x;
        cin >> l >> r >> x;
        ps.push_back({l,r,x});
    }     
 
    sort(ps.begin(), ps.end());
 
    for(int i = 0; i < n; i++){
        int l, r, x;
        tie(l, r, x) = ps[i];
        int j = (int)(upper_bound(ps.begin(), ps.end(), make_tuple(r,INF,INF)) - ps.begin()); 
        
        g[i+1] = j+1;
 
        p[i+1] = x;
    }
 
    cout << dp(1) << endl;
}
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
 
    while(t--){
        solve();
    }
 
 
 
    return 0;
}