#include <bits/stdc++.h>

using namespace std;

int main(){

    double N, A, B;

    scanf("%lf %lf %lf", &N, &A, &B);

    double parcela1 = ((2*N)/(B+A));
    double parcela2;
    if(A == B){
        printf("%lf", parcela1);
        return 0;
    }

    if(((int)B-(int)A+1) % 2){
        parcela2 = (1/(B-A+1));
    }
    else{
        parcela2 = (1/(B-A)) * ((B-A+1)/2);
    }

    printf("%lf", parcela1 + parcela2);

    return 0;
}


