#include <bits/stdc++.h>

#define N 5000

using namespace std;

int a[N+1];
int sum[N+1];
long long dp[N+1][N+1];

// recursive dp
long long solve(int l, int r){
    if(l >= r) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    return dp[l][r] = solve(l+1, r) + solve(l, r-1) - solve(l+1, r-1) + (sum[r] - sum[l-1] == 0);
}

int main(){
    
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }

    memset(dp, -1, sizeof(dp));

// iterative dp
    for(int l = n; l >= 1; l--){
        for(int r = 1; r <= n; r++){
            if(l >= r) dp[l][r] = 0;
            else{
                dp[l][r] = dp[l+1][r] + dp[l][r-1] - dp[l+1][r-1] + (sum[r] - sum[l-1] == 0);
            }
        }
    }

    while(m--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", dp[l][r]);
    }

    return 0;
}