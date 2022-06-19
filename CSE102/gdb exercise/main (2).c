#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void rotate(int** matrix, int matrixSize, int* matrixColSize);
//Rotate Image
int main()
{
    int i,j,row,col,size ;
    int **matrix ;
    int *ptr = NULL ;

    ptr = &matrix[0][0] ;
   
    printf("Enter the capacity of your matrix (rowxcol): ");
    scanf("%d%d",&row,&col);

    size = row*col ;
    ptr = (int*)malloc(row*col*sizeof(int));

    printf("Enter the elements of your array: ");
    for(i = 0; i<row; i++) {
        for(j = 0; j<col; j++) {

            scanf("%d", ptr + i*col + j) ;
        }
    }

    printf("What you have entered:\n");
    for(i = 0; i<row; i++) {
        for(j = 0; j<col; j++) {

            printf("%d ", *(ptr + i*col + j)) ;
        }
        printf("\n");
    }

    rotate(matrix, size, &col);

    return 0;
}   

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int row,col ; 
    int i = 0, j=0, temp, k=0;
    int *ptr ;
    int sahteCol ;

    col = (*matrixColSize);
    row = matrixSize / col ;
    ptr = &matrix[0][0];

    sahteCol = col - 1 ;

    // reverse every individual row
    while(i < row)
    {
        sahteCol = col - 1 ;
        j = 0 ;

        while(j < sahteCol)
        {
            temp = (*(*(matrix + i) + j)) ;
            (*(*(matrix + i) + j)) = (*(*(matrix + i) + sahteCol)) ;
            (*(*(matrix + i) + sahteCol)) = temp ;

            sahteCol-- ;
            j++ ;
        }   
        i++ ;
    }

    printf("Reversed rows version :\n");
    for(i = 0; i<row; i++) {
        for(j = 0; j < col; j++) {

            printf("%d ", *(ptr + i*col + j)) ;
        }
        printf("\n");
    }

    printf("\n");

    //transpose array, result is going to become "turned 90 degree matrix"
    printf("Turned 90 degree version:\n");
    for(i = 0; i<col; i++) {
        for(j = 0; j<row; j++)
        {
            printf("%d ",*(ptr + i*col + j));
        }
    }

    
}

