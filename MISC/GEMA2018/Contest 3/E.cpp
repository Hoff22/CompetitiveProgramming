#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 1000000000

int n;
int b;

using namespace std;

int main(){
    
    long long ans = 0;	

    scanf("%d %d", &n, &b);


    long long nTerm = (b - n) + 1;
    ans = (b + nTerm) * n / 2;

    printf("%lld\n", ans);

    return 0;
}