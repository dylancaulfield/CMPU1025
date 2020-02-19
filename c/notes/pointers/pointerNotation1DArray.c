#include <stdio.h>

#define SIZE 5

int main()
{
    int numbers[SIZE];
    int i;

    // Enter data into array
    printf("Enter %d numbers\n", SIZE);

    for (i = 0; i < SIZE; i++)
    {

        scanf(" %d", (numbers + i));
        printf("%d\n", *(numbers + i));
    }
}