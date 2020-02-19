/*

    Specified numbers of integers into an array

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numOfNums = 0;
    int i;
    int *ptr;

    printf("How many numbers would you like to enter?: ");
    scanf(" %d", &numOfNums);

    ptr = calloc(numOfNums, sizeof(int));

    for (i = 0; i < numOfNums; i++)
    {
        
        printf("Enter number %d: ", i + 1);
        scanf(" %d", ptr + i);

    }
    
    for (i = 0; i < numOfNums; i++)
    {
        
        printf("Number #%d: %d\n", i + 1, *(ptr + i));

    }

    free(ptr);

    return 0;

}