#include <stdio.h>

#define ROWS 3
#define COLS 4

int main()
{

    int i, j;

    int array1[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int array2[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int array3[ROWS][COLS];

    for (i = 0; i < ROWS; i++)
    {

        for (j = 0; j < COLS; j++)
        {

            array3[i][j] = array1[i][j] * array2[i][j];
            printf("[i, j] => %d\n", array3[i][j]);
        }
    }

    return 0;
}