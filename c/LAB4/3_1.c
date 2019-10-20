/*
 * Program that displays a status based off a character input
 * Dylan Caulfield
 * 14/10/2019
 */

#include <stdio.h>

int main() {

    char marriage_status;

    printf("Enter a status code [S/M/W/E/D]: ");

    scanf(" %c", &marriage_status);


    switch (marriage_status) {
        case 'S':
            printf("single\n");
            break;
        case 'M':
            printf("married\n");
            break;
        case 'W':
            printf("widowed\n");
            break;
        case 'E':
            printf("separated\n");
            break;
        case 'D':
            printf("divorced\n");
            break;
        default:
            printf("error:invalid code\n");
    }

    return 0;
}