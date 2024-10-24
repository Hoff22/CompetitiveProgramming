#include <bits/stdc++.h>

// #include <iostream>
// #include <chrono>
// #include <string>
// #include <fstream>
// #include <math.h>
// #include <sstream>

#define MAX 1000001

long long arr[MAX];
long long ans[10001];

using namespace std;

int main(){
    
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        long long num;
        scanf("%lld", &num);
        if(i == 1){
            arr[i] = num;
        }
        else{
            arr[i] = arr[i - 1] + num;
        }
    }

    cin >> n;

    for(int i = 1; i <= n; i++){
        int l, r;
        scanf("%d %d", &l, &r);

        ans[i] = arr[r] - arr[l - 1];
    }
    
    for(int i = 1; i <= n; i++){
        printf("%lld\n", ans[i]);
    }

    return 0;
}