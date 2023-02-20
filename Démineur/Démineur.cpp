#include <iostream>

void printBoard(int board[], int length){
    int divide = 1;
    for (int i = 0; i < length; i++) {
        if (i/10 == divide){
            divide++;
            printf("\n %d", board[i]);
        } else{
			printf(" %d", board[i]);
        }
        
    }
}

void Board (){
    int board[] = { 0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0, };

    int length = sizeof(board) / sizeof(board[0]);

    printBoard(board, length);
}

int main()
{

    std::cout << "Hello World!\n";

    Board();

}

