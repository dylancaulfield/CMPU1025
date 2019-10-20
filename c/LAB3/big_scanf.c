/*
 * Input different values
 * Dylan Caulfield
 * 07/10/2019
 */

#include <stdio.h>

int main(){

    int first, second, third, fourth;
    float principal, rate, time, f;
    char keyval1, keyval2, c;
    double d;
    
    printf("Enter in 4 integers, 4 floats, 3 characters and 1 double:\n");
    scanf(" %d %d %d %d %f %f %f %f %1s %1s %1s %lf", &first, &second, &third, &fourth, &principal, &rate, &time, &f, &keyval1, &keyval2, &c, &d);
    
    printf("%d, %d, %d, %d, %f, %f, %f, %f, %c, %c, %c, %lf\n", first, second, third, fourth, principal, rate, time, f, keyval1, keyval2, c, d);
    
    return 0;
}