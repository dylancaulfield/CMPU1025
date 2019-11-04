/*

    Read in 5 characters and display them

    Dylan Caulfield
    04/11/2019

*/

#include <stdio.h>

#define ARRAY_LENGTH 5

int main()
{

    char characters[ARRAY_LENGTH];
    int i;

    for (i = 0; i < ARRAY_LENGTH; i++)
    {

        printf("Enter a character(%d): ", i + 1);
        scanf(" %c", &characters[i]);
        while(getchar() != '\n');

    }

    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        
        printf("%c ", characters[i]);

    }
    

    return 0;
}
