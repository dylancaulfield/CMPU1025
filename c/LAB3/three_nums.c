/*
 * Program to enter 3 numbers and display them on separate lines
 * Dylan Caulfield
 * 07/10/2019
 */

#include <stdio.h>

int main(){

    float num1, num2, num3;

    printf("Enter 3 numbers:\n");

    scanf("%f %f %f", &num1, &num2, &num3);

    printf("The numbers are: %f, %f and %f", num1, num2, num3);

    return 0;
}