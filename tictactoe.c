#include <stdio.h>
#include <time.h>

#ifdef __linux__ 
    #include <unistd.h>
    #define clear "clear"
#elif _WIN32
    #include <windows.h>
    #define clear "cls"
#else
    #error "OS not supported!"
#endif

void menu();

void game();

void tryagain(){ 
    int menuTryAgain;

    printf("\n\tDo you wanna try again?\n");

    printf("[1] Try Again\n");
    printf("[2] Exit\n\n");

    do{
    printf("Enter: ");
    scanf("%d", &menuTryAgain);
    }while((menuTryAgain < 1) || (menuTryAgain > 2));

    switch (menuTryAgain){
        case 1:
            system(clear);
            game();
            break;
        case 2:
            exit(0);
            break;
    }

}

void game(){
    char game[3][3] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    int i, j, winner = 0, round = 2;

    srand(time(NULL));

    printf("\tRound 1\n");

    printf("\n   1 2 3 ");
    printf("\n  -------\n");
    for(i = 0; i < 3; i++){
        printf("%d |", i + 1);
        for(j = 0; j < 3; j++){
            printf("%c|", game[i][j]);
        }
        printf("\n  -------\n");
    }
    
    printf("\n\nYou begin. You are \'X\'...\n");
    
    do{
    printf("Enter your row: ");
    scanf("%d", &i);
    }while((i < 1) || (i > 3));

    do{
    printf("Enter your column: ");
    scanf("%d", &j);
    }while((j < 1) || (j > 3));
    
    i--;
    j--;
    game[i][j] = 'X';

    do{
        
        if((game[0][0] != '.') && (game[0][1] != '.') && (game[0][2] != '.') &&
            (game[1][0] != '.') && (game[1][1] != '.') && (game[1][2] != '.') &&
            (game[2][0] != '.') && (game[2][1] != '.') && (game[2][2] != '.')){
                
                printf("\n\tI'm Sorry...No one won\n");
                break;
            }
            
        system(clear);

        printf("\tRound %d\n", round);

        round++;

        

        do{
            i = rand() % 3;
            j = rand() % 3;
        }while((game[i][j] == 'X') || (game[i][j] == 'O'));

        game[i][j] = 'O';

        if(((game[0][0] == 'O') && (game[0][1] == 'O') && (game[0][2] == 'O')) ||
            ((game[1][0] == 'O') && (game[1][1] == 'O') && (game[1][2] == 'O')) ||
            ((game[2][0] == 'O') && (game[2][1] == 'O') && (game[2][2] == 'O')) ||
            ((game[0][0] == 'O') && (game[1][0] == 'O') && (game[2][0] == 'O')) ||
            ((game[0][1] == 'O') && (game[1][1] == 'O') && (game[2][1] == 'O')) ||
            ((game[0][2] == 'O') && (game[1][2] == 'O') && (game[2][2] == 'O')) ||
            ((game[0][0] == 'O') && (game[1][1] == 'O') && (game[2][2] == 'O')) ||
            ((game[0][2] == 'O') && (game[1][1] == 'O') && (game[2][0] == 'O'))){
                
                printf("\n\n-------\n");
                for(i = 0; i < 3; i++){
                    printf("|");
                    for(j = 0; j < 3; j++){
                    printf("%c|", game[i][j]);
                    }
                    printf("\n-------\n");

                }

                printf("\n\tI'm Sorry...You lose\n");
                winner = 2;
                break;
            }

        printf("\n   1 2 3 ");
        printf("\n  -------\n");
        for(i = 0; i < 3; i++){
            printf("%d |", i + 1);
            for(j = 0; j < 3; j++){
            printf("%c|", game[i][j]);
            }
            printf("\n  -------\n");

        }

        do{

            do{
            printf("Enter your row: ");
            scanf("%d", &i);
            }while((i < 1) || (i > 3));

            do{
            printf("Enter your column: ");
            scanf("%d", &j);
            }while((j < 1) || (j > 3));

            i--;
            j--;

        }while((game[i][j] == 'X') || (game[i][j] == 'O'));

        game[i][j] = 'X';

        if(((game[0][0] == 'X') && (game[0][1] == 'X') && (game[0][2] == 'X')) ||
            ((game[1][0] == 'X') && (game[1][1] == 'X') && (game[1][2] == 'X')) ||
            ((game[2][0] == 'X') && (game[2][1] == 'X') && (game[2][2] == 'X')) ||
            ((game[0][0] == 'X') && (game[1][0] == 'X') && (game[2][0] == 'X')) ||
            ((game[0][1] == 'X') && (game[1][1] == 'X') && (game[2][1] == 'X')) ||
            ((game[0][2] == 'X') && (game[1][2] == 'X') && (game[2][2] == 'X')) ||
            ((game[0][0] == 'X') && (game[1][1] == 'X') && (game[2][2] == 'X')) ||
            ((game[0][2] == 'X') && (game[1][1] == 'X') && (game[2][0] == 'X'))){

                printf("\n\n-------\n");
                for(i = 0; i < 3; i++){
                    printf("|");
                    for(j = 0; j < 3; j++){
                    printf("%c|", game[i][j]);
                    }
                    printf("\n-------\n");

                }

                printf("\n\tCongratulations. You won!!\n");
                winner = 1;
            }

        
    }while((winner == 0));

    tryagain();

}

void menu(){ 
    int menuTTT;
    printf("\tWelcome to Tic Tac Toe\n\n");
    printf("Are you ready?\n");

    printf("[1] Play\n");
    printf("[2] Exit\n\n");

    do{
    printf("Enter: ");
    scanf("%d", &menuTTT);
    }while((menuTTT < 1) || (menuTTT > 2));

    switch (menuTTT){
        case 1:
            system(clear);
            game();
            break;
        case 2:
            exit(0);
            break;
    }
    
}

int main(){
    menu();

    return 0;
}