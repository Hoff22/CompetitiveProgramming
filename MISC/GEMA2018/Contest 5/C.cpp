#include <bits/stdc++.h>
#define N 20

using namespace std;


int arr[N];
int x, n;

int solve(int i, int sum){
// // se o que eu quero chegou la, great adiciona um na soma daquela arvore
//     if(sum == x){
//         return 1;
//     }
// nesse caso se eu cheguei no fim do array significa que essa arvore não merece biscoito
    if(i == n){
        return sum == x;
    }
//soma das arvores em que eu peguei e em que eu não peguei
    //                V                      V
    return solve(i+1, sum + arr[i]) + solve(i+1, sum);
}
  
/*
n = 4

2^4 = 16
00001
10000

0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010

1 0 1 1
0 1 0 0
0 0 0 0

(13 ^ 6) // #bizarro

1101
0110
1011

1100
1101
1110
1111
10000

*/

int main(){

    scanf("%d %d", &n, &x);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%d\n", solve(0,0));

    return 0;
}
