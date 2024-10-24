#include <bits/stdc++.h>

using namespace std;

int n, x, arr[20];

int dp[21][40000];

int solve(int i, int sum){

    if(i == n){
        return  sum == x;
    }
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }

    return dp[i][sum] = solve(i+1, sum) + solve(i+1, sum + arr[i]);
}

int main(){

    scanf("%d %d", &n, &x);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0,0) << endl;

    return 0;
}