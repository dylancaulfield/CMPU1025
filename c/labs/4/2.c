/*
 * Take in a number and output if odd or even
 * Dylan Caulfield
 * 14/10/2019
 */

#include <stdio.h>

int main() {

    int number;

    printf("Enter an integer between 1 and 100: ");
    scanf(" %d", &number);

    if (number < 1 || number > 100) {
        printf("You did not enter an integer between 1 and 100!");
        return 0;
    }

    if (number % 2 == 0) {
        printf("%d is even", number);
    } else {
        printf("%d is odd", number);
    }

    return 0;
}
