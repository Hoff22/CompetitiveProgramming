#include <bits/stdc++.h>

using namespace std;

char MyBoard[3][3];

void drawBoard(char board[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%c", board[i][j]);
			if(j < 2){
				printf("|");
			}
			if(i < 2 and j == 2){
				printf("\n-+-+-\n");
			}
		}
	}
}

void place(int i, int j, int player, char board[3][3]){
	if(player == 1){
		board[i][j] = 'x';
	}
	else if(player == 2){
		board[i][j] = 'o';
	}
}

int isOver(char board[3][3]){
	for(int i = 0; i < 3; i++){
		if(board[i][0] == 'o'){
			if(board[i][1] == 'o' and board[i][2] == 'o'){
				return 2;
			}
		}

		if(board[i][0] == 'x'){
			if(board[i][1] == 'x' and board[i][2] == 'x'){
				return 1;
			}
		}
	}

	if(board[0][0] == 'o' and board[1][1] == 'o' and board[2][2] == 'o'){
		return 2;
	}

	if(board[0][0] == 'x' and board[1][1] == 'x' and board[2][2] == 'x'){
		return 1;
	}

	for(int j = 0; j < 3; j++){
		if(board[0][j] == 'o'){
			if(board[1][j] == 'o' and board[1][j] == 'o'){
				return 2;
			}
		}

		if(board[0][j] == 'x'){
			if(board[1][j] == 'x' and board[2][j] == 'x'){
				return 1;
			}
		}
	}
	int count = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[i][j] == '.') count++;
		}
	}
	if (!count){
		return 3;
	}
	return 0;
}

void clearBoard(char board[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			board[i][j] = '.';
		}
	}
}

int main(){

	int count = 0;
	int i, j;
	int player;

	clearBoard(MyBoard);

	while(!isOver(MyBoard)){
		player = (count % 2) + 1;
		
		system("clear");

		drawBoard(MyBoard);
		printf("\n\n");	
		
		printf("[player %d] jogada i j: ", player);
		scanf("%d%d", &i, &j);
		while(MyBoard[i-1][j-1] != '.'){
			printf("[player %d] jogada i j: ", player);
			scanf("%d%d", &i, &j);			
		}

		place(i-1, j-1, player, MyBoard);

		count++;
	}

	system("clear");
	drawBoard(MyBoard);
	printf("\n");

	if(isOver(MyBoard) == 3){
		printf("Deu Velha\n");
	}
	else{
		printf("Player %d venceu!!\n", player);
	}

	return 0;
}