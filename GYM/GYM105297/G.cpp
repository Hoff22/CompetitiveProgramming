#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
typedef long long ll;

#define N 1000

#define eps 0.00000001

long long dist[N+1][N+1];
long long DP[N+1][N+1];
int n;


long long dp(int i , int t){
    if(i > n) return 0;

    if(DP[i][t] != -1) return DP[i][t];

    return DP[i][t] = min(dp(i+1, t) + dist[i][i+1], dp(i+1,i) + dist[t][i+1]);
}


void solve(){
    cin >> n;
    vector<int> a(n+1);

    for(int i = 1 ;i <= n; i++){
        cin >> a[i];
        dist[0][i] = a[i];
        dist[i][0] = a[i];
        for(int j = 1; j <= i; j++){
            dist[i][j] = abs(a[i]-a[j]);
            dist[j][i] = abs(a[i]-a[j]);
        }
    }

    memset(DP, -1 ,sizeof(DP));

    cout << dp(0,0) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; t =1;
    
    for(int i = 0; i < t; ++i){
        solve();
    }
    
    return 0;
}