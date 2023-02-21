#include <iostream>
#include <stdlib.h>
#define size 10

void printBoard(char board[], int length){
    int divide = 0;
    for (int i = 0; i < length; i++) {
        if (i == 0){
            printf("   0 1 2 3 4 5 6 7 8 9");
        }
        if (i/size == divide){
            divide++;
            if (board[i] == 0) {
				printf("\n %d",divide-1);
				printf(" O");
            }else if(board[i] == 1){
				printf("\n X");
			}
			else if (board[i] == 1) {
				printf("\n X");
			}
        } else{
			if (board[i] == 0) {
				printf(" O");
			}
			else if (board[i] == 1) {
				printf(" X");
			}
        }
        
    }
}

int main()
{
    //The sense of life. https://youtu.be/dQw4w9WgXcQ
    std::cout << "Demineur of BeboUwU!\n";

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
    for (i = 1; i <= 10; i++) {
		random = rand() % 100;
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

    //Coords input
    printf("\nIndiquer une ligne: ");
    scanf_s("%d", &x);
    printf("\nIndiquer une colonne: ");
    scanf_s("%d", &y);
    printf("\nValeur x: %d, Valeur y: %d", x, y);

    //Coords insert

}

