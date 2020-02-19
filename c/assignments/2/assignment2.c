#include <stdio.h>

// Function Prototypes
void bubbleSort(int *, int);
int arrayContains(int *, int, int);

int main()
{

    

}

// Implementation of bubble sort algorithm
void bubbleSort(int *array, int size)
{

    int swapped, i, temp;

    do
    {

        swapped = 0;

        for (i = 0; i < size - 1; i++)
        {

            if (*(array + i) > *(array + i + 1))
            {

                temp = *(array + i);
                *(array + i) = *(array + i + 1);
                *(array + i + 1) = temp;

                swapped++;
            }
        }

    } while (swapped != 0);
}

// Function to check whether an array contains a value
int arrayContains(int *array, int size, int value)
{

    int i;

    for (i = 0; i < size; i++)
    {
        
        if (*(array + i) == value)
        {
            return 1;
        }
        

    }
    
    return 0;


}