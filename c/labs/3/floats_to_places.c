/*
 * Program to enter 3 floats and display with different decimal places
 * Dylan Caulfield
 * 07/10/2019
 */

#include <stdio.h>

int main(){

    float float1, float2, float3;

    printf("Enter 3 floats with a decimal place:\n");

    scanf("%f%f%f", &float1, &float2, &float3);

    printf("%.4f, %.3f and %.0f", float1, float2, float3);

    return 0;
}