/*
 * Using modulus to get remainders
 * Dylan Caulfield
 * 30/09/2019
 */

#include <stdio.h>

int main() {

    int rem1 = 2 % 2;
    int rem2 = 3 % 2;
    int rem3 = 5 % 2;
    int rem4 = 7 % 3;
    int rem5 = 100 % 33;
    int rem6 = 100 % 7;
    
    printf("The remainders are: %d %d %d %d %d %d", rem1, rem2, rem3, rem4, rem5, rem6);

    return 0;
}

