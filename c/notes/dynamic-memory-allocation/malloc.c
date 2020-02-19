/*

    pointer = malloc(size);

    pointer => Pointer to the start of the allocated block of memory.

    size => Integer representing the entire size of the memory block in bytes

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr;
    int numNums;
    int numBytes;
    int i;



    printf("How many numbers would you like to enter?: ");
    scanf(" %d", &numNums);

    // Calculate the number of bytes required for the memory block
    numBytes = numNums * sizeof(int);

    // Allocate memory required
    ptr = malloc(numBytes);

    // Check if memory allocated successfully
    if (ptr == NULL)
    {

        printf("Memory failed to allocate\n");
    }
    else
    {

        printf("Enter data into memory block");

        // Enter data into memory block
        for (i = 0; i < numNums; i++)
        {

            scanf(" %d", ptr + i);
        }

        // Display contents of memory block
        for (i = 0; i < numNums; i++)
        {

            printf("%d/n", *(ptr + i));
        }

        // Release memory block
        free(ptr);

    }

    return 0;
}
