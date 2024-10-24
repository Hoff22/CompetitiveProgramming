#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 1000001



using namespace std;

bool solveWin(int n){
    if(n <= m){
        return true;
    }
    for(int i = 1; i <= m; i++){
        if(!solveWin(n - i)){
            return true;
            break;
        }
    }
    return false;
}
///  * * * * * * * * * * * * *
/// 3
int N, m;

int main(){

    scanf("%d %d", &N, &m);

    if(solveWin(N)){
        cout << "O Loppa vai mandar bem" << endl;
    }
    else{
        cout << "O Loppa vai ficar pistola" << endl;
    }

    return 0;
}