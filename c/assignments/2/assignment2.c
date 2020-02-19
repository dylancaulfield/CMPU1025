/*

    ///

    Dylan Caulfield
    19/02/2020
    
    OS: Ubuntu
    Compiler: gcc

*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 6

// Function Prototypes
void bubbleSort(int *, int);
int arrayContains(int *, int, int);
void chooseLottoNumbers(int *);
void compareChosenNumbers(int *);
int getMenuSelection(void);
void printArray(int *, int);
void showChosenNumbers(int *);
void sortNumbers(int *);

int main()
{

    int unlocked = 0;
    int menuSelection;
    int chosenNumbers[LENGTH] = {};

    do
    {

        menuSelection = getMenuSelection();

        if (!unlocked && (menuSelection >= 2 && menuSelection <= 5))
        {

            printf("\n\nYou need to choose the Lotto numbers first!\n\n");
            continue;
        }

        unlocked = 1;

        switch (menuSelection)
        {
        case 1: // Choose numbers
        {

            chooseLottoNumbers(chosenNumbers);
            break;
        }
        case 2: // Show chosen numbers
        {

            showChosenNumbers(chosenNumbers);
            break;
        }
        case 3: // Sort chosen numbers
        {

            sortNumbers(chosenNumbers);
            break;
        }
        case 4: // Compare with winning numbers
        {

            compareChosenNumbers(chosenNumbers);
            break;
        }
        case 5: // Display frequency
        {

            /* TODO */
            break;
        }
        } // End switch

    } while (menuSelection != 6);

    return 0;
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

// Function to take in new Lotto numbers and check for errors
void chooseLottoNumbers(int *array)
{

    int i, enteredNum, numInRange, numUsed;

    for (i = 0; i < LENGTH; i++)
    {

        do
        {

            printf("\nEnter #%d: ", i + 1);
            scanf(" %d", &enteredNum);
            while (getchar() != '\n')
                ; // Clear standard input buffer

            numInRange = enteredNum >= 1 && enteredNum <= 42;
            numUsed = arrayContains(array, LENGTH, enteredNum);

            if (!numInRange)
            {

                printf("\nPlease enter a number between 1-42.\n");
            }

            if (numUsed)
            {

                printf("\nThis number has already been entered. Please enter another number.\n");
            }

        } while (!numInRange || numUsed);

        *(array + i) = enteredNum;
    }

    printf("\n");
}

// Function to compare the entered numbers with the winning numbers
// and to display the appropriate message to the user
void compareChosenNumbers(int *array)
{

    int i, matched = 0;
    int winningNumbers[LENGTH] = {1, 3, 5, 7, 9, 11};

    for (i = 0; i < LENGTH; i++)
    {

        if (arrayContains(array, LENGTH, *(winningNumbers + i)))
        {
            matched++;
        }

    } // End for

    printf("You have %d winning numbers\n\n", matched);

    switch (matched)
    {
    case 3:
    {

        printf("Congratulations! You have won a Cinema Pass\n\n");
        break;
    }

    case 4:
    {

        printf("Congratulations! You have won a Weekend Away\n\n");
        break;
    }

    case 5:
    {

        printf("Congratulations! You have won a New Car\n\n");
        break;
    }

    case 6:
    {

        printf("Congratulations! You have won the Jackpot\n\n");
        break;
    }

    default:
    {

        printf("Better luck next time!\n\n");
        break;
    }
    } // End Switch
}

// Function to display a menu to user and return their selection
int getMenuSelection()
{

    int selection, inRange;

    do
    {

        printf("------ Menu ------\n");
        printf("1. Choose numbers for Lotto\n");
        printf("2. Show chosen Lotto numbers\n");
        printf("3. Sort chosen Lotto numbers\n");
        printf("4. Compare chosen Lotto numbers with winning numbers\n");
        printf("5. Display frequency of chosen numbers\n");
        printf("6. End Program\n\n");
        printf("Enter Selection: ");

        scanf(" %d", &selection);
        while (getchar() != '\n')
            ; // Clear standard input buffer

        inRange = selection >= 1 && selection <= 6;

        if (!inRange)
        {
            printf("\nPlease enter a number between 1-6.\n");
        }

    } while (!inRange);

    system("clear");

    return selection;
}

// Function to print out the elements of an array in a comma separated list
void printArray(int *array, int size)
{

    int i;

    printf("[");

    for (i = 0; i < size; i++)
    {

        printf("%d", *(array + i));

        // Add comma and space for every element except last
        if (i != size - 1)
        {
            printf(", ");
        }
    }

    printf("]");
}

// Function to show the Lotto numbers that have been chosen
void showChosenNumbers(int *array)
{

    printf("The numbers you have chosen are:\n\n");
    printArray(array, LENGTH);
    printf("\n\n");
}

void sortNumbers(int *array)
{

    printf("Sorting chosen Lotto numbers:\n\n");
    printArray(array, LENGTH);
    printf(" -> ");

    // Sort the array
    bubbleSort(array, LENGTH);

    printArray(array, LENGTH);

    printf("\n\n");

}