/*

    Arrays

    Dylan Caulfield
    11/11/2019

*/

#include <stdio.h>

#define LEN 10

int main()
{

    int i;
    int a[LEN];

    for (i = 0; i < LEN; i++)
    {
        
        a[i] = 9 - i;

    }

    for (i = 0; i < LEN; i++)
    {
        
        a[i] = a[ a[i] ];

    }

    printf("\n%d\n", a[8]);
    
    
    return 0;
}