/*
 * Read two integers, check if first is divisible by the second
 * Dylan Caulfield
 * 14/10/2019
 */

#include <stdio.h>

int main() {

    int num1, num2;

    printf("Enter two integers: ");
    fflush(stdout);

    scanf(" %d %d", &num1, &num2);

    if (num1 % num2 == 0) {

        printf("%d is evenly divisible by %d", num1, num2);

    } else {

        printf("%d is not evenly divisible by %d", num1, num2);

    }

    return 0;
}
