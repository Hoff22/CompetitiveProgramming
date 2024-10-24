#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

using namespace std;
/*
8
div:
1 = 1, 1, 1, 1, 1, 1 - 5 - (1, 5) - (1, 1, 4) - (1, 1, 2, 2)  - (1, 1, 1, 3) - (1, 1, 1, 1, 2) - (1, 1, 1, 1, 1, 1)
2 = 2, 2, 2 ---------- 2 - (2, 4) - (2, 2, 2)
3 = 3, 3 ------------- 1 - (3, 3)
6 = 6 ---------------- 1 - (6)

4
1 - (1, 1, 1, 1) - (1, 1, 2) - (1, 3)
2 - (2, 2)
4- (4)

1, 1, 1, 1, 1, 1

*/
int dp[1001][1001];

int solve(int x, int last){
    if(x == 0){
        return 1;
    }
    
    if(dp[x][last] != -1){
        return dp[x][last];
    }
    // if(x < last){
    //     return 0;
    // }
    int ans = 0;
    for(int i = 1; i * last <= x; i++){
        ans += solve(x - i * last, i * last);
    }
    return dp[x][last] = ans;
}
int solve2(int x, int last){
    if(x == 0){
        return 1;
    }
    // if(x < last){
    //     return 0;
    // }
    int ans = 0;
    for(int i = 1; i * last <= x; i++){
        ans += solve2(x - i * last, i * last);
    }
    return ans;
}

int main(){
    
    int n;
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    cout << solve(n, 1) << endl;

    return 0;
}