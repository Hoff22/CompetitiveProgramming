#include <bits/stdc++.h>

#define MAX 100000000

using namespace std;

int main(){
    
    long long a, b, year = 0;
    scanf("%lld %lld", &a, &b);

    while(a <= b){
        a *= 3;
        b *= 2;
        year++;
    }

    cout << year << endl;

    return 0;
}