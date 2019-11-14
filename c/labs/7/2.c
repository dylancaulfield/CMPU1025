/*

    2D Arrays

    Dylan Caulfield
    11/11/2000

*/

#include <stdio.h>

#define NUM_ARRAYS 3
#define ARRAY_LEN 2

int main()
{

    int i, j;
    float array[NUM_ARRAYS][ARRAY_LEN];
    float sum, average, smallest, largest;

    for (i = 0; i < NUM_ARRAYS; i++)
    {

        for (j = 0; j < ARRAY_LEN; j++)
        {

            printf("Enter a number for [%d, %d]: ", i, j);
            scanf(" %f", &array[i][j]);

            while (getchar() != '\n')
            {
            }
        }
    }

    printf("\n");

    smallest = largest = array[0][0];

    for (i = 0; i < NUM_ARRAYS; i++)
    {

        for (j = 0; j < ARRAY_LEN; j++)
        {

            printf("[%d, %d] = %f\n", i, j, array[i][j]);

            if (array[i][j] < smallest)
            {
                smallest = array[i][j];
            }

            if (array[i][j] > largest)
            {
                largest = array[i][j];
            }

            sum += array[i][j];
        }
    }

    printf("\nThe average is %f\n", sum / (NUM_ARRAYS * ARRAY_LEN));

    return 0;
}