
#include <stdio.h>

void diamond_star_display(int height);

void diamond_star_display(int height)
{
    int row, column;
    if((height<=0) || ((height % 2) == 0))
    {
        return;
    }
    int mid = height / 2 + 1;
    for (row=mid;row>=1; row--)
    {
        for (column=1; column<= height;column++)
        {
            if(column==row || column ==(height+1-row))
            {
                printf("*");

            }
            else
            {
                printf(" ");

            }
        }
        printf("\n");
    }
    for(row=2;row<=mid;row++)
    {
        for (column=1; column<= height;column++)
        {
            if(column==row || column ==(height+1-row))
            {
                printf("*");

            }
            else
            {
                printf(" ");

            }
        }
        printf("\n");
        
    }
    
    

}



void x_star_display(int height);

void x_star_display(int height)
{
    int row, column;
    if((height<=0) || ((height % 2) == 0))
    {
        return;
    }
    for (row=1;row<=height; row++)
    {
        for (column=1; column<= height;column++)
        {
            if(column==row || column ==(height+1-row))
            {
                printf("*");

            }
            else
            {
                printf(" ");

            }
        }
        printf("\n");
    }
}


void multiplication_table_display(int size);

void multiplication_table_display(int size)
{
    int row, column;
    if(size<=0)
    {
        return;
    }

    printf("   ");

    for(column=1; column<=size;column++)
    {
        printf(" %d ", column);
    }
    printf("\n");

    for(column=1; column<=size;column++)
    {
        printf("---");
    }
    printf("\n");


    for (row=1;row<=size; row++)
    {
        printf("%d", row);
        printf("* ");

        for (column=1; column<=size;column++)
        {
            if (row * column < 10 ) printf(" ");
            printf("%d", row * column);
            printf(" ");
        }
        printf("\n");

    }
}

void is_palindrome_integer(int n);
void is_palindrome_integer(int n){
    
    int reversed = 0, remainder, original;
    original = n; 
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (original == reversed)
        printf("%d is a palindrome.", original);
    else
        printf("%d is not a palindrome.", original);
}

int main()
{
   
   int option;


   do
   {

        printf("Enter option 1 to x_star_display\n");
        printf("Enter option 2 to diamond_star_display\n");
        printf("Enter option 3 to multiplication_table_display\n");
        printf("Enter option 4 to palindrome check number\n");
        printf("Enter option -1 to exit!\n");



       scanf("%d", &option);
       switch(option){
       int input;
       case(1):
        printf("Enter an odd integer as the height:");
        scanf("%d", &input);
        x_star_display(input);
        break;    

        case(2):
        printf("Enter an odd integer as the height:");
        scanf("%d", &input);
        diamond_star_display(input);
        break;    

        case(3):
        printf("Enter an integer as the size:");
        scanf("%d", &input);
        multiplication_table_display(input);
        break;    


        case(4):
        printf("Enter an integer as the palindrome:");
        scanf("%d", &input);
        is_palindrome_integer(input);
        break;
       }
       
       
   }while(option !=-1);
   /*int height;
    
    
    printf("Enter an odd integer as the height:");
    scanf("%d", &height);
    diamond_star_display(height);
    x_star_display(height);
    multiplication_table_display(height);*/
    return 0;
}
