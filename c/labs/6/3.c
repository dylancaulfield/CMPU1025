/*

    Read 4 integers into an array and display them. Swap 1st with 2nd and 3rd with 4th and display them in new order.

    Dylan Caulfield
    04/11/2019

*/

#include <stdio.h>

#define ARRAY_LENGTH 4

int main()
{
    
    int numbers[ARRAY_LENGTH];
    int i, temp;

    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        
        printf("Enter a number(%d): ", i+1);
        scanf(" %d", &numbers[i]);

    }

    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        
        printf("%d ", numbers[i]);

    }

    printf("\n\n");
    

    temp = numbers[0];
    numbers[0] = numbers[1];
    numbers[1] = temp;

    temp = numbers[2];
    numbers[2] = numbers[3];
    numbers[3] = temp;


    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        
        printf("%d ", numbers[i]);

    }
    
    

    return 0;
}


