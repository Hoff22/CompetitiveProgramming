#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 1000

int arr[MAX][MAX];

using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    pair<int, int> place = {0, 0};
    int x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &x);
            if(x == 0){
                place.first = i;
                place.second = j;
            }
        }
    }

    printf("%d %d\n", place.first, place.second);

    return 0;
}