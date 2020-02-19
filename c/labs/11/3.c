/*



*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main()
{

    int i;
    float *p_floats = calloc(SIZE, sizeof(float));
    float *p_average = malloc(sizeof(float));
    float sum = 0;

    if (p_floats == NULL || p_average == NULL)
    {
        printf("Couldn't allocate memory");
        return 0;
    }

    for (i = 0; i < SIZE; i++)
    {

        printf("Enter number %d: ", i + 1);
        scanf(" %f", p_floats + i);

        sum += *(p_floats + i);
    }

    *p_average = sum / SIZE;

    for (i = 0; i < SIZE; i++)
    {
        printf("Number %d: %f\n", i + 1, *(p_floats + i));
    }

    printf("Average: %f\n", *p_average);

    free(p_floats);
    free(p_average);

    return 0;
}