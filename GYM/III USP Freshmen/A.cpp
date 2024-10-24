#include <bits/stdc++.h>

#define N 1000000000
#define MAX 10000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){

    long long n;
    scanf("%lld", &n);

    long long sum;

    sum = n*(n+1)/2;
    // 1 2 3 4 
    // 1 3 6 10
    //  2 3 4

    printf("%lld\n", sum /*- (n-1)*/);

    return 0;

}