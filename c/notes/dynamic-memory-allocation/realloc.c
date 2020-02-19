/*

    pointer = realloc(pointer, newSize)

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int numBytes;
    int numNums;
    int i;
    char answer;
    int newNums;

    printf("Enter number of numbers\n");
    scanf(" %d", &numNums);

    // Calculate size of block required in bytes
    numBytes = numNums * sizeof(int);

    // Allocate memory block
    ptr = malloc(numBytes);
    if (ptr == NULL)
    {
        printf("Failed to allocate memory\n\n");
        return 0;
    }

    // Enter data into memory
    for (i = 0; i < numNums; i++)
    {
        scanf(" %d", ptr + i);
    }

    printf("\nAny extra numbers?(y/n): ");
    scanf(" %c", &answer);

    if (answer == 'n')
    {
        printf("\nOk, all data already entered");
    }
    else
    {
        printf("\nHow many extra numbers?: ");
        scanf(" %d", &newNums);

        // Calculate new size
        numBytes = numBytes + newNums * sizeof(int);

        // Change size of block
        ptr = realloc(ptr, numBytes);
        if (ptr == NULL)
        {
            printf("Failed to reallocate memory\n\n");
            return 0;
        }
    }
}