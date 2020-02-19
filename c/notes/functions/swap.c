
#include <stdio.h>

int main()
{

    int x = 5;
    int y = 7;

    printf("x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("x = %d, y = %d\n", x, y);

    return 0;
}