#include <iostream>
#include <stdlib.h>
#define size 20

void printNumbers(int clue);
int play(char trappedBoard[], char playableBoard[]);
void printBoard(char board[], int length);
int playVerif(char trappedBoard[], char playableBoard[], int x, int y);
int main();


void printNumbers(int clue) {
	if (clue == 0) {
		printf("\n   ");
	}
	else if (clue < 10) {
		printf("\n  %d", clue);
	}
	else if (clue >= 10) {
		printf("\n %d", clue);
	}
}

int play(char trappedBoard[], char playableBoard[]){
    int x;
	int y;
    int isBomb;

	printf("\nIndiquer une colonne: ");
	scanf_s("%d", &x);
	printf("\nIndiquer une ligne: ");
	scanf_s("%d", &y);
	printf("\nValeur x: %d, Valeur y: %d", x, y);

	isBomb = playVerif(trappedBoard, playableBoard, x, y);

	printf("\nUntrapped :\n");
	printBoard(playableBoard, size * size);

	printf("\n\nTrapped :\n");
	printBoard(trappedBoard, size * size);
    
    return isBomb;
}

void printBoard(char board[], int length){
    int divide = 0;
    for (int i = 0; i < length; i++) {

        if (i == 0){
			for (int j = 0; j <= size; j++) {
				if (j == 0) {
                    printf("   ");
                } else if(j < 10){
                    printf("  %d", j);
                }else if(j >= 10){
					printf(" %d", j);
                }
                
            }
        }
        if (i/size == divide){
            divide++;
            if (board[i] == 0) {
                printNumbers(divide);
				printf("  O");
			}
			else if (board[i] == 1) {
				printNumbers(divide);
				printf("  X");
			}
			else if (board[i] == 2) {
				printNumbers(divide);
				printf("  $");
			}
        } else{
			if (board[i] == 0) {
				printf("  O");
			}
			else if (board[i] == 1) {
				printf("  X");
			}
			else if (board[i] == 2) {
				printf("  $");
			}
        }
        
    }
}

int playVerif(char trappedBoard[], char playableBoard[], int x , int y){
    if (playableBoard[(x + (y-1) * size) - 1] == 0) {
        playableBoard[(x + (y-1) * size) - 1] = 2;
    }
    if (trappedBoard[(x + (y - 1) * size) - 1] == 1){
        printf("\t\nBomb right there");

        return 1;
    } else{
        printf("\t\nOnly luck");
        return 0;
    }
    
}

int main()
{
    //The sense of life. https://youtu.be/dQw4w9WgXcQ
    std::cout << "Minesweeper of BeboUwU!\n";

    //init win/lose
	int booleanWin = 0;
	int booleanLoose = 0;

    //Boards init
	char trappedBoard[size * size];
	char playableBoard[size * size];
    
    //Random values init
	int i, random;
	srand(time(NULL));

    //Coords Init
    int x = 0;
    int y = 0;

    //Boards creation
    for (int i = 0; i < size * size; i++) { 
		trappedBoard[i] = 0;
		playableBoard[i] = 0;
    }
    
    //Random Creation
    for (int i = 1; i <= (size*size)/10; i++) {
        int bombNumber = size * size;
		random = rand() % bombNumber; 
        if (trappedBoard[random] == 1) {
            i--;
        }
        trappedBoard[random] = 1;
    }

    //Boards print
    printf("\nUntrapped :\n");
	printBoard(playableBoard, size * size);

    printf("\n\nTrapped :\n");
    printBoard(trappedBoard, size * size);

    while (booleanLoose == 0 && booleanWin == 0) {
		booleanLoose = play(trappedBoard, playableBoard);
        printf("truc: %d", booleanLoose);
    }
}