/*

    Looping arrays

    Dylan Caulfield
    11/11/2019

*/

#include <stdio.h>

#define LEN 15

int main()
{

    int i;
    double array[LEN];

    for (i = 0; i < LEN; i++)
    {

        printf("Enter #%d: ", i + 1);
        scanf(" %lf", &array[i]);

    }

    for (i = 0; i < LEN; i++)
    {

        printf("%lf ", array[i]);

    }

    printf("\n");

    for (i = LEN - 1; i >= 0; i--)
    {
        
        printf("%lf ", array[i]);

    }
    
    printf("\n");

    return 0;
}