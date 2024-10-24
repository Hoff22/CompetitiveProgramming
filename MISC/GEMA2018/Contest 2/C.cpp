#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 100000000

//int arr[10000];
int freq[1001];

using namespace std;

int main(){
    
    int n;
    cin >> n;
    string s;

    int max = 1;
    for(int i = 0; i < n; i++){
        cin >> s;     
        freq[s.size()]++;
        if(freq[s.size()] > freq[max]){
            max = s.size();
        }
    }

    cout << max << endl;

    return 0;
}