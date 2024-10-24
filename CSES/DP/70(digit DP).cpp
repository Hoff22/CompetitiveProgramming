#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
constexpr int N = 10;
constexpr int M = 1000;
constexpr int MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
 
typedef long long ll;
 
vector<int> a, b;
long long DP[20][10][2][2][2];
 
long long dp(int i, int last, int apref, int bpref, int zpref){
    if(i == b.size()) return 1;
 
    if(DP[i][last][apref][bpref][zpref] != -1) return DP[i][last][apref][bpref][zpref];
 
    long long res = 0;
 
    int l, r;
 
    l = 0;
    r = 9;
 
    if(apref) l = a[i];
    if(bpref) r = b[i];
 
    for(int d = l; d <= r; d++){
        if(d == last and !zpref) continue;
        res += dp(i+1, d, apref and d==l, bpref and d==r, zpref and d==0);
    }
 
    return DP[i][last][apref][bpref][zpref] = res;
}
 
void solve(){
    memset(DP, -1, sizeof(DP));
 
    string a_,b_;
    cin >> a_ >> b_;
 
    a.push_back(0);
    b.push_back(0);
 
    int j = a_.size()-b_.size();
    for(int i = 0; i < b_.size(); i++, j++){
        if(j < 0) a.push_back(0);
        else a.push_back(a_[j]-'0');
        b.push_back(b_[i]-'0');
    }
 
    cout << dp(0,0,1,1,1) << endl;
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