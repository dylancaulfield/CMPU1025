/*

    Read 5 integers into an array. Copy these integers into another array in reverse order.

    Dylan Caulfield
    04/11/2019

*/

#include <stdio.h>

#define ARRAY_LENGTH 5

int main()
{

    int i;
    int numArray[ARRAY_LENGTH], numArrayReversed[ARRAY_LENGTH];

    for (i = 0; i < ARRAY_LENGTH; i++)
    {

        printf("Enter a number(%d): ", i + 1);
        scanf(" %d", &numArray[i]);
    }

    for (i = 0; i < ARRAY_LENGTH; i++)
    {

        numArrayReversed[i] = numArray[ARRAY_LENGTH - 1 - i];
    }

    for (i = 0; i < ARRAY_LENGTH; i++)
    {

        printf("%d ", numArrayReversed[i]);
    }

    return 0;
}
