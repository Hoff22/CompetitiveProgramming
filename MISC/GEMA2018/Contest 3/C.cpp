#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 100

long long arr[MAX][MAX];
//int freq[MAX];

using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%lld", &arr[i][j]);
        }
    }

    for(int j = 0; j < m; j++){
        bool pattern = true;
        for(int i = 1; i < n; i++){
            // igual
            if(arr[1][j] == arr[0][j]){
                if(arr[i][j] != arr[i - 1][j]){
                    pattern = false;
                }
            }
            // crescente
            else if(arr[1][j] > arr[0][j]){
                if(arr[i][j] < arr[i - 1][j]){
                    pattern = false;
                }
            }
            // decrescente
            else{
                if(arr[i][j] > arr[i - 1][j]){
                    pattern = false;
                }
            }
        }
        if(pattern){
            cout << "S" << endl;
        }
        else{
            cout << "N" << endl;
        }
    }
    return 0;
}