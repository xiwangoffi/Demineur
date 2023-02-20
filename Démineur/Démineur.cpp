#include <iostream>

void Board (){
    int divide = 1;
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
    for (int i = 0; i < length; i++) {
        if (i/10 == divide){
            divide++;
            printf("\n %d", board[i]);
        } else{
			printf(" %d", board[i]);
        }
        //printf("%d ", x[i]);
        
    }
}

int main()
{

    std::cout << "Hello World!\n";

    Board();

}

