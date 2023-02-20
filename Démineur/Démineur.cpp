#include <iostream>

void Board (){
    int divide = 0;
    int board[] = { 0,1,2,3,4,5,6,7,8,9,
                    0,1,2,3,4,5,6,7,8,9,
                    0,1,2,3,4,5,6,7,8,9,
                    0,1,2,3,4,5,6,7,8,9,
                    0,1,2,3,4,5,6,7,8,9,
                    0,1,2,3,4,5,6,7,8,9,
                    0,1,2,3,4,5,6,7,8,9,
                    0,1,2,3,4,5,6,7,8,9,
                    0,1,2,3,4,5,6,7,8,9,
                    0,1,2,3,4,5,6,7,8,9, };
    int length = sizeof(board) / sizeof(board[0]);
    for (int i = 0; i < length; i++) {
        //printf("%d ", x[i]);
        printf("Chiffre: %d", i / 10);
    }
}

int main()
{

    std::cout << "Hello World!\n";

    Board();

}

