#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 100000000

using namespace std;

int main(){
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;
    for(int i = 0; i < s.size() / 2; i++){
        if(s[i] != s[s.size() - 1 - i]){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}