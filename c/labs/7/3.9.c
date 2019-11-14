/*

    4 x 5 array. Find values below 0 and output.

    Dylan Caulfield
    11/11/2019

*/

#include <stdio.h>

#define NUM_ARR 4
#define ARR_LEN 5

int main()
{

    int i, j;
    double array[NUM_ARR][ARR_LEN];

    for (i = 0; i < NUM_ARR; i++)
    {

        for (j = 0; j < ARR_LEN; j++)
        {

            printf("Enter number[%d, %d]: ", i, j);
            scanf(" %lf", &array[i][j]);
        }
    }

    for (i = 0; i < NUM_ARR; i++)
    {

        for (j = 0; j < ARR_LEN; j++)
        {

            if (array[i][j] < 0)
            {
                printf("[%d, %d] => %lf\n", i, j, array[i][j]);
            }
        }
    }

    return 0;
}