/*
 * Add the sum of integers 1 to 5 and display. Average of numbers 1.0, 1.1 to 2.0 and display
 * Dylan Caulfield
 * 30/09/2019
 */

#include <stdio.h>


int main() {

    int sumInts = 1 + 2 + 3 + 4 + 5;
    float sumFloats = 1.0 + 1.1 + 1.2 + 1.3 + 1.4 + 1.5 + 1.6 + 1.7 + 1.8 + 1.9 + 2.0;
    float avgFloats = sumFloats / 11;

    printf("The sum of the integers is %d\n", sumInts);
    printf("The average of the floating point numbers is %f", avgFloats);


    return 0;
}