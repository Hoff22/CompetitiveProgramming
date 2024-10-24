#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int n;
int a[N+1];

bool choose(const int x, const int b){
    return x > b;
}

int main(){

    int odds;
    long long ans = 0;

    scanf("%d", &n);

    odds = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] % 2) odds++;
    }

    sort(a+1, a+1+n, choose);

    for(int i = 1; i <= n; i++){
        if(a[i] % 2){
            if(odds > 1 or ans % 2){
                ans += a[i];
                odds--;
            }
        }
        else{
            ans += a[i];
        }
    }

    printf("%lld\n", ans);
    

    return 0;

}