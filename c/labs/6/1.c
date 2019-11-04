/*

    Read in 5 numbers into an array. Copy this array into another array.

    Dylan Caulfield
    04/11/2019

*/

#include <stdio.h>

#define ARRAY_LENGTH 5

int main()
{

    int array1[ARRAY_LENGTH], array2[ARRAY_LENGTH], i;

    for (i = 0; i < ARRAY_LENGTH; i++)
    {

        printf("\nEnter a number(%d): ", i + 1);
        scanf(" %d", &array1[i]);

    }

    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        
        array2[i] = array1[i];

    }

    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        
        printf("%d\n", array2[i]);

    }
    
    

    return 0;
}
