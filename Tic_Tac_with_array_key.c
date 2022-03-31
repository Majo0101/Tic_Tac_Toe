#include <stdio.h>

int main(){

    char arr[3][3];
    int counter = 49;
    int players = 2;
    char player1;
    char player2;
    int god[6] = {0,0,0,1,0,2};

    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            printf(" %c |",arr[i][j] = (char)counter++);
        }   printf("\n");
    }       printf("-------------\n"); counter = 49;

   while (1){

        if((players++)%2 == 0){
            printf("Player1 Enter 1-9 or space to give up\n");
            scanf("%c", &player1);
            if(player1 == ' '){
                printf("\nPlayer1 gave up\n");
                break;
            }else{
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if((counter++)==player1){
                            arr[i][j] = 'X';
                        }
                    }
                }       counter = 49;
            }
        }else{
            printf("Player2 Enter 1-9 or space to give up\n");
            scanf("%c", &player2);
            if(player2 == ' '){
                printf("\nPlayer2 gave up\n");
                break;
            }else{
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if ((counter++) == player2) {
                            arr[i][j] = (char)254;
                        }
                    }
                }        counter = 49;
            }
        }

       for (int i = 0,a = 0; i < 8; i++) {
           if (i < 3) { god[0] = god[2] = god[4] = a++; }

           if (i == 3) {
               for (int j = 0; j < 4; ++j) {
                   int tmp = god[j]; god[j] = god[j + 1]; god[j + 1] = tmp;
               } a = 2;
           }

           if (i > 3 && i < 6) { god[1] = god[3] = god[5] = --a; }
           if (i == 6) { god[3] = 1; god[5] = 2;}
           if (i == 7) { god[0] = 2; god[4] = 0;}

           if (arr[god[0]][god[1]] == arr[god[2]][god[3]] && arr[god[2]][god[3]] == arr[god[4]][god[5]]) {
               printf("\nYOU are W I N N E R\n");
               players = 0;
           }
       }
       fflush(stdin);
       if(players == 0)break;
   }

    printf("_____________\n");
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            printf(" %c |",arr[i][j]);
        }   printf("\n");
    }       printf("-------------\n");

    return 0;
}