#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function Prototypes */
void printMap(char array[15][30]);                                 /* Printing the array carrying map elements */
void moving_car1(char array[15][30], int array_finish[1], int r1); /* Arranging new location of player 1 that has been decided by throwing dice */
void moving_car2(char array[15][30], int array_finish[1], int r2); /* Arranging new location of player 2 that has been decided by throwing dice */
void filling_matrix(char array[15][30]);                           /* Filling array before starting the game. */
int dice();                                                        /* Getting a random number */
int startGame();                                                   /* Throwing dice before starting the game to decide which player start to play the game first */
void blue();                                                       /* Coloring blue */                                       
void yellow();                                                     /* Coloring yellow */                                      
void reset();                                                      /* Going back to normal colors */
void red();                                                        /* Coloring red */
void green();                                                      /* Coloring green */


int main() {
    char array[15][30] ;
    int array_finish[1] = {0};
    int r1=1, r2=0, game_mode;

    /* Using computer's internal clock to control the choice of the seed. */
    srand(time(NULL));

    /* Filling array before starting the game. */
    filling_matrix(array);

    /* Printing the array carrying map elements before starting the game. */
    printMap(array);

    /* Deciding who will start the game */
    game_mode = startGame();
    if(game_mode == 1) printf("\n*** PLAYER 1 will start the game... ***");
    else if(game_mode == 2) printf("\n*** PLAYER 2 will start the game... ***");
    
    while(array_finish[0] != 1) {  /* Indicating whether the game has finished or not */

        /* The case in which player 1 will start the game. */
        if(game_mode == 1) {
            yellow();
            printf("\nPLAYER 1... Press enter to dice...");
            reset();

            if(getchar() == '\n') {
                r1 = dice();   /* Throwing dice for player 1 */
                yellow();
                printf("DICE: %d\n",r1);
                reset();
                moving_car1(array,array_finish,r1);  /* Arranging new location of player 1 that has been decided by throwing dice */
            }

            if(array_finish[0] != 1){  /* If player 1 hasn't win the game yet, player2 will throw dice. */
                blue();
                printf("\nPLAYER 2... Press enter to dice...");
                reset();

                if(getchar() == '\n') {
                    r2 = dice();   /* Throwing dice for player 2 */
                    blue();
                    printf("DICE: %d\n",r2);
                    reset();
                    moving_car2(array,array_finish,r2);  /* Arranging new location of player 2 that has been decided by throwing dice */
                }
            }

            printMap(array);  /* Printing new map that is kept in an array */
        }


        /* The case in which player 2 will start the game. */
        else if(game_mode == 2) {
            blue();
            printf("\nPLAYER 2... Press enter to dice...");
            reset();

            if(getchar() == '\n') {
                r2 = dice();   /* Throwing dice for player 2 */
                blue();
                printf("DICE: %d\n",r2);
                reset();
                moving_car2(array,array_finish,r2);   /* Arranging new location of player 2 that has been decided by throwing dice */
            }

            if(array_finish[0] != 1){ /* If player 2 hasn't win the game yet, player 1 will throw dice. */
                yellow();
                printf("\nPLAYER 1... Press enter to dice...");
                reset();

                if(getchar() == '\n') {
                    r1 = dice();   /* Throwing dice for player 1 */
                    yellow();
                    printf("DICE: %d\n",r1);
                    reset();
                    moving_car1(array,array_finish,r1);   /* Arranging new location of player 1 that has been decided by throwing dice */
                }
            }

            printMap(array);  /* Printing new map that is kept in an array */
        }

    }

    return (0);
}


/* Arranging new location of player 1 that has been decided by throwing dice */
void moving_car1(char array[15][30], int array_finish[1], int r1) {
    int i, j;
    int old_loc1_i, old_loc1_j;
    int location1_i, location1_j ;
    int count=0, flag=0;
    
    /* Finding the current location of player 1 before changing its location */
    for(i=0; i<15; i++) {
        for(j=0; j<30; j++) { 
            if(array[i][j] == '1') {
                location1_i = i;
                location1_j = j;
                old_loc1_i = i;
                old_loc1_j = j;
            }
        }
    }

    /* Arranging player 1's new location in accordance with the result of dice and player 1's current location */
    if(location1_j < 28 && location1_i == 1) {
        location1_j += r1;
        if(location1_j > 28) {
            count = location1_j - 28 ;
            location1_i += count ;
            location1_j = 28;
        }
    }

    else if(location1_j == 28) {
        location1_i += r1;
        if(location1_i > 13) {
            count = location1_i - 13 ;
            location1_j -= count ;
            location1_i = 13;
        }
    }

    else if(location1_j < 28 && old_loc1_i == 13) {
        location1_j -= r1;
        if(location1_j < 1) {
            count = 1 - location1_j ;
            location1_i -= count ;
            location1_j = 1;
        }
    }

    else if(location1_i >= 2){
        location1_i -= r1;
        if(location1_i <= 2) {
            if(location1_i <= 1) {
                location1_i = 1;
            }

            else if(location1_i == 2) {
                location1_i = 2;
            }
            array_finish[0] = 1;   /* Condition for finishing the game. */
            yellow();
            printf("\n\n\n*** PLAYER 1 WON THE GAME ***\n\n");
            reset();
        }
    }


    /* Checking whether player 1 will get a penalty or not */
    if(location1_i == 1 && location1_j == 14) {
        location1_j -= 2;
        flag=1;
    }

    else if(location1_i == 7 && location1_j == 28) {
        location1_i -= 2;
        flag=1;
    }

    else if(location1_i == 13 && location1_j == 14) {
        location1_j += 2;
        flag=1;
    }

    if(flag == 1) {
        yellow();
        printf("Penalty for Player 1...\n");
        reset();
    }
    

    /* Changing the location of player 1 */
    array[old_loc1_i][old_loc1_j] = ' ';
    array[location1_i][location1_j] = '1';
}


/* Arranging new location of player 2 that has been decided by throwing dice */
void moving_car2(char array[15][30], int array_finish[1], int r2) {
    int i, j;
    int old_loc2_i, old_loc2_j;
    int location2_i, location2_j ;
    int count, flag=0;

    /* Finding the current location of player 2 before changing its location */
    for(i=0; i<15; i++) {
        for(j=0; j<30; j++) { 
            if(array[i][j] == '2') {
                location2_i = i;
                location2_j = j;
                old_loc2_i = i;
                old_loc2_j = j;
            }
        }
    }

    /* Arranging player 2's new location in accordance with the result of dice and player 2's current location */
    if(location2_j < 27 && location2_j > 2 && old_loc2_i == 3) {
        location2_j += r2;
        if(location2_j > 26) {
            count = location2_j - 26 ;
            location2_i += count ;
            location2_j = 26;
        }
    }

    else if(location2_j == 26) {
        location2_i += r2;
        if(location2_i > 11) {
            count = location2_i - 11 ;
            location2_j -= count ;
            location2_i = 11;
        }
    }
    
    else if(location2_j < 27 && old_loc2_i == 11) {
        location2_j -= r2;
        if(location2_j < 3) {
            count = 3 - location2_j ;
            location2_i -= count ;
            location2_j = 3;
        }
    }

    else if(location2_i >= 4 && location2_j == 3){
        location2_i -= r2;
        if(location2_i <= 4) {
            if(location2_i < 4) {
                location2_i = 3;
            }

            else if(location2_i == 4) {
                location2_i = 4;
            }
            array_finish[0] = 1;  /* Condition for finishing the game. */
            blue();
            printf("\n\n\n*** PLAYER 2 WON THE GAME ***\n\n");
            reset();
        }
    }


    /* Checking whether player 2 will get a penalty or not */
    if(location2_i == 3 && location2_j == 10) {
        location2_j -= 2;
        flag = 1;
    }

    else if(location2_i == 3 && location2_j == 18) {
        location2_j -= 2;
        flag = 1;
    }

    else if(location2_i == 5 && location2_j == 26) {
        location2_i -= 2;
        flag = 1;
    }

    else if(location2_i == 10 && location2_j == 26) {
        location2_i -= 2;
        flag = 1;
    }

    else if(location2_i == 11 && location2_j == 10) {
        location2_j += 2;
        flag = 1;
    }

    else if(location2_i == 11 && location2_j == 18) {
        location2_j += 2;
        flag = 1;
    }


    blue();
    if(flag == 1) printf("Penalty for Player 2...\n");
    reset();

    /* Changing the location of player 2 */
    array[old_loc2_i][old_loc2_j] = ' ';
    array[location2_i][location2_j] = '2';

}


/* Filling array before starting the game. */
void filling_matrix(char array[15][30]) {
    int i, j;

    for(i=0; i<15; i++) {
        for(j=0; j<30; j++) { 
            
            /* Indicating finish lines */
            if((i==2 && j==1)||(i==4 && j==3)) {
                array[i][j] = '-';
            }


            /* Indicating the first location of player 1 before starting the game. */
            else if(i==1 && j==1) {
                array[i][j] = '1';
            }


            /* Indicating the first location of player 2 before starting the game. */
            else if(i==3 && j==3) {
                array[i][j] = '2';
            }


            /* Indicating penaly points for player 1 */
            else if((i==1 && j==14) || (i==7 && j==28) || (i==13 && j==14)){
                array[i][j] = 'X';
            }


            /* Indicating penaly points for player 2 */
            else if((i==3 && j==10) || (i==3 && j==18) || (i==5 && j==26) || (i==10 && j==26) || (i==11 && j==10) || (i==11)&&(j==18)) {
                array[i][j] = 'X';
            }


            /* Indicating racetrack */
            else if(j==0 || j==29) {
                array[i][j] = '|';
            }
            
            else if(i==0 || i==14) {
                array[i][j] = '-';
            }
            

            else if((j==2 || j==27) && (i>=2 && i<=12)){
                array[i][j] = '|';
            }

            else if((j == 4 || j==25) && (i>=5 && i<=9)) {
                array[i][j] = '|';
            }

            else if(i==2 || i==12){
                if(j>2 && j<27) {
                    array[i][j] = '-';
                }

                else {
                    array[i][j] = ' ';
                }
            }

            else if(i==4 || i==10) {
                if(j>=4 && j<=25) {
                    array[i][j] = '-';
                }

                else {
                    array[i][j] = ' ';
                }
            }

            else {
                array[i][j] = ' ';
            }

        }
    }

}


/* Printing the array carrying map elements */
void printMap(char array[15][30]) {
    int i, j;

    for(i=0; i<15; i++) {
        for(j=0; j<30; j++) { 

            /* Printing players */
            if(array[i][j] == '1') {
                yellow();
                printf("%c",array[i][j]);
                reset();
            }
            
            else if(array[i][j] == '2') {
                blue();
                printf("%c",array[i][j]);
                reset();
            }


            /* Printing penaly points */
            else if(i == 1 && j == 14 || i == 7 && j == 28 || i == 13 && j == 14 ||i == 3 && j == 10 || i == 3 && j == 18) {
                red();
                printf("%c",array[i][j]);
                reset();
            }

            else if(i == 5 && j == 26 || i == 10 && j == 26 || i == 11 && j == 10 ||i == 11 && j == 18) {
                red();
                printf("%c",array[i][j]);
                reset();
            }


            /* Printing finish lines */
            else if(i==2 && j==1) {
                green();
                printf("%c",array[i][j]);
                reset();
            }

            else if(i==4 && j==3) {
                green();
                printf("%c",array[i][j]);
                reset();
            }


            /* Printing other elements of racetrack */
            else {
                printf("%c",array[i][j]);
            }

        }

        printf("\n");
    }
}


/* Throwing dice before starting the game to decide which player start to play the game first */
int startGame() {
    int r1, r2, game_mode;
    printf("\n\nTo start to game, players should dice and decide who is going to start first according to it...\n");

    do{
        yellow();
        printf("PLAYER 1... Press enter to dice...");
        reset();
        if(getchar() == '\n') {
            r1 = dice();   /* Getting a random number between 1-6 */
            yellow();
            printf("DICE: %d\n",r1);
            reset();
        }

        blue();
        printf("PLAYER 2... Press enter to dice...");
        reset();
        if(getchar() == '\n') {
            r2 = dice();   /* Getting a random number between 1-6 */
            blue();
            printf("DICE: %d\n",r2);
            reset();
        }

        if(r1 == r2) printf("Same dice value... please try again.\n");


        /* Deciding who will start to play the game */
        else if(r1 > r2)  game_mode = 1;   /* The case in which player 1 will start to play the game. */
        else  game_mode = 2;               /* The case in which player 2 will start to play the game. */
           
    }while(r1 == r2);

    return game_mode;
}


/* Coloring blue */
void blue() {
    printf("\033[0;34m");
}


/* Coloring yellow */
void yellow() {
    printf("\033[0;33m");
}


/* Going back to normal colors */
void reset() {
    printf("\033[0m");
}


/* Coloring red */
void red() {
    printf("\033[1;31m");
}


/* Coloring green */
void green() {
    printf("\033[0;32m");
}


/* Getting a random number */
int dice() {
    int r;
    r = 1 + rand()%6 ;
    return r;
}


