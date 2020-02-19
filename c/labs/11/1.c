/*

    Lectures programs

*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

int main()
{

    int i;
    int *ptr = calloc(LENGTH, sizeof(int));

    if (ptr == NULL)
    {
        printf("No memory available");
    }
    

    *(ptr + 1) = 60;

    for (i = 0; i < LENGTH; i++)
    {
        
        printf("%d\n", *(ptr + i));

    }

    free(ptr);
    
    return 0;

}