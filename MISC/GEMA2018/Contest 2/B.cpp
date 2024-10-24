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
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    cout << arr[n - 1] - arr[0] << endl;

    return 0;
}