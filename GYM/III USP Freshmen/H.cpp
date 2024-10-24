#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;


int main(){

    int l, r, m;
    char a;

    l = 0;
    r = MAX;

    while(l <= r){
        m = (l+r)/2;

        printf("Q %d", m);
        cout.flush();

        scanf(" %c", &a);

        if(a == '<'){
            r = m-1;
        }
        else if(a == '>'){
            l = m+1;
        }
        else{
            break;
        }
    }
    
    

    return 0;

}
// 2 2
// 2 1
// 1 0