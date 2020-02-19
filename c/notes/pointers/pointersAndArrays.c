/*

    In C, the name of an array is the same as the address
    location of the 1st element of the array. 

*/

#include <stdio.h>

#define SIZE 5

int main()
{

    int array[SIZE];
    int a, b;

    printf("%p == %p\n", array, &array[0]);

    printf("%p == %p\n", array + 1, &array[1]);

    // Subscript/Square bracket notation:    array_name[i]
    // Pointer notation:                     *(array_name + i)

    printf("Enter a and b: ");
    scanf("%d %d", (array + 1), array);

    printf("%d %d\n\n", *(array), array[1]);


    return 0;
}
