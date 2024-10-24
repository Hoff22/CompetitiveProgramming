#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;


int main(){

    int n, s;
    long long ans = 0;
    int a[N+1];

    scanf("%d %d", &n, &s);

    for(int i = 0; i < n; i++){
        int t, e;
        scanf("%d %d", &t, &e);

        a[i] = t + (s - e);
    }

    sort(a, a+n);

    for(int i = 0; i < n; i++){
        //printf("%d ", a[i]);
        ans = max((ans - s), 0ll) + ans + a[i];
    }

    printf("%lld\n", ans);
    

    return 0;

}
// 2 2
// 2 1
// 1 0