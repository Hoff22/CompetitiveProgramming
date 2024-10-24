#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 100000

using namespace std;

int main(){
    
    int ans = 0;
    string T, S;
    
    cin >> T;
    cin >> S; 

    for(int i = 0; i < (int)S.size(); i++){
        if(T[i] != S[i]){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}