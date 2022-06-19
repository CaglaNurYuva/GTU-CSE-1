#include <stdio.h>

enum day {sunday, monday, tuesday, wednesday, thursday, friday, saturday};
enum products {harddisk, monitor, keyboard, mouse};
enum sel {buy=1, orders, prices, exit};
enum currency {Dolar = 4, Euro, Sterlin=9, Peso};
enum product_prices {h_p=2, k_p ,mt_p=5, ms_p =10};

void writeOrderFile(int product, int day)
{
    FILE *fp;
    fp = fopen("orders.txt", "a+");
    fprintf(fp, "%d %d\n", product, day);
    fclose(fp);
}

void readOrderFile(void (*p_day)())
{
    int product, day;
    FILE *fp;
    fp = fopen("orders.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%d %d\n", &product, &day);
        printf("Product ID: %d,",product);
        p_day(day);
    }
    fclose(fp);
}



void calculate_prices(int (*a)(),int (*m)(),void (*p_day)()){

    int product, day;
    int sum=0,p;
    FILE *fp;
    fp = fopen("orders.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%d %d\n", &product, &day);

        if(product == harddisk){
            printf("Product: Harddisk,");
            p = m(h_p,Dolar);
            sum = a(sum,p);
        }else if(product == monitor){
            printf("Product: Monitor,");
            p = m(mt_p,Euro);
            sum = a(sum,p);
        }else if(product == keyboard){
            printf("Product: Keyboard,");
            p = m(k_p,Peso);
            sum = a(sum,p);
        }else if(product == mouse){
            printf("Product: Mouse,");
            p = m(ms_p,Sterlin);
            sum = a(sum,p);
        }
        p_day(day);
    }

    printf("Total prices: %d TL\n\n", sum);
    fclose(fp);
}

int add(int a, int b){
    return a + b;
}

int mult(int a, int b){
    return a * b;
}

void print_day(int day){

	if(day == sunday){
        printf("Day: Sunday\n");
    }else if(day == monday){
        printf("Day: Monday\n");
    }else if(day == tuesday){
        printf("Day: Tuesday\n");
    }else if(day == wednesday){
        printf("Day: Wednesday\n");
    }else if(day == thursday){
        printf("Day: Thursday\n");
    }else if(day == friday){
        printf("Day: Friday\n");
    }else{
        printf("Day: Saturday\n");
    }
}

int main(){

    int selection, sel2, sel3;

    
    do{
        printf("Welcome to the TechMarket. \n ");
        printf("1. Buy Product \n ");
        printf("2. Orders \n ");
        printf("3. All Orders Prices \n ");
        printf("4. EXIT \n ");
        printf("------------------------- \n ");

        scanf("%d", &selection);
        if (selection == buy)
        {
            printf("Select your product: \n ");
            printf("0. Harddisk \n ");
            printf("1. Monitor \n ");
            printf("2. Keyboard \n ");
            printf("3. Mouse\n ");
            printf("4. GO TO MAIN MENU\n ");
            printf("------------------------- \n ");
            scanf("%d", &sel2);

            if(sel2 != 4){
                printf("Select your arrival day[0-6]: \n ");
                printf("Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday \n ");
                printf("------------------------- \n ");
                scanf("%d", &sel3);

                writeOrderFile(sel2, sel3);
            }
                
        }
        else if (selection == orders)
        {
            readOrderFile(print_day);
        }
        else if (selection == prices)
        {
            calculate_prices(add, mult, print_day);
        }
    }while (selection != exit);

    
    return 0;
}