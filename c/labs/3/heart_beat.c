/*
 * Get age from user, calculate total heartbeats
 * Dylan Caulfield
 * 07/10/2019
 */

#include <stdio.h>

int main() {

    float age;
    int heartbeats;

    printf("Enter your age: ");
    scanf("%f", &age);
    
    heartbeats = 75 * 60 * 24 * 365.25 * age;

    printf("You have had %d heartbeats so far\n", heartbeats);

    return 0;
}