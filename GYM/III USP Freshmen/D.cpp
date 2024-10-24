#include <bits/stdc++.h>

#define N 100000
#define MAX 10000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int n;
int a[N+1];

int main(){
    long long ans = 0;
    long long sum = 0;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }

    long long correction = 0;
    for(int i = 1; i < n; i++){
        correction += a[i];
        ans += a[i] * (sum - correction);
    }

    // a b c = 
    // a*b + b*c + a*c =
    // a*(b+c) + b*(c+a) + c*(a+b)

    printf("%lld", ans);

    return 0;

}