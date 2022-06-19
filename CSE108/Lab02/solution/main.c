#include <stdio.h>
#include <math.h>

int gcd(int n1, int n2)
{
    int gcd = 0;
    int i = 0;
    for (i = 1; i <= n1 && i <= n2; ++i)
    {
        // Checks if i is factor of both integers
        if (n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }
    return gcd;
}

int lcm(int n1, int n2)
{
    return (n1 / gcd(n1, n2)) * n2;
}

int calculate_mean()
{
    int total = 0;
    int temp = 0;
    int counter = 0;

    FILE *fp;
    fp = fopen("/home/kezura/Desktop/cse108/lab2/results.txt", "r");

    while (fscanf(fp, "%d", &temp) == 1)
    {
        total += temp;
        counter++;
    }

    return total / counter;
}

void writeFile(int number)
{
    FILE *fp;
    fp = fopen("/home/kezura/Desktop/cse108/lab2/results.txt", "a+");
    fprintf(fp, "%d ", number);
    fclose(fp);
}

void gcd_calculator()
{
    int num1, num2, result;
    printf("Please enter two different number: \n");
    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 2: ");
    scanf("%d", &num2);

    result = gcd(num1, num2);
    printf("GCD of these two numbers: %d", result);
    writeFile(result);
    printf("\nThe result is written to the results.txt file.");
}

void lcm_calculator()
{
    int num1, num2, result;
    printf("Please enter two different number: \n");
    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 2: ");
    scanf("%d", &num2);

    result = lcm(num1, num2);

    printf("LCM of these two numbers: %d", result);
    writeFile(result);
    printf("\nThe result is written to the results.txt file.");
}

void standard_deviation_calculator()
{
    int mean = 0;
    int number = 0;
    float standardDeviation = 0.0;
    int total = 0;
    int counter = 0;

    mean = calculate_mean();

    FILE *fp;
    fp = fopen("/home/kezura/Desktop/cse108/lab2/results.txt", "r");
    while (fscanf(fp, "%d", &number) == 1) // (!feof(fp))
    {
        // fscanf(fp, "%d", &temp);
        printf("\n %d. Number: %d", counter + 1, number);
        total += pow(number - mean, 2);
        counter++;
    }

    standardDeviation = sqrt(total / counter);
    
    printf("\nMean: %d", mean);
    printf("\nTotal Count: %d", counter);
    printf("\nStandart Deviation : %.2f", standardDeviation);
}

int main()
{
    int selection;

    // GCD,LCM and Standard Deviation Calculator

    printf("Enter the calculator type \n ");
    printf("1. GCD Calculator \n ");
    printf("2. LCM Calculator via GCD \n ");
    printf("3. Standard Deviation Calculator \n ");
    printf("------------------------- \n ");

    scanf("%d", &selection);
    if (selection == 1)
    {
        gcd_calculator();
    }
    else if (selection == 2)
    {
        lcm_calculator();
    }
    else if (selection == 3)
    {
        standard_deviation_calculator();
    }
    else
    {
        printf("Please enter correct input");
    }

    return 0;
}
