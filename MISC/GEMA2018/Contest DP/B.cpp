#include <bits/stdc++.h>
#include <string>

#define N 1000

using namespace std;

int dp[N+1][N+1];

int main(){
    
    string a, b;

    cin >> a >> b;

    for(int i = 1; i <= a.length(); i++){
        for(int j = 1; j <= b.length(); j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    printf("%d\n", dp[a.length()][b.length()]);



    return 0;
}