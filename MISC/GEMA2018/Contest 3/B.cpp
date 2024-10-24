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
    
    int n, h;
    cin >> n >> h;
    int cur = 0;
    int last;
    cin >> last;
    int ans = 0;
    for(int i = 1; i < n; i++){
        cin >> cur;
        ans += abs(cur - last) * 4;
        last = cur;
    }

    cout << ans << endl;

    return 0;
}