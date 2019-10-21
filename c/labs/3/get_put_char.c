/*
 * Program to get and display character with putchar and getchar
 * Dylan Caulfield
 * 07/10/2019
 */

#include <stdio.h>

int main(){

    char char1, char2;
    
    printf("Enter two characters: \n");
    
    char1 = getchar();
    char2 = getchar();
    
    putchar(char1);
    putchar(char2);

    return 0;
}