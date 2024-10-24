#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
 
ll n, x;
pair<int,ll> DP[(1<<20)];
bool seen[(1<<20)];
ll c[21];
 
pair<int,ll> dp(int m){
    if(m == 0) return {1, 0ll};
 
    if(seen[m]) return DP[m];
    seen[m] = 1;
 
    pair<int,ll> ans = {20, 0x3f3f3f3f3f3f3f3f};
 
    for(int j = 0; j < n; j++){
        if((m>>j)&1){
            pair<int,ll> res = dp(m^(1<<j));
            res.se += c[j];
 
            if(res.se <= x){
                ans = min(ans, res);
            }
            else{
                res.fi++;
                res.se = c[j];
                ans = min(ans, res);
            }
        }
    }
 
    return DP[m] = ans;
}
 
/*
1 1 0
7 3 4  6
 
  7 -
    10  - 14 - 10 4
 
    7 3 - 11 7 - 7 7 - 7 3 4 
*/
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> c[i];
 
    cout << dp((1<<n)-1).fi << endl;
 
    return 0;
}