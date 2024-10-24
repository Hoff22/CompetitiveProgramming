#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define N 1001

char arr[N][N];
bool seen[N][N];
//int freq[MAX];
int n, m, ans = 0;

void propagate(char dir, int i, int j){

    if(i >= n or j >= m or i < 0 or j < 0){
        return;
    }

    if(arr[i][j] != dir){
        if(arr[i][j] == '#'){
            return;
        }
        if(arr[i][j] != '.' and !seen[i][j]){
            propagate(arr[i][j], i, j);
        }
    }

    seen[i][j] = true;
        
    if(dir == 'R'){
        arr[i][j] = 'R';
        propagate('R', i, j + 1);
    }
    if(dir == 'L'){
        arr[i][j] = 'L';
        propagate('L', i, j - 1);
    }
    if(dir == 'U'){
        arr[i][j] = 'U';
        propagate('U', i - 1, j);        
    }
    if(dir == 'D'){
        arr[i][j] = 'D';
        propagate('D', i + 1, j);    
    }
}

using namespace std;

int main(){
    
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &arr[i][j]);
        }
    }

    memset(seen, 0, sizeof(seen));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            propagate(arr[i][j], i, j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '.'){
                ans++;
            }
        }
    }


    if(ans == 0){
        printf("NO SOLUTION\n");
    }
    else if(ans < 2){
        printf("ONLY ONE SOLUTION\n");
    }
    else{
        printf("MULTIPLE SOLUTIONS\n");
    }

    return 0;
}