#include <stdio.h>

/* Functions related to 1. option */
int operation_one();                                    /* Getting coefficients from user as an input and writing them to coefficients.txt file */

/* Functions related to 2. option */
int operation_two();                                    /* Drawing graph on terminal */
int is_on_graph(int x, int y, int a, int b, int c);     /* Checking the point whether it is on the graph or not */
void draw_hat();                                        /* Drawing upper arrow on terminal */
void sayi_var_y_var(int x, int y, int a, int b, int c); /* Writing numbers just left y axis */
void x_sayilari(int x, int y, int a, int b, int c);     /* Writing numbers just under x axis */
int is_on_x_axis(int y);                                /* Checking whether the point is on the x axis or not */
int is_on_y_axis(int x);                                /* Checking whether the point is on the y axis or not */
void blue();                                            /* Coloring blue */
void yellow();                                          /* Coloring yellow */
void reset();                                           /* Going back to normal colors */

/* Functions related to 3. option */
int operation_three();                                  /* Calling write_file function, preventing and checking some file errors */
int draw_hat_to_file();                                 /* Drawing upper arrow to the graph.txt file */
int write_file();                                       /* Drawing graph on the graph.txt file */


int main() {
    int choice, result1, result2, result3, result4;

    do{
        do{
            /* MENU */
            printf("Select an operation...\n");
            printf("1 -> Enter the coefficients.\n");
            printf("2 -> Draw the graph.\n");
            printf("3 -> Print the graph into a .txt file.\n");
            printf("4 -> Exit.\n\n");

            printf("Choice: ");
            scanf("%d",&choice);

            if(choice != 1 && choice != 2 && choice != 3 && choice != 4) printf("Unvalid selection!\n");

        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);


        /* Doing tasks */
        if(choice == 1) {
            result1 = operation_one();
            if(result1 == 1) {
                printf("Error has happened regarding file operations..\n");
            }
        }

        else if(choice == 2) {
            result2 = operation_two();
            if(result2 == 1) {
                printf("Error has happened regarding file operations...\n");
            }
        }
        else if(choice == 3) {
            result3 = operation_three();
            if(result3 == 1) {
                printf("Error has happened regarding file operations...\n");
            }
        }


    }while(choice != 4);

    printf("Quitting...\n");
    return (0);
}


/* Getting coefficients from user as an input and writing them to coefficients.txt file */
int operation_one() {
    FILE *ptr;
    int a, b, c;

    printf("\nPlease enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n\n");

    printf("a: ");
    scanf("%d",&a);
    printf("b: ");
    scanf("%d",&b);
    printf("c: ");
    scanf("%d",&c);

    ptr = fopen("coefficients.txt","w");
    if(ptr == NULL) return (1);

    fprintf(ptr, "%d\n%d\n%d\n",a,b,c);
    fclose(ptr);
    printf("\ncoefficients.txt file has been created.\n\n");
    return (0);
}


/* Drawing graph on terminal */
int operation_two() {
    FILE *ptr;
    int a, b, c;
    int x, y,on_graph;

    ptr = fopen("coefficients.txt","r");
    if(ptr == NULL) return (1);
    if(fscanf(ptr,"%d\n%d\n%d",&a,&b,&c) == -1) return (1);
    fclose(ptr);

    draw_hat();
    for(y = 15; y >= -15; y--) {  /* y values goes from -15 to 15 */
        on_graph = is_on_graph(x,y,a,b,c);
        
        if(y == 0) {          
            for(x=-51; x<=51; x++) {
                
                 /* Drawing y axis */
                if(x == 0) { 
                    if(is_on_graph(x,y,a,b,c) == 1){  
                        blue();
                        printf("#");
                        reset();
                    }

                    else {
                        printf("|");
                    }
                }

                /* Marking points that are on the graph */
                else if(is_on_graph(x,y,a,b,c) == 1) {
                    blue();
                    printf("#");
                    reset();
                }    


                /* Marking arrows that are on x axis */
                else if(x == -51) {
                    printf("<");
                }

                else if(x == 51) {
                    printf(">");
                }

                else {
                    printf("-");
                }
            }
        }

        /* Writing numbers just under x axis */
        else if(y == -1)  {             
            x_sayilari(x,y,a,b,c);
        }


        /* Writing numbers just left y axis */
        else {
            sayi_var_y_var(x,y,a,b,c);
        } 
        printf("\n");                 
    }
    return (0);
}          


/* Writing numbers just left y axis */
void sayi_var_y_var(int x, int y, int a, int b, int c) {
    int d, cakisma1, cakisma2, cakisma3, cakisma4;

    /* y axis has some special cases, for example the point might be on the graph and on the number indicating y axis etc.  */
    /* That sort of cases for y axis are organized in this function. */

    for(d=-51; d<=51; d++){

        if(d == 0) { 
            cakisma1 = is_on_graph(0,y,a,b,c);  // this point indicates y axis line.
            cakisma2 = is_on_graph(-1,y,a,b,c); // this point indicates just one before y axis line.
            cakisma3 = is_on_graph(-2,y,a,b,c); // this point indicates just two before y axis line.
            cakisma4 = is_on_graph(-3,y,a,b,c); // this point indicates just three before y axis line.


            /* Regulations for the numbers that occupies 2 characters */
            if(y == 15 || y == 10 || y == -5) { 
                if(cakisma3 == 0) {
                    if(cakisma2 == 0) {
                        if(cakisma1 == 0) {
                            yellow();
                            printf("\b\b%d",y);
                            reset();
                            printf("|");
                        }

                        else if(cakisma1 == 1) {
                            yellow();
                            printf("\b\b%d",y);
                            blue();
                            printf("#");
                            reset();
                        }
                    }

                    else if(cakisma2 == 1) { 
                        if(cakisma1 == 0) {
                            printf("\b\b ");
                            blue();
                            printf("#");
                            reset();
                            printf("|");
                        }

                        else if(cakisma1 == 1) {
                            printf("\b\b ");
                            blue();
                            printf("##");
                            reset();
                        }
                    }
                }


                else if(cakisma3 == 1) {
                    if(cakisma2 == 0) {
                        if(cakisma1 == 0) {
                            printf("\b\b");
                            blue();
                            printf("#");
                            reset();
                            printf(" ");
                            printf("|");
                        }

                        else if(cakisma1 == 1) {
                            printf("\b\b");
                            blue();
                            printf("# ");
                            printf("#");
                            reset();
                        }
                    }

                    else if(cakisma2 == 1) { 
                        if(cakisma1 == 0) {
                            printf("\b\b");
                            blue();
                            printf("##");
                            reset();
                            printf("|");
                        }

                        else if(cakisma1 == 1) {
                            printf("\b\b");
                            blue();
                            printf("###");
                            reset();
                        }
                    }
                }
            }


            /* Regulations for the numbers that occupies 3 characters */
            else if(y == -15 || y == -10) {
                if(cakisma4 == 0) {
                    if(cakisma3 == 0) {
                        if(cakisma2 == 0) {
                            if(cakisma1 == 0) {
                                yellow();
                                printf("\b\b\b%d",y);
                                reset();
                                printf("|");
                            }

                            else if(cakisma1 == 1) {
                                yellow();
                                printf("\b\b\b%d",y);
                                blue();
                                printf("#");
                                reset();
                            }
                        }

                        else if(cakisma2 == 1) { 
                            if(cakisma1 == 0) {
                                printf("\b\b\b  ");
                                blue();
                                printf("#");
                                reset();
                                printf("|");
                            }

                            else if(cakisma1 == 1) {
                                printf("\b\b\b  ");
                                blue();
                                printf("##");
                                reset();
                            }
                        }
                    }


                    else if(cakisma3 == 1) { 
                        if(cakisma2 == 0) {
                            if(cakisma1 == 0) {
                                printf("\b\b\b ");
                                blue();
                                printf("#");
                                reset();
                                printf(" ");
                                printf("|");
                            }

                            else if(cakisma1 == 1) {
                                printf("\b\b\b ");
                                blue();
                                printf("#");
                                reset();
                                printf(" ");
                                blue();
                                printf("#");
                                reset();
                            }
                        }

                        else if(cakisma2 == 1) { 
                            if(cakisma1 == 0) {
                                printf("\b\b\b ");
                                blue();
                                printf("#");
                                printf("#");
                                reset();
                                printf("|");
                            }

                            else if(cakisma1 == 1) {
                                printf("\b\b\b ");
                                blue();
                                printf("###");
                                reset();
                            }
                        }
                    }
                }


                else if(cakisma4 == 1) {
                    if(cakisma3 == 0) {
                        if(cakisma2 == 0) {
                            if(cakisma1 == 0) {
                                blue();
                                printf("\b\b\b#");
                                reset();
                                printf("  |");
                            }

                            else if(cakisma1 == 1) {
                                blue();
                                printf("\b\b\b#");
                                reset();
                                printf("  ");
                                blue();
                                printf("#");
                                reset();
                            }
                        }

                        else if(cakisma2 == 1) {
                            if(cakisma1 == 0) {
                                blue();
                                printf("\b\b\b#");
                                reset();
                                printf(" ");
                                blue();
                                printf("#");
                                reset();
                                printf("|");
                            }

                            else if(cakisma1 == 1) {
                                blue();
                                printf("\b\b\b#");
                                reset();
                                printf(" ");
                                blue();
                                printf("##");
                                reset();
                            }
                        }
                    }

                    else if(cakisma3 == 1) { 
                        if(cakisma2 == 0){
                            if(cakisma1 == 0) {
                                printf("\b\b\b");
                                blue();
                                printf("##");
                                reset();
                                printf(" ");
                                printf("|");

                            }

                            else if(cakisma1 == 1) {
                                printf("\b\b\b");
                                blue();
                                printf("##");
                                reset();
                                printf(" ");
                                blue();
                                printf("#");
                                reset();
                            }
                        }

                        else if(cakisma2 == 1) {
                            if(cakisma1 == 0) {
                                printf("\b\b\b");
                                blue();
                                printf("###");
                                reset();
                                printf("|");
                            }

                            else if(cakisma1 == 1) {
                                blue();
                                printf("\b\b\b####");
                                reset();
                            }
                        }
                    }
                }
  
            }


            /* Regulations for the numbers that occupies 1 characters */
            else if(y == 5) {
                if(cakisma2 == 1) {
                    if(cakisma1 == 0) {
                        blue();
                        printf("\b#");
                        reset();
                        printf("|");
                    }

                    else if(cakisma1 == 1) {
                        blue();
                        printf("\b##");
                        reset();
                    }
                }

                else if(cakisma2 == 0) {
                    if(cakisma1 == 1) {
                        yellow();
                        printf("\b5");
                        blue();
                        printf("#");
                        reset();
                    }

                    else if(cakisma1 == 0) {
                        yellow();
                        printf("\b5");
                        reset();
                        printf("|");
                    }
                }
            }


            /* Regulations for the numbers that occupies 1 characters */
            else {
                if(cakisma1 == 1) {
                    blue();
                    printf("#"); 
                    reset();
                }
                else if(cakisma1 == 0) {
                    printf("|"); 
                }
            }

        }


        /* Marking the point that is on the graph */
        else if(is_on_graph(d,y,a,b,c) == 1){
            blue();
            printf("#");
            reset();
        }


        /* Drawing space */
        else {
            printf(" "); 
        }

    }
}


/* Writing numbers just under x axis */
void x_sayilari(int x, int y, int a, int b, int c) {
    int d;
    int cakisma1, cakisma2, cakisma3;

    /* x axis has some special cases, for example the point might be on the graph and on the number indicating x axis etc.  */
    /* That sort of cases for x axis are organized in this function. */

    for(d=-51; d<=51; d++){
        
        /* Regulations to draw 0 and some coincidence cases */
        if(d == 0) {
            cakisma1 = is_on_graph(0,y,a,b,c);   // This point indicates the point just on the y axis line.
            cakisma2 = is_on_graph(-1,y,a,b,c);  // This point indicates the point just one before the y axis line.

            if(cakisma2 == 0) {
                if(cakisma1 == 0) {
                    yellow();
                    printf("\b0");
                    reset();
                    printf("|");
                }

                else if(cakisma1 == 1) {
                    yellow();
                    printf("\b0");
                    blue();
                    printf("#");
                    reset();
                }
            }

            else if(cakisma2 == 1) {
                if(cakisma1 == 0) {
                    blue();
                    printf("\b#");
                    reset();
                    printf("|");
                }

                else if(cakisma1 == 1) {
                    blue();
                    printf("\b##");
                    reset();
                }
            }
        }


        /* Marking the point that is on the graph */
        else if(is_on_graph(d,y,a,b,c) == 1) {
            blue();
            printf("#");
            reset();
        }
              

        /* Regulations for the numbers that occupy 3 characters */
        else if(d == -50 || d == -40 || d == -30 || d == -20 || d == -10) {
            cakisma1 = is_on_graph(d+1,y,a,b,c);
            cakisma2 = is_on_graph(d+2,y,a,b,c);

            if(cakisma1 == 0 && cakisma2 == 0) {
                yellow();
                printf("%3d",d);
                reset();
                d = d + 2; 
            }

            else {
                printf(" ");
            }
        }


        /* Regulations for the numbers that occupy 2 characters */
        else if(d == 10 || d == 20 || d == 30 || d == 40 || d == 50) {
            cakisma1 = is_on_graph(d+1,y,a,b,c);

            if(cakisma1 == 0) {
                yellow();
                printf("%2d",d);
                reset();
                d++;
            }

            else {
                printf(" ");
            }

        }


        /* Drawing space */
        else printf(" ");
    }
}


/* Checking the point whether it is on the graph or not */
int is_on_graph(int x, int y, int a, int b, int c) {
    int result;
    result = (a*(y*y) + b*y + c);

    if(result == x) return (1);
    else return (0);
}


/* Drawing upper arrow on terminal */
void draw_hat() {
    int i;
    for(i = -51; i<=0; i++) {
        if(i == 0) printf("^");
        else printf(" ");
    }
    printf("\n");
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


/* Calling write_file function, preventing and checking some file errors */
int operation_three() {
   FILE *ptr; 
   int error;


   /* Preventing some file errors by creating the file that is going to be used */ 
   ptr = fopen("graph.txt","w");
   fclose(ptr);


   /* Checking file errors */ 
   error = write_file();
   if(error == 1) return (1);
   else return (0);
}


/* Checking whether the point is on the x axis or not */
int is_on_x_axis(int y) {
    if(y == 0) return (1);
    else return (0);
}


/* Checking whether the point is on the y axis or not */
int is_on_y_axis(int x) {
    if(x == 0) return (1);
    else return (0);
}


/* Drawing graph on the graph.txt file */
int write_file() {
    FILE *ptr, *p;
    int a, b, c, x, y, error;


    /* Opening coefficients.txt file to read coefficients */
    ptr = fopen("coefficients.txt","r");
    if(ptr == NULL) return (1);


    /* Reading coefficients from coefficients.txt file */
    if(fscanf(ptr,"%d\n%d\n%d\n",&a,&b,&c) == -1) {
        printf("\nThe file is empty...\n");
        return (1);
    }

    printf("\nCoefficients has been read from the coefficient file.\n");
    fclose(ptr);


    /* Drawing upper arrow to the file and checking any file error */
    error = draw_hat_to_file();
    if(error == 1) return (1);


    /* Opening graph.txt file */
    p = fopen("graph.txt","a");
    if(p == NULL) return (1);


    /* Drawing graph on the graph.txt file */
    for(y=15; y>=-15; y--) {
        for(x=-51; x<=51; x++) {

            /* Checking whether the point is on the graph or not */
            if(is_on_graph(x,y,a,b,c) == 1) {
                fprintf(p,"#");
                continue;
            }

            /* Checking whether the point is on the y axis or not */
            else if(is_on_y_axis(x) == 1) {
                fprintf(p,"|");
                continue;
            }

            /* Checking whether the point is on the x axis or not */
            else if(is_on_x_axis(y) == 1) {

                /* Regulations related to x axis */
                if(x == -51) fprintf(p,"<");
                else if(x == 51) fprintf(p,">");
                else if(x == 0) fprintf(p,"|");
                else fprintf(p,"-");
            }

            /* Drawing space */
            else fprintf(p," ");
        }
        fprintf(p,"\n");
    }

    fclose(p);
    printf("The graph of x=%d*(y*y) + %d*y + %d has been written to graph.txt file.\n\n",a,b,c);
    return (0);
}


/* Drawing upper arrow to the graph.txt file */
int draw_hat_to_file() {
    FILE *ptr;
    int i;

    ptr = fopen("graph.txt","w");
    if(ptr == NULL) return (1);

    for(i = -51; i<=0; i++) {
        if(i == 0) fprintf(ptr,"^");
        else fprintf(ptr," ");
    }
    fprintf(ptr,"\n");

    fclose(ptr);
    return (0);
}
