/*
 * Input 3 numbers and determine if they form a triangle
 * Dylan Caulfield
 * 14/10/2019
 */

#include <stdio.h>

int main() {

    float side1, side2, side3;

    printf("Enter 3 numbers: ");
    fflush(stdout);

    scanf(" %f %f %f", &side1, &side2, &side3);

    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {

        printf("Invalid Input");
        fflush(stdout);
        return 0;

    }

    if (side1 + side2 < side3) {

        printf("This is not a valid triangle");
        fflush(stdout);

    } else if (side3 + side1 < side2) {

        printf("This is not a valid triangle");
        fflush(stdout);

    } else if (side2 + side3 < side1) {

        printf("This is not a valid triangle");
        fflush(stdout);

    } else {

        printf("This is a triangle");
        fflush(stdout);

    }

    return 0;
}