/*
 * Program that takes in a character and tells if it is a vowel or not
 * Dylan Caulfield
 * 14/10/2019
 */

#include <stdio.h>

int main() {

    char input;

    printf("Enter a character: ");
    scanf(" %c", &input);

    switch (input){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':

            printf("You have entered a vowel\n");
            break;

        default:
            printf("You have not entered a vowel\n");
    }


    return 0;
}