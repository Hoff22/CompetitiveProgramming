#include <bits/stdc++.h>
#define N 40

using namespace std;

char arr[N][N];
int arr2[N][N];

int main(){

    int l, c, n;

    scanf("%d %d", &l, &c);

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }

    return 0;
}


