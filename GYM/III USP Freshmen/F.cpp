#include <bits/stdc++.h>

#define N 1000000000
#define MAX 10000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){

    int n;

    scanf("%d", &n);

    int sum = 0;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        sum += x;
    }
    if(!(sum % 5)){
        printf("%d", sum/5);
    }
    else{
        printf("%d", sum/5 + 1);
    }

    return 0;

}