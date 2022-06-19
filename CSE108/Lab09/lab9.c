#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ARRSIZE 2 
#define STRSIZE 50
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define THREE_MIN(a,b,c) MIN(MIN(a,b),c)


void findMaximumDistance(int distanceOfCities[],
                         int result[],
                         int start,
                         int end)
{
    if (start == end)
    {
        /* array has one element */
        result[0] = distanceOfCities[start];
        result[1] = distanceOfCities[end];
    }
    else if (start +1 == end)
    {
        /* array has two elements */


        /* find min and max values and put those values to array result */
        if (distanceOfCities[start] > distanceOfCities[end])
        {
            result[0] = distanceOfCities[start];
            result[1] = distanceOfCities[end];
        }
        else
        {
            result[0] = distanceOfCities[end];
            result[1] = distanceOfCities[start];
        }
    }
    else
    {
        /* find mid point */
        int mid = (start + end) / 2;

        /* result arrays for left hand side and right hand side of array */
        int leftres[ARRSIZE], rightres[ARRSIZE];

        /* find results for left and right sides of array */
        findMaximumDistance(distanceOfCities, leftres, start, mid);
        findMaximumDistance(distanceOfCities, rightres, mid+1, end);

        /* compare their min and max values and respect to that add
         * this into result array
         */
        if (leftres[0] > rightres[0])
            result[0] = leftres[0];
        else
            result[0] = rightres[0];

        if (leftres[1] < rightres[1])
            result[1] = leftres[1];
        else
            result[1] = rightres[1];
    }
}


int recursiveMinStrDiff(char str1[], /* first string */
                        char str2[], /* second string */
                        int m,       /* length of first string */
                        int n)       /* length of second string */
{
    if (m == 0)
    {
        /* first string is empty */
        return n;
    }
    else if (n == 0)
    {
        /* first string is empty */
        return m;
    }
    else if (str1[m-1] == str2[n-1])
    {
        /* last elements are same */
        return recursiveMinStrDiff(str1, str2, m-1, n-1);
    }
    else
    {
        /* last elements are not same */
        return  1
           + THREE_MIN(recursiveMinStrDiff(str1, str2, m, n - 1), // Insert
                 recursiveMinStrDiff(str1, str2, m - 1, n), // Remove
                 recursiveMinStrDiff(str1, str2, m - 1,
                          n - 1) // Replace
             );
    }
}


/* function to print an int array which is size is parameter size */
void printArr(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main(int argc, char *argv[])
{
    int distanceOfCities[] = {120, 200, 105, 300, 295};
    int result[ARRSIZE];

    char str1[STRSIZE], str2[STRSIZE];


    /* test for part 1 */
    printf("Part 1\n");
    printf("------------------------\n");
    
    findMaximumDistance(distanceOfCities, result, 0, 4);
    printf("array is: \n");
    printArr(distanceOfCities, 5);
    printf("Result arr is: {%d, %d}\n", result[0], result[1]);


    /* test for part 2 */
    printf("Part 2\n");
    printf("------------------------\n");

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    
    int m = strlen(str1);
    int n = strlen(str2);
    printf("Part 2 result: %d\n", recursiveMinStrDiff(str1, str2, m, n));
 
    return 0;
}