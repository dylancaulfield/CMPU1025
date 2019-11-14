/*

    Multiplying corresponding 1D array elements

    Dylan Caulfield
    11/11/2019

*/

#include <stdio.h>

#define LEN 5

int main()
{

    int i;
    double array1[LEN], array2[LEN];

    for (i = 0; i < LEN; i++)
    {

        printf("Enter 1st #%d: ", i + 1);
        scanf(" %lf", &array1[i]);
    }

    for (i = 0; i < LEN; i++)
    {

        printf("Enter 2nd #%d: ", i + 1);
        scanf(" %lf", &array2[i]);
    }

    for (i = 0; i < LEN; i++)
    {

        printf("(%d) => %lf * %lf = %lf\n", i + 1, array1[i], array2[i], array1[i] * array2[i]);
    }

    return 0;
}