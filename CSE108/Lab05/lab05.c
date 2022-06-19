#include <stdio.h>
#include <stdlib.h>

void display2d(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n"); // new line
    }
}

void display1d(int matrix[], int length)
{
    if (length == 10)
    {
        for (int i = 0; i < 10; i++)
        {
            printf("%d\t", matrix[i]);
        }
    }
    else if (length == 8)
    {
        for (int i = 0; i < 8; i++)
        {
            printf("%d\t", matrix[i]);
        }
    }
    printf("\n"); // new line
}

// function to multiply two 3x3 matrix
void multiply(int m[3][3], int n[3][3])
{
    int result[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = 0; // assign 0
            // find product
            for (int k = 0; k < 3; k++)
                result[i][j] += m[i][k] * n[k][j];
        }
    }
    printf("Multiplication of matrix: \n");
    display2d(result);
}

void cfilter(int matrix[10], int filter[3])
{
    int temp[8];
    for (int i = 1; i < 10; i++)
    {
        temp[i - 1] = (matrix[i - 1] * filter[0]) + (matrix[i] * filter[1]) + (matrix[i + 1] * filter[2]);
    }
    printf("\nConvolutional Filter Result: \n");
    display1d(temp, 8);
}

// function to find transpose of a 3x3 matrix
void transpose(int matrix[3][3])
{
    int temp[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp[i][j] = matrix[j][i];
        }
    }
    display2d(temp);
}

// function to display 3x3 matrix
void trace(int x[3][3])
{
    int i, j, s = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
            {
                s = s + x[i][j];
            }
        }
    }
    display2d(x);
    printf("Trace of matrix is: %d \n", s);
}

// main function
int main()
{
    // matrix
    // Values should be assumed to be received by the user.
    /*
	int a[3][3];
	int b[3][3];
    for(int i = 0; i<3; i++)
	{
		for(int j = 0; j <3; j++)
		{
			scanf("%d",&a[i][j]); // Creating the 3*3 matrix
		}
	}

    for(int i = 0; i<3; i++)
	{
		for(int j = 0; j <3; j++)
		{
			scanf("%d",&b[i][j]); // Creating the 3*3 matrix
		}
	}
	*/
    int a[][3] = {{3, 4, 9}, {6, 14, 12}, {7, 10, 11}};
    int b[][3] = {{8, 4, 5}, {9, 7, 3}, {8, 5, 1}};

    // variable to take choice
    int choice;

    // menu-driven
    do
    {
        // menu to choose the operation
        printf("\nChoose the matrix operation,\n");
        printf("----------------------------\n");
        printf("1. Convolutional Filter for 1D array\n");
        printf("2. Multiplication\n");
        printf("3. Trace\n");
        printf("4. Transpose\n");
        printf("5. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            // Values should be assumed to be received by the user.
            int array[10] = {3, 2, 11, 9, 16, 21, 17, 4, 5, 9};
            printf("1D Array \n");
            display1d(array, 10);
            int filter[3] = {-1, 1, -1};
            cfilter(array, filter);
            break;
        }
        case 2:
        {
            multiply(a, b);
            break;
        }
        case 3:
        {
            printf("Trace of the first matrix: \n");
            trace(a);
            printf("Trace of the second matrix: \n");
            trace(b);
            break;
        }
        case 4:
        {
            printf("Transpose of the first matrix: \n");
            transpose(a);
            printf("Transpose of the second matrix: \n");
            transpose(b);
            break;
        }
        case 5:
            printf("Thank You.\n");
            exit(0);
        default:
            printf("Invalid input.\n");
            printf("Please enter the correct input.\n");
        }
    } while (1);

    return 0;
}
