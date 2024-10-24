#include <bits/stdc++.h>

#define N 100000
#define MAX 10000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int n;

int main(){

    scanf("%d", &n);

    while(n--){
        int a, b;
        scanf("%d %d", &a, &b);

        if(max(a,b) - min(a,b) > 1){
            printf("%d %d\n", (a+b)/2, (a+b+1)/2);
        }
        else{
            printf("Ok\n");
        }
    }

    

    return 0;

}