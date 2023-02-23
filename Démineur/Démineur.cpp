#include <iostream>
#include <stdlib.h>
#define size 20

void printNumbers(int clue);
int play(char trappedBoard[], char playableBoard[]);
void printBoard(char board[], int length);
int playVerif(char trappedBoard[], char playableBoard[], int x, int y, int flag);
void showArea(char trappedBoard[], char playableBoard[], int x, int y, int length);
int main();
void red();
void white();
void green();
void cyan();
void yellow();
void blue();

void red() {
    printf("\033[0;31m");
}

void white() {
    printf("\033[0;37m");
}
void green() {
    printf("\033[0;32m");
}

void cyan() {
    printf("\033[0;36m");
}

void yellow() {
    printf("\033[0;33m");
}

void magenta() {
    printf("\033[0;35m");
}

void blue() {
    printf("\033[0;34m");
}

void setColor(char board[], int i) {
    if (board[i] == 1 || board[i] == 2) {
        green();
    }
    else if (board[i] == 3 || board[i] == 4) {
        yellow();
    }
    else if (board[i] == 5 || board[i] == 6) {
        magenta();
    }
    else if (board[i] == 7 || board[i] == 8) {
        red();
    }
}

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

void showArea(char trappedBoard[], char playableBoard[], int x, int y, int length) {
    int isO = 1;
    while (isO == 1){
        isO = 0;
		for (int i = 0; i < length; i++)
		{
			if (playableBoard[i] == 13)
			{
				//Verify O Right
				if (playableBoard[i + 1] == 10 && (i + 1) % size != 0) {
					playableBoard[i] = trappedBoard[i];
					isO = 1;
				}
				//Verify O Left
				else if (playableBoard[i - 1] == 10 && (i - 1) % size != size - 1) {
                    playableBoard[i] = trappedBoard[i];
					isO = 1;
				}
				//Verify O Up
				else if (playableBoard[i - size] == 10 && i >= size) {
                    playableBoard[i] = trappedBoard[i];
					isO = 1;
				}
				//Verify O Down
				else if (playableBoard[i + size] == 10 && i <= (size * size) - size) {
                    playableBoard[i] = trappedBoard[i];
					isO = 1;
				}

				//Verify O Right Up
				else if (playableBoard[i - (size - 1)] == 10 && i >= size && (i + 1) % size != 0 && i != 0) {
                    playableBoard[i] = trappedBoard[i];
					isO = 1;
				}
				//Verify O Left Up
				else if (playableBoard[i - (size + 1)] == 10 && i >= size && (i - 1) % size != size - 1) {
                    playableBoard[i] = trappedBoard[i];
					isO = 1;
				}
				//Verify O Right Down
				else if (playableBoard[i + (size + 1)] == 10 && i <= (size * size) - size && (i + 1) % size != 0) {
                    playableBoard[i] = trappedBoard[i];
					isO = 1;
				}
				//Verify O Left Down
				else if (playableBoard[i + (size - 1)] == 10 && i <= (size * size) - size && (i - 1) % size != size - 1 && i != 0) {
                    playableBoard[i] = trappedBoard[i];
					isO = 1;
				}
			}
		}
    }
    
}

int play(char trappedBoard[], char playableBoard[]) {
    int x;
    int y;
    int flag = 0;
    int isBomb;

    int answer = 0;

    printf("\nVoulez-vous mettre un drapeau ? yes = 1 or no = 0\n");
    scanf_s("%d", &answer);

    printf("\nIndiquer une colonne: ");
    scanf_s("%d", &x);
    printf("\nIndiquer une ligne: ");
    scanf_s("%d", &y);
    printf("\nValeur x: %d, Valeur y: %d", x, y);

    if (answer == 1) {
        flag = 1;
    }
    else {
        flag = 0;
    }

    isBomb = playVerif(trappedBoard, playableBoard, x, y, flag);

    showArea(trappedBoard, playableBoard, x, y, size*size);

    printf("\nUntrapped :\n");
    printBoard(playableBoard, size * size);

    printf("\n\nTrapped :\n");
    printBoard(trappedBoard, size * size);

    return isBomb;
}

