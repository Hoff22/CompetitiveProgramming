#include <bits/stdc++.h>

#define N 1000000000
#define MAX 10000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){

    int x1, y1, x2, y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    long long d1 = x1*x1 + y1*y1;
    long long d2 = x2*x2 + y2*y2;

    if(d1 < d2){
    	printf("Russo\n");
    }
    else if(d1 > d2){
    	printf("Wil\n");
    }
    else{
    	printf("Empate\n");
    }

    return 0;

}

// 2 2
// 2 1
// 1 0

//