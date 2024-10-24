#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 3

int arr[MAX];
int freq[MAX];

using namespace std;

int main(){
    
    for(int i = 0; i < 3; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + 3);

    reverse(arr, arr + 3);

    for(int i = 0; i < 3; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}