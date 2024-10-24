#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 1000

char arr[MAX][MAX];
bool seen[MAX][MAX];

using namespace std;

int main(){
    
    int n, m, fi, fj, i, j;
    cin >> n >> m;

    for(i = 0; i < n; i++){
        string s;
        cin >> s;
        for(j = 0; j < m; j++){
            arr[i][j] = s[j];
        }
    }

    cin >> fi >> fj;
    i = fi;
    j = fj;
    while(i < n and i >= 0 and j < m and j >= 0){
        if(seen[i][j]){
            cout << "EOQ\n";
            return 0;
            break;
        }
        else{
            seen[i][j] = true;
            switch (arr[i][j])
            {
            case 'L':
                j--;
                break;
            case 'U':
                i--;
                break;
            case 'D':
                i++;
                break;
            default:
                j++;
                break;
            }
        }
    }
    cout << "AE MLK\n";

    return 0;
}