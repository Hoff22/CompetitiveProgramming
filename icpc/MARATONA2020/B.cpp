#include <bits/stdc++.h>
#define N 100000

using namespace std;

int ships[100][100];
bool board[11][11];

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &ships[i][0], &ships[i][1], &ships[i][2], &ships[i][3]);
    }

    for(int i = 0; i < n; i++){
        int d = ships[i][0];
        int l = ships[i][1];
        int r = ships[i][2];
        int c = ships[i][3];

        if(d){
            // vertical:
            if(r+l-1 > 10){
                printf("N");
                return 0;
            }
            for(int j = r; j < r+l; j++){
                if(board[j][c]){
                    printf("N");
                    return 0; 
                }
                else{
                    board[j][c] = true;
                }
            }
        }
        else{
            // horizontal:
            if(c+l-1 > 10){
                printf("N");
                return 0;
            }
            for(int j = c; j < c+l; j++){
                if(board[r][j]){
                    printf("N");
                    return 0; 
                }
                else{
                    board[r][j] = true;
                }
            }
        }
    }

    printf("Y");

    return 0;
}