void printBoard(char board[], int length) {
    int divide = 0;
    for (int i = 0; i < length; i++) {

        if (i == 0) {
            for (int j = 0; j <= size; j++) {
                if (j == 0) {
                    printf("   ");
                }
                else if (j < 10) {
                    printf("  %d", j);
                }
                else if (j >= 10) {
                    printf(" %d", j);
                }

            }
        }
        if (i / size == divide) {
            divide++;
            if (board[i] == 10) {
                printNumbers(divide);
                white();
                printf("  O");
            }
            else if (board[i] == 11) {
                printNumbers(divide);
                cyan();
                printf("  X");
            }
            else if (board[i] == 12) {
                printNumbers(divide);
                blue();
                printf("  F");
                white();
            }
            else if (board[i] == 13) {
                printNumbers(divide);
                white();
                printf("  ?");
            }
            if (board[i] < 10)
            {
                printNumbers(divide);
                setColor(board, i);
                printf("  %d", board[i]);
                white();
            }
        }
        else {
            if (board[i] == 10) {
                white();
                printf("  O");
            }
            else if (board[i] == 11) {
                cyan();
                printf("  X");
                white();
            }
            else if (board[i] == 12) {
                blue();
                printf("  F");
                white();
            }
            else if (board[i] == 13) {
                white();
                printf("  ?");
            }
            if (board[i] < 10)
            {
                setColor(board, i);
                printf("  %d", board[i]);
                white();
            }
        }

    }
}

int playVerif(char trappedBoard[], char playableBoard[], int x, int y, int flag) {
    if (flag == 1) {
        playableBoard[(x + (y - 1) * size) - 1] = 12;
        return 0;
    }
    else {
        if (trappedBoard[(x + (y - 1) * size) - 1] == 11) {
            printf("\t\nBomb right there");
            return 1;
        }
        else {
            printf("\t\nOnly luck");
            playableBoard[(x + (y - 1) * size) - 1] = trappedBoard[(x + (y - 1) * size) - 1];
            return 0;
        }
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
        trappedBoard[i] = 10;
        playableBoard[i] = 13;
    }

    //Random Creation Bomb
    for (int i = 1; i <= (size * size) / 10; i++) {
        int bombNumber = size * size;
        random = rand() % bombNumber;
        if (trappedBoard[random] == 11) {
            i--;
        }
        trappedBoard[random] = 11;
    }

    //Verif Number Bomb
    for (int i = 0; i < size * size; i++)
    {
        int numberBomb = 0;
        if (trappedBoard[i] != 11) {

            //Verify Bomb Right
            if (trappedBoard[i + 1] == 11 && (i + 1) % size != 0) {
                numberBomb++;
            }
            //Verify Bomb Left
            if (trappedBoard[i - 1] == 11 && (i - 1) % size != size-1) {
                numberBomb++;
            }
            //Verify Bomb Up
            if (trappedBoard[i - size] == 11 && i >= size) {
                numberBomb++;
            }
            //Verify Bomb Down
            if (trappedBoard[i + size] == 11 && i <= (size * size) - size) {
                numberBomb++;
            }

            //Verify Bomb Right Up
            if (trappedBoard[i - (size - 1)] == 11 && i >= size && (i + 1) % size != 0 && i != 0) {
                numberBomb++;
            }
            //Verify Bomb Left Up
            if (trappedBoard[i - (size + 1)] == 11 && i >= size && (i - 1) % size != size - 1) {
                numberBomb++;
            }
            //Verify Bomb Right Down
            if (trappedBoard[i + (size + 1)] == 11 && i <= (size * size) - size && (i + 1) % size != 0) {
                numberBomb++;
            }
            //Verify Bomb Left Down
            if (trappedBoard[i + (size - 1)] == 11 && i <= (size * size) - size && (i - 1) % size != size - 1) {
                numberBomb++;
            }

            //Verify if is Bomb
            if (numberBomb != 0)
            {
                trappedBoard[i] = numberBomb;
            }
        }
    }
    //Boards print
    printf("\nUntrapped :\n");
    printBoard(playableBoard, size * size);

    printf("\n\nTrapped :\n");
    printBoard(trappedBoard, size * size);

    while (booleanLoose == 0 && booleanWin == 0) {
        booleanLoose = play(trappedBoard, playableBoard);
    }
    printf("\n\nPedu");
}