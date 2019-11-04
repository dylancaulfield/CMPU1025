/*

    Read in 3 temperatures in Fahrenheit into an array.
    Display each of these temperatures in Fahrenheit and Celsius.

    Dylan Caulfield
    04/11/2019

*/

#include <stdio.h>

#define NUM_TEMPS 3

int main()
{

    int i;
    int temps[NUM_TEMPS];
    float celsius;

    for (i = 0; i < NUM_TEMPS; i++)
    {

        printf("Enter a temperature in degrees Fahrenheit(%d): ", i + 1);
        scanf(" %d", &temps[i]);
    }

    for (i = 0; i < NUM_TEMPS; i++)
    {

        celsius = (temps[i] - 32.0) * (5.0 * 9.0);

        printf("Temp %d in Fahrenheit: %d, Celsius: %f\n", i + 1, temps[i], celsius);
    }

    return 0;
}
