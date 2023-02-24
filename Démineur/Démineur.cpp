#include <iostream>
#include <stdlib.h>
#define size 20

void printNumbers(int clue);
int play(char trappedBoard[], char playableBoard[]);
void printBoard(char board[], int length);
int playVerif(char trappedBoard[], char playableBoard[], int x, int y, int flag);
void showArea(char trappedBoard[], char playableBoard[], int length);
void bombCreation(char trappedBoard[], int x, int y);
void boardCreation(char trappedBoard[], char playableBoard[]);
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
    else if (clue == 1){
		printf("\n  %d", clue);
    }
	else if (clue < 10) {
		printf(" %d\n  %d", clue-1, clue);
	}
	else if (clue >= 10) {
		printf(" %d\n %d", clue-1, clue);
	}
}

void boardCreation(char trappedBoard[], char playableBoard[]){
	//Boards creation
	for (int i = 0; i < size * size; i++) {
		trappedBoard[i] = 10;
		playableBoard[i] = 13;
	}
}

void bombCreation(char trappedBoard[], int x , int y) {
	//Random values init
	int i, random;
	srand(time(NULL));

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
            if (trappedBoard[i - 1] == 11 && (i - 1) % size != size - 1) {
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
}

void showArea(char trappedBoard[], char playableBoard[], int length) {
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

void prePlay(char trappedBoard[], char playableBoard[]) {
    int x;
    int y;

	printf("\nIndiquer une colonne entre (1 et %d): ", size);
	scanf_s("%d", &x);
	printf("\nIndiquer une ligne entre (1 et %d): ", size);
	scanf_s("%d", &y);

	while (x > size || x < 1 || y > size || y < 1) {
		printf("\nValeurs non valide\n");
		printf("\nIndiquer une colonne entre (1 et %d): ", size);
		scanf_s("%d", &x);
		printf("\nIndiquer une ligne entre (1 et %d): ", size);
		scanf_s("%d", &y);
    }

    boardCreation(trappedBoard, playableBoard);
    bombCreation(trappedBoard, x, y);

    while (trappedBoard[(x + (y - 1) * size) - 1] != 10) {
		boardCreation(trappedBoard, playableBoard);
		bombCreation(trappedBoard, x, y);
    }

    playableBoard[(x + (y - 1) * size) - 1] = 10;

    showArea(trappedBoard, playableBoard, size * size);

    //Boards print
    printf("\nMinesweeper :\n");
    printBoard(playableBoard, size * size);

}

int play(char trappedBoard[], char playableBoard[]) {
    int x;
    int y;
    int flag = 0;
    int isBomb;

    int answer = 0;

    printf("\nVoulez-vous mettre un drapeau ? yes = 1 or no = 0\n");
    scanf_s("%d", &answer);

	printf("\nIndiquer une colonne entre (1 et %d): ", size);
	scanf_s("%d", &x);
	printf("\nIndiquer une ligne entre (1 et %d): ", size);
	scanf_s("%d", &y);

	while (x > size || x < 1 || y > size || y < 1) {
		printf("\nValeurs non valide\n");
		printf("\nIndiquer une colonne entre (1 et %d): ", size);
		scanf_s("%d", &x);
		printf("\nIndiquer une ligne entre (1 et %d): ", size);
		scanf_s("%d", &y);
	}

    if (answer == 1) {
        flag = 1;
    }
    else {
        flag = 0;
    }

    isBomb = playVerif(trappedBoard, playableBoard, x, y, flag);

    showArea(trappedBoard, playableBoard, size*size);

	//Boards print
    printf("\nMinesweeper :\n");
    printBoard(playableBoard, size * size);

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
                printf("   ");
            }
            else if (board[i] == 11) {
                printNumbers(divide);
                cyan();
				printf("  X");
				white();
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
                printf("  .");
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
                printf("   ");
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
                printf("  .");
            }
            if (board[i] < 10)
            {
                setColor(board, i);
                printf("  %d", board[i]);
                white();
            }
        }
		if (i == (size * size) - 1) {
			for (int j = 0; j <= size; j++) {
				if (j == 0) {
					printf(" %d\n   ",size);
				}
				else if (j < 10) {
					printf("  %d", j);
				}
				else if (j >= 10) {
					printf(" %d", j);
				}

			}
		}
    }
}

int playVerif(char trappedBoard[], char playableBoard[], int x, int y, int flag) {
    int victory = 0;

    if (flag == 1 && playableBoard[(x + (y - 1) * size) - 1] == 13) {
        playableBoard[(x + (y - 1) * size) - 1] = 12;
		for (int i = 0; i < size * size; i++)
		{
			if (playableBoard[i] == 12 || playableBoard[i] == 13) {
				victory++;
			}
		}
		if (victory == (size * size) / 10) {
			return 2;
		}
		else {
			return 0;
		}
    } else if(flag == 1) {
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
            for (int i = 0; i < size * size; i++)
            {
                if (playableBoard[i] == 12 || playableBoard[i] == 13){
                    victory++;
                }
            }
            if (victory == (size * size)/10){
                return 2;
            }else{
				return 0;
            }
        }
        
    }

}

int main() {
    //The sense of life. https://youtu.be/dQw4w9WgXcQ
    std::cout << "Minesweeper of BeboUwU!\n";

    //init win/lose
    int booleanLoose = 0;

    //Boards init
    char trappedBoard[size * size];
    char playableBoard[size * size];

    prePlay(trappedBoard, playableBoard);

    while (booleanLoose == 0) {
        booleanLoose = play(trappedBoard, playableBoard);
    }
    if (booleanLoose == 2){
		printf("\n\Ganer");
    }
	else if (booleanLoose == 1) {
		printf("\n\nPedu");
    }
}