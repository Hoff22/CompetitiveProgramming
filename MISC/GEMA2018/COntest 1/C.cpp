#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

// #define MAX 100000000

// int arr[MAX];
// int freq[MAX];

using namespace std;

int main(){
    
    int a,b;

    scanf("%d %d", &a, &b);

    int ans = (ceil((double)b / 2.0) * ceil((double)a / 2.0)) + (floor((double)b / 2.0) * floor((double)a / 2.0));

    printf("%d\n", ans);

    return 0;
}