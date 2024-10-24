#include <bits/stdc++.h>

#define N 6
#define M 7
#define INF 0x3f3f3f3f

using namespace std;


void place(int j, int player, int board[N][M]){
    for(int i = 0; i < N; i++){
        if(board[i][j] == 0){
            board[i][j] = player;
            break;
        }
    }
}

void remove(int j, int board[N][M]){
    for(int i = N - 1; i >= 0; i--){
        if(board[i][j] != 0){
            board[i][j] = 0;
            break;
        }
    }
}

void printfBoard(int board[N][M]){
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isOverVert(int player, int i, int j, int board[N][M]){
    for(int k = 0; k < 4; k++){
        if(i + k > N){
            return 0;
        }
        if(board[i+k][j] != player){
            return 0;
        }
    }
    return 1;
}

int isOverHori(int player, int i, int j, int board[N][M]){
    for(int k = 0; k < 4; k++){
        if(j + k > N){
            return 0;
        }
        if(board[i][j+k] != player){
            return 0;
        }
    }
    return 1;
}

int isOverDiag(int player, int i, int j, int board[N][M]){
    bool over = false;
    for(int k = 0; k < 4; k++){
        if(i + k >= N or j + k >= M){
            over = false;
            break;
        }
        if(board[i+k][j+k] != player){
            over = false;
            break;
        }
    }
    over = true;
    for(int k = 0; k < 4; k++){
        if(i + k >= N or j - k < 0){
            over = false;
            break;
        }
        if(board[i+k][j-k] != player){
            over = false;
            break;
        }
    }
    return over;
}

int isOver(int board[N][M]){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j]){
                if(max(isOverDiag(board[i][j], i, j, board), isOverVert(board[i][j], i, j, board))){
                    return 1;
                }
            }
        }
    }

    return 0;
}

int solve(int depth, int board[N][M]){
    if(isOver(board)){
        return 1;
    }
    if(depth == 0){
        return 0;
    }

    for(int j = 0; j < M; j++){
        if(board[N-1][j] == 0){
            
            int newBoard[N][M];
            for(int n = 0; n < N; n++){
                for(int m = 0; m < M; m++){
                    newBoard[n][m] = board[n][m];
                }
            }
            place(j, max((depth % 2)+1, 1), newBoard);
            if(solve(depth-1, newBoard)){
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    int Myboard[N][M] = {0};
    int counter = 1;

    while(!isOver(Myboard)){
        int n;

        printf("\n");
        printfBoard(Myboard);

        if(counter % 2){
            scanf("%d", &n);

            place(n - 1, 1, Myboard);
        }
        else{
            for(int j = 0; j < M; j++){
                if(solve(11, Myboard)){
                    place(j, 2, Myboard);
                    break;
                }
            }
        }

        counter++;
    }
    printf("\n");
    printfBoard(Myboard);

    return 0;
}