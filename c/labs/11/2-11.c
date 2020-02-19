/*

    Miles per litre

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main()
{

    int i;
    float litres[] = {11.5, 11.21, 12.7, 12.6, 12.4};
    float miles[] = {471.5, 358.72, 495.3, 453.6, 421.6};
    int mpl[5];

    for (i = 0; i < SIZE; i++)
    {

        *(mpl + i) = *(miles + i) / *(litres + i);
        printf("%d\n", *(mpl + i));

    }

    return 0;
}