/*

    Read in 3 numbers. Sort the array in ascending order.

    Dylan Caulfield
    04/11/2019

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH 100000

int main()
{

    int i, temp, swapped, random;
    int numbers[ARRAY_LENGTH];

    srand(time(NULL));

    for (i = 0; i < ARRAY_LENGTH; i++)
    {

        random = (rand() % ARRAY_LENGTH) + 1;

        numbers[i] = random; 

    }

    do
    {
        
        swapped = 0;

        for (i = 0; i < ARRAY_LENGTH - 1; i++)
        {
            
        
            

            if (numbers[i + 1] < numbers[i])
            {
                swapped++;

                temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;


            }
            



        }
        
        printf("%d\n", swapped);

    } while (swapped != 0);
    
    
    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        
        printf("%d ", numbers[i]);

    }
    


    return 0;
}
