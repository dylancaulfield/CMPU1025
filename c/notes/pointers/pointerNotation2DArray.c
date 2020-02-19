#include <stdio.h>

#define ROWS 2
#define COLS 2

int main()
{

    int i, j, k;
    int array[ROWS][COLS];

    for (i = 0; i < ROWS; i++)
    {

        for (j = 0; j < COLS; j++)
        {

            printf("Enter number[%d, %d]: ", i, j);
            scanf(" %d", *(array + i + j));

            printf("[%d, %d] => %d\n", i, j, **(array + i + j));
        }
    }

    printf("\n\nK Begins\n\n");

    for (k = 0; k < ROWS * COLS; k++)
    {

        printf("Enter number[%d]: ", k);
        scanf(" %d", *(array + k));

        printf("[%d] => %d\n", k, **(array + k));
    }
}