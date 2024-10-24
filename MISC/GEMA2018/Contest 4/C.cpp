#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 1000001

int arr[MAX];
//int freq[MAX];

using namespace std;

int main(){
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d",&arr[i]);
    }
    cout << arr[(int)ceil((double)n/2.0)] << endl;
    return 0;
}