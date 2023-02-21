#include <iostream>
#include <stdlib.h>
#define size 10

void printBoard(char board[], int length){
    int divide = 1;
    for (int i = 0; i < length; i++) {
        if (i/size == divide){
            divide++;
            if (board[i] == 0) {
                printf("\n O");
            }else if(board[i] == 1){
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
    char board[size * size];

	int i, n;

	srand(time(NULL));

    std::cout << "Démineur de Bebou UWU!\n";

    for (int i = 0; i < size * size; i++) {
        board[i] = 0;
    }
    

	for (i = 1; i <= 10; i++) {
		n = rand() % 100;
		printf("%d\n", n);
        if (board[n] == 1){
            i--;
        }
        board[n] = 1;
	}

    printBoard(board, size * size);

}

