#include <bits/stdc++.h>
#include <string>

#define N 100
#define MOD (1000000000 + 7)

using namespace std;

long long dp[N+1][N+1][N+1];

long long solve(int a, int b, int c){

    if(a == 0 or b == 0 or c == 0){
        return dp[a][b][c] = 1;
    }
    if(a < 0 or b < 0 or c < 0){
        return 0;
    }

    if(dp[a][b][c] != -1){
        return dp[a][b][c];
    }

    return dp[a][b][c] =   (solve(a-b, b, c) +
                            solve(a-c, b, c) +
                            solve(a, b-a, c) +
                            solve(a, b-c, c) +
                            solve(a, b, c-a) +
                            solve(a, b, c-b)) % MOD;

}

int main(){
    
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    memset(dp, -1, sizeof(dp));

    printf("%lld\n", solve(a, b, c));
    
    return 0;
}