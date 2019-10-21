/*
 * Using different arithmetic operators
 * Dylan Caulfield
 * 30/09/2019
 */

#include <stdio.h>

int main(){

    int add = 15 + 10;
    int subtract = 15 - 10;
    int prod = 15 * 10;
    float divide = 15.0 / 10.0;
    int mod = 15 % 3;

    printf("Add: %d\nSubtract: %d\nProduct: %d\nDivide: %f\nModulus: %d", add, subtract, prod, divide, mod);

    return 0;
}
