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

    int count = 0;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(x % 2 == 0){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}