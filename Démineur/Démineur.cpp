#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printNumbers(int clue);
void printBoard(int* board, int size);
int playVerif(int* trappedBoard, int* playableBoard, int x, int y, int flag, int size);
void showArea(int* trappedBoard, int* playableBoard, int size);
void bombCreation(int* trappedBoard, int x, int y, int size);
int play(int* trappedBoard, int* playableBoard, int size);
void boardCreation(int* trappedBoard, int* playableBoard);
void prePlay(int* trappedBoard, int* playableBoard, int size);
void showMine(int* trappedBoard, int* playableBoard, int size);
int main();
void red();
void white();
void green();
void cyan();
void yellow();
void blue();
void setColor(int* board, int i);

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

void setColor(int* board, int i) {
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

int isInt(){
	char entree[100];
	int nombre;
	char* fin;
	printf("Entrez un nombre entier : ");
	while (fgets(entree, 100, stdin) != NULL) {
		// Supprimer le caractère de retour à la ligne à la fin de l'entrée
		entree[strcspn(entree, "\n")] = '\0';
		// Vérifier si l'entrée est un nombre entier valide
		if (isdigit(entree[0]) || entree[0] == '+' || entree[0] == '-') {
			nombre = strtol(entree, &fin, 10);
			if (*fin == '\0') {
				printf("Vous avez entré le nombre entier %d.\n", nombre);
                return nombre;
				break;
			}
		}
		printf("Erreur : veuillez entrer un nombre entier valide.\n");
		printf("Entrez un nombre entier : ");
	}
}

void printNumbers(int clue) {
    if (clue == 0) {
        printf("\n   ");
    }
    else if (clue == 1) {
        printf("\n  %d", clue);
    }
    else if (clue < 10) {
        printf(" %d\n  %d", clue - 1, clue);
    }
    else if (clue >= 10) {
        printf(" %d\n %d", clue - 1, clue);
    }
}

void bombCreation(int* trappedBoard, int x, int y, int size) {
    //Random values init
    int i, random;
    srand(time(NULL));

    //Random Creation Bomb
    for (int i = 1; i <= (size * size) / 10; i++) {
        int bombNumber = size * size;
        random = rand() % bombNumber;
        if ((random >= (x + (y - 1) * size) - 2 && random <= x + (y - 1) * size) || (random >= (x + (y - 1) * size) - 2 - size && random <= (x + (y - 1) * size) - size) || (random >= (x + (y - 1) * size) - 2 + size && random <= (x + (y - 1) * size) + size)) {
            random += 3;
        }
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

void showArea(int* trappedBoard, int* playableBoard, int size) {
    int isO = 1;
    while (isO == 1) {
        isO = 0;
        for (int i = 0; i < size * size; i++)
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

void showMine(int* trappedBoard, int* playableBoard, int size) {
    for (int i = 0; i < size * size; i++) {
        if (trappedBoard[i] == 11) {
            printf("\n");
            Sleep(400);
			playableBoard[i] = 11;
			printBoard(playableBoard, size);
        }
    }
}

void prePlay(int* trappedBoard, int* playableBoard, int size) {
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

    bombCreation(trappedBoard, x, y, size);



    playableBoard[(x + (y - 1) * size) - 1] = 10;

    showArea(trappedBoard, playableBoard, size);

    //Boards print
    printf("\nMinesweeper :\n");
    printBoard(playableBoard, size);

}

int play(int* trappedBoard, int* playableBoard, int size) {
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

    isBomb = playVerif(trappedBoard, playableBoard, x, y, flag, size);

    showArea(trappedBoard, playableBoard, size);

    //Boards print
    printf("\nMinesweeper :\n");
    printBoard(playableBoard, size);

    return isBomb;
}

void printBoard(int* board, int size) {
    int divide = 0;
    for (int i = 0; i < size * size; i++) {

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
                    printf(" %d\n   ", size);
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

int playVerif(int* trappedBoard, int* playableBoard, int x, int y, int flag, int size) {
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
    }
    else if (flag == 1) {
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
        }

    }

}

int main() {
    //The sense of life. https://youtu.be/dQw4w9WgXcQ
    std::cout << "Minesweeper of BeboUwU!\n";

    //init win/lose
    int booleanLoose = 0;

    //Boards init

	int size = 0;
	printf("Taille entre 5 et 30 (un entier pls): ");
	size = isInt();

    while (size < 5 || size > 30) {
		size = isInt();
    }
	int* playableBoard = (int*)malloc(sizeof(int) * (size * size));
	int* trappedBoard = (int*)malloc(sizeof(int) * (size * size));

	for (int i = 0; i < size * size; i++) {
		trappedBoard[i] = 10;
		playableBoard[i] = 13;
	}

    prePlay(trappedBoard, playableBoard, size);

    while (booleanLoose == 0) {
        booleanLoose = play(trappedBoard, playableBoard, size);
    }
    if (booleanLoose == 2) {
        printf("\n\Ganer\n");
    }
    else if (booleanLoose == 1) {
		showMine(trappedBoard, playableBoard, size);
		printf("\n\nPedu\n");
    } 

}