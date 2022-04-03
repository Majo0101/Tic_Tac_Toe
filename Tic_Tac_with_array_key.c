#include <stdio.h>

char arr[3][3];
int counter = 49;
int players = 2;
int key[6] = {0,0,0,1,0,2};

int sWitchTwo(int player);
void playTable();
void swap();
void enigma();

int main(){

    playTable();

   while (1){

       ((players++) % 2 == 0) ? players = sWitchTwo(0) : sWitchTwo(1);

       playTable();

       enigma();

       if(players == 0)break;
   }

    return 0;
}

int sWitchTwo(player){

    char choice;
    char *name[] = {"Player1","Player2" };

    printf("%s Enter 1-9 or space to give up\n",name[player] );
    scanf("%c", &choice);
    if(choice == ' '){
        printf("\n%s gave up\n", name[player]);
        return players = 0;
    }else{
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((counter++) == choice) {
                    (player == 0) ? arr[i][j] = 'X' : (arr[i][j] = (char)254);
                }
            }
        }
        counter = 49;
    }
    fflush(stdin);
    return players;
}

void playTable(){

    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            printf(" %c |", (players != 2) ? arr[i][j] : (arr[i][j] = (char)counter++) );
        }
        printf("\n");
    }
    printf("-------------\n");
    counter = 49;
}

void swap(){
    for (int j = 0; j < 6; ++j) {
        int tmp = key[j];
        key[j] = key[j + 1];
        key[j + 1] = tmp;
        j++;
    }
}

void enigma(){

    for (int i = 0,a = 0; i < 8; i++) {

        if (i < 3) {key[0] = key[2] = key[4] = a++;}
        if (i == 3) { swap(); a = 2;}
        if (i > 3 && i < 6) {key[1] = key[3] = key[5] = --a;}
        if (i == 6) { key[3] = 1; key[5] = 2;}
        if (i == 7) { key[0] = 2; key[4] = 0;}

        if (arr[key[0]][key[1]] == arr[key[2]][key[3]] && arr[key[2]][key[3]] == arr[key[4]][key[5]]) {
            printf("\nYOU ARE W I N N E R ! ! ! \n");
            players = 0;
        }
    }
}

//
//            Enigma output  in loop ->
//            0 0 - 0 1 - 0 2
//            winner ?
//            1 0 - 1 1 - 1 2
//            winner ?
//            2 0 - 2 1 - 2 2
//            winner ?
//            0 2 - 1 2 - 2 2
//            winner ?
//            0 1 - 1 1 - 2 1
//            winner ?
//            0 0 - 1 0 - 2 0
//            winner ?
//            0 0 - 1 1 - 2 2
//            winner ?
//            2 0 - 1 1 - 0 2
//            winner ?
//
//
//
//            0 0 - 0 1 - 0 2
//            1 0 - 1 1 - 1 2
//            2 0 - 2 1 - 2 2
//            0 2 - 1 2 - 2 2
//            0 1 - 1 1 - 2 1
//            0 0 - 1 0 - 2 0
//            0 0 - 1 1 - 2 2
//            2 0 - 1 1 - 0 2
//
//            array positions ->
//            00 - 01 - 02
//            10 - 11 - 12
//            20 - 21 - 22
