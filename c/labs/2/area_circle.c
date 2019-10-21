/*
 * Calculate and display area of circle
 * Dylan Caulfield
 * 30/09/2019
 */

#include <stdio.h>

int main(){

    float pi = 3.14;
    float radius = 4.8;
    float area = pi * (radius * radius);

    printf("The area of the circle is %fcm^2\n", area);


    return 0;
}