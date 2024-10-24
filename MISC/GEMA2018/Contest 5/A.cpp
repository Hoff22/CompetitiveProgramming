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
    
    string T;
    
    cin >> T;

    int i = 0;
    while(T[i] != '\0'){
        i++;
        if(T[i- 1] == 'a' or T[i- 1] == 'e' or T[i- 1] == 'i' or T[i- 1] == 'o' or T[i- 1] == 'u'){
            if(T[i] == 'a' or T[i] == 'e' or T[i] == 'i' or T[i] == 'o' or T[i] == 'u'){
                T.erase(T.begin()+i);
                i--;
            }
        }
        // r a c a c a a s o o u i u i u \0
        // 0 1 0 1 0 1 1 0 1 1 1 1 1 1 1 
        // 0 1 2 3 4 5 6 7 8 9 A B C D E
        // r a c a c a a s o o u i u i u \0
        // 0 1 0 1 0 1 1 0 1 1 1 1 1 1 1
    }

    cout << T << endl;

    return 0;
}