#include <stdio.h>

int range_test(int, int, int);

int main()
{

    int num1 = 27, num2 = 4;

    swap(&num1, &num2);


    printf("Numbers in ascending order are %d and %d", num1, num2);
}

int range_test(int val, int low, int high)
{

    if (val >= low && val <= high)
    {
        return 1;
    }

    return 0;
}