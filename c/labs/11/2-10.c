/*

    Replace blank characters with underscores

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i;
    char chars[] = {'a', ' ', 'c', ' ', ' ', 'd'};

    for (i = 0; i < sizeof(chars); i++)
    {

        if (*(chars + i) == ' ')
        {
            *(chars + i) = '_';
        }
    }

    for (i = 0; i < sizeof(chars); i++)
    {
        
        printf("%c", *(chars + i));

    }
    

    return 0;
}