#include <stdio.h>
#include <string.h>
#define TAM_STRING 15

#ifdef __linux__ 
    #include <unistd.h>
    #define clear "clear"
#elif _WIN32
    #include <windows.h>
    #define clear "cls"
#else
    #error "OS not supported!"
#endif

int winnerX = 0;
int winnerO = 0;

void TwoPlayer(char *playerX, char *playerO);

void menu();

void Score(char *playerX, char *playerO){
    int menuScore;
    
    printf("\n\tScore\n\n");

    printf("\'X\' Player (%s) won %d times\n", playerX, winnerX);
    printf("\'O\' Player (%s) won %d times\n", playerO, winnerO);

    do{
        printf("\n[1]Restart Game\n[2]Restart Score and go back to Menu\n[3] Exit game\nEnter: ");
        scanf("%d%*c", &menuScore);
    }while(menuScore < 1 || menuScore > 3);

    switch(menuScore){
        case 1:
            TwoPlayer(playerX, playerO);
            break;
        case 2:
            winnerX = 0;
            winnerO = 0;
            system(clear);
            menu();
            break;
        case 3:
            exit(0);
    }
}

int Round2x(char *playerX, char *playerO){
    char game[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int i, j, number = 1, winner;
    //winner = 1 (X)      winner = 2 (O)     winner = 0 (no winner)

    do{
        if((game[0][0] == 'X' && game[0][1] == 'X' && game[0][2] == 'X') ||
           (game[1][0] == 'X' && game[1][1] == 'X' && game[1][2] == 'X') ||
           (game[2][0] == 'X' && game[2][1] == 'X' && game[2][2] == 'X') ||
           (game[0][0] == 'X' && game[1][0] == 'X' && game[2][0] == 'X') ||
           (game[0][1] == 'X' && game[1][1] == 'X' && game[2][1] == 'X') ||
           (game[0][2] == 'X' && game[1][2] == 'X' && game[2][2] == 'X') ||
           (game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X') ||
           (game[0][2] == 'X' && game[1][1] == 'X' && game[2][0] == 'X')){
               winner = 1;
               break;
        }else if((game[0][0] == 'O' && game[0][1] == 'O' && game[0][2] == 'O') ||
           (game[1][0] == 'O' && game[1][1] == 'O' && game[1][2] == 'O') ||
           (game[2][0] == 'O' && game[2][1] == 'O' && game[2][2] == 'O') ||
           (game[0][0] == 'O' && game[1][0] == 'O' && game[2][0] == 'O') ||
           (game[0][1] == 'O' && game[1][1] == 'O' && game[2][1] == 'O') ||
           (game[0][2] == 'O' && game[1][2] == 'O' && game[2][2] == 'O') ||
           (game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O') ||
           (game[0][2] == 'O' && game[1][1] == 'O' && game[2][0] == 'O')){
               winner = 2;
               break;
        }else if((game[0][0] != ' ' && game[0][1] != ' ' && game[0][2] != ' ' &&
                  game[1][0] != ' ' && game[1][1] != ' ' && game[1][2] != ' ' &&
                  game[2][0] != ' ' && game[2][1] != ' ' && game[2][2] != ' ')){
               winner = 0;
               break;
        }

        system(clear);

        if(number % 2 != 0){
            printf("\tRound #%d\n\n%s's turn (\'X\')\n\n", number, playerX);

            printf("  1 2 3\n");
            printf("1 %c|%c|%c\n", game[0][0], game[0][1], game[0][2]);
            printf("  -----\n");
            printf("2 %c|%c|%c\n", game[1][0], game[1][1], game[1][2]);
            printf("  -----\n");
            printf("3 %c|%c|%c\n", game[2][0], game[2][1], game[2][2]);

            do{
                printf("\nEnter your row: ");
                scanf("%d%*c", &i);
                printf("Enter your column: ");
                scanf("%d%*c", &j);
                i--;
                j--;
            }while(game[i][j] != ' ');

            game[i][j] = 'X';
            
        }else{
            printf("\tRound #%d\n\n%s's turn (\'O\')\n\n", number, playerO);

            printf("  1 2 3\n");
            printf("1 %c|%c|%c\n", game[0][0], game[0][1], game[0][2]);
            printf("  -----\n");
            printf("2 %c|%c|%c\n", game[1][0], game[1][1], game[1][2]);
            printf("  -----\n");
            printf("3 %c|%c|%c\n", game[2][0], game[2][1], game[2][2]);

            do{
                printf("\nEnter your row: ");
                scanf("%d%*c", &i);
                printf("Enter your column: ");
                scanf("%d%*c", &j);
                i--;
                j--;
            }while(game[i][j] != ' ');
            
            game[i][j] = 'O';

        }

        number++;
    }while(1);

    return winner;
}

void DefinePlayer(char *player){
    int tam;

    printf("\tYou will play as \'X\'\nWhat's your name, \'X\'?\nEnter nick: ");
    fgets(player, TAM_STRING+1, stdin);

    tam = strlen(player) - 1;
    if(player[tam] == '\n')
        player[tam] = '\0';

}

void DefinePlayers(char *playerX, char *playerO){
    int tam;
    
    printf("Who's gonna play as \'X\'?\nEnter nick: ");
    fgets(playerX, TAM_STRING+1, stdin);

    tam = strlen(playerX) - 1;
    if(playerX[tam] == '\n')
        playerX[tam] = '\0';
    
    printf("\nWho's gonna play as \'O\'?\nEnter nick: ");
    fgets(playerO, TAM_STRING+1, stdin);
    
    tam = strlen(playerO) - 1;
    if(playerO[tam] == '\n')
        playerO[tam] = '\0';

}

int Round1x(char *player){
    char game[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int winner, i, j, number = 1;
    //winner = 1 (player)   winner = 0 (computer)

    srand(time(NULL));

    do{
        if((game[0][0] != ' ' && game[0][1] != ' ' && game[0][2] != ' ' &&
            game[1][0] != ' ' && game[1][1] != ' ' && game[1][2] != ' ' &&
            game[2][0] != ' ' && game[2][1] != ' ' && game[2][2] != ' ')){
                winner = 0;
                break;
        }

        system(clear);

        printf("\tRound #%d\n\nIt's your turn, %s. You're \'X\'\n\n", number, player);

        printf("  1 2 3\n");
        printf("1 %c|%c|%c\n", game[0][0], game[0][1], game[0][2]);
        printf("  -----\n");
        printf("2 %c|%c|%c\n", game[1][0], game[1][1], game[1][2]);
        printf("  -----\n");
        printf("3 %c|%c|%c\n", game[2][0], game[2][1], game[2][2]);

        do{
            printf("\nEnter your row: ");
            scanf("%d%*c", &i);
            printf("Enter your column: ");
            scanf("%d%*c", &j);
            i--;
            j--;
        }while(game[i][j] != ' ');

        game[i][j] = 'X';

        if((game[0][0] == 'X' && game[0][1] == 'X' && game[0][2] == 'X') ||
           (game[1][0] == 'X' && game[1][1] == 'X' && game[1][2] == 'X') ||
           (game[2][0] == 'X' && game[2][1] == 'X' && game[2][2] == 'X') ||
           (game[0][0] == 'X' && game[1][0] == 'X' && game[2][0] == 'X') ||
           (game[0][1] == 'X' && game[1][1] == 'X' && game[2][1] == 'X') ||
           (game[0][2] == 'X' && game[1][2] == 'X' && game[2][2] == 'X') ||
           (game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X') ||
           (game[0][2] == 'X' && game[1][1] == 'X' && game[2][0] == 'X')){
               winner = 1;
               break;
        }

        do{
            i = rand() % 3;
            j = rand() % 3;
        }while(game[i][j] != ' ');

        game[i][j] = 'O';

        if((game[0][0] == 'O' && game[0][1] == 'O' && game[0][2] == 'O') ||
           (game[1][0] == 'O' && game[1][1] == 'O' && game[1][2] == 'O') ||
           (game[2][0] == 'O' && game[2][1] == 'O' && game[2][2] == 'O') ||
           (game[0][0] == 'O' && game[1][0] == 'O' && game[2][0] == 'O') ||
           (game[0][1] == 'O' && game[1][1] == 'O' && game[2][1] == 'O') ||
           (game[0][2] == 'O' && game[1][2] == 'O' && game[2][2] == 'O') ||
           (game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O') ||
           (game[0][2] == 'O' && game[1][1] == 'O' && game[2][0] == 'O')){
               winner = 2;
               break;
        }

        number++;
    }while(1);

    return winner;
}

void OnePlayer(char *player){
    int menu1x;
    
    system(clear);

    switch(Round1x(player)){
        case 0:
            printf("\n\nGame Over... No one won\n");
            break;
        case 1:
            printf("\n\n\tCongratulations, %s!!\nYou won the game.\n", player);
            break;
        case 2:
            printf("\n\nGame Over... You lose\n");
    }

    do{
        printf("\n[1] Go back to menu\n[2] Exit game\nEnter: ");
        scanf("%d%*c", &menu1x);
    }while(menu1x < 1 || menu1x > 2);

    switch(menu1x){
        case 1:
            system(clear);
            menu();
            break;
        case 2:
            exit(0);
    }

}

void TwoPlayer(char *playerX, char *playerO){
    char menu2x;

    system(clear);

    switch(Round2x(playerX, playerO)){
        case 0:
            printf("\n\nGame Over... No one won\n");
            break;
        case 1:
            winnerX++;
            printf("\n\n\tCongratulations, \'X\'!!\n%s won the game.\n", playerX);
            break;
        case 2:
            winnerO++;
            printf("\n\n\tCongratulations, \'O\'!!\n%s won the game.\n", playerO);
            break;
    }

    do{
        printf("\nSee Score?\nEnter (y/n): ");
        scanf("%c%*c", &menu2x);
    }while(menu2x != 'y' && menu2x != 'Y' && menu2x != 'N' && menu2x != 'n');

    switch(menu2x){
        case 'y':
        case 'Y':
            system(clear);
            Score(playerX, playerO);
            break;
        case 'n':
        case 'N':
            system(clear);
            menu();
    }
}

void menu(){
    int menu;

    printf("\tTic Tac Toe\n\n");
    printf("Welcome to tic tac toe...\n");

    do{
        printf("\n[1] One Player\n[2] Two Players\n[3] Exit\n\nEnter: ");
        scanf("%d%*c", &menu);
    }while(menu < 1 || menu > 3);

    switch(menu){
        case 1:
            system(clear);
            char player[TAM_STRING+1];
            DefinePlayer(player);
            OnePlayer(player);
            break;
        case 2:
            system(clear);
            char playerX[TAM_STRING+1], playerO[TAM_STRING+1];
            DefinePlayers(playerX, playerO);
            TwoPlayer(playerX, playerO);
            break;
        case 3:
            exit(0);
    }
}

int main(){

    system(clear);
    
    menu();

    return 0;
}