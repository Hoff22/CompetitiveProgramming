#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 100000

using namespace std;
//(x + y) * (x - y) = p;
//(x + y) = p / (x - y)
int main(){
    
    int p;
    scanf("%d", &p);
    
    if(p == 2){
        cout << 0 << endl;
        return 0;
    }

    printf("1\n");
    printf("%d %d\n", (int)ceil((double)p / 2.0), (int)floor((double)p / 2.0));

    return 0;
}