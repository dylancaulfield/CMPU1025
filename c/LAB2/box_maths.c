/*
 * Compute and display the volume and surface area of a box
 * Dylan Caulfield
 * 30/09/2019
 */

#include <stdio.h>

int main(){

    float height, length, width, volume, surfaceArea;
    height = 10.0;
    length = 11.5;
    width = 2.5;

    volume = height * length * width;
    surfaceArea = 2*((height * length) + (height * width) + (length * width)); // Parenthesis for readability

    printf("The volume of the box is: %fcm^3\n", volume);
    printf("The total surface area of the cube is: %fcm^2", surfaceArea);

    return 0;
}
