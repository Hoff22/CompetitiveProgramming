#include <bits/stdc++.h>

#define N 5000

using namespace std;

int a[N+1];
pair<int,int> dp[N+1][N+1];

int main(){
    
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    for(int l = n; l >= 1; l--){
        for(int r = l; r <= n; r++){
            if(l == r) dp[l][r] = {a[l], 0};
            else if(l == r-1) dp[l][r] = {a[l]+a[r], (a[l]+a[r] == 0)};
            else{
                dp[l][r].first = dp[l+1][r-1].first + a[l] + a[r];
                dp[l][r].second = (dp[l][r].first == 0) + dp[l+1][r].second + dp[l][r-1].second - dp[l+1][r-1].second;
            }
        }
    }

    for(int q = 0; q < m; q++){
        int l, r;
        scanf("%d %d", &l, &r);
        
        printf("%d\n", dp[l][r].second);
    }

    return 0;
}