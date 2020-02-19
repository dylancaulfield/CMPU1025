#include <stdio.h>

void printElems(int *array)
{

    printf("size of array is: %ld", sizeof(*array));

}


int main()
{

    int array[5] = {1, 2, 3, 4, 5};

    printElems(array);


    return 0;


}