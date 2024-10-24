#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 1000001



using namespace std;
/* 
esse solve só retorna se ganha ou perde:

int dpWin[10001];

bool solveWin(int n){
    if(n <= m){
        return true;
    }
    if(dpWin[n] != -1){
        return dpWin[n];
    }
    for(int i = 1; i <= m; i++){
        if(!solveWin(n - i)){
            return (dpWin[n] = true);
            break;
        }
    }

    return (dpWin[n] = false);
}
*/
int N, m;

int dp[10001];

int solve(int n){
    if(n <= m){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    for(int i = 1; i <= m; i++){
        if(solve(n - i) == 0){
            return dp[n] = i;
            break;
        }
    }

    return dp[n] = 0;
}

int main(){
    memset(dp, -1, sizeof(dp));

    scanf("%d %d", &N, &m);

    int win = solve(N);

    if(win){
        cout << "O Loppa vai mandar bem" << endl;
        cout << win << endl;
    }
    else{
        cout << "O Loppa vai ficar pistola" << endl;
        cout << win << endl;
    }

    return 0;
}