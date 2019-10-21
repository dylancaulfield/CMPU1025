/*
 * Program to enter 2 characters and display them
 * Dylan Caulfield
 * 07/10/2019
 */

#include <stdio.h>

int main(){

    char char1, char2;

    printf("Enter 2 characters:\n");

    scanf(" %c", &char1);
    scanf(" %c", &char2);

    printf("The characters are: %d and %d\n", char1, char2);

    return 0;
}
