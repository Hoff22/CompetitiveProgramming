#include <bits/stdc++.h>
#include <string>

#define N 1000000
#define INF 0x3f3f3f3f

using namespace std;

int n;
string path;

int dp[N+1][20+1];

int solve(int d, int p){

    if(d >= n){
        return 0;
    }
    

    if(path[d] == '.'){
        return INF;
    }
    

    if(dp[d][p] != -1){
        return dp[d][p];
    }
    
    if(path[d] == 'p'){
        return dp[d][p] = min(solve(d + 1 + (1 << (p + 1)), p + 1), solve(d + 1, p)) + 1;
    }
  
    return dp[d][p] = solve(d + 1, p) + 1;
}
// 12
// pxpp.p....xxo

int main(){

    cin >> n;
    cin >> path;

    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0);

    if(ans >= INF){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    

    
    return 0;
}