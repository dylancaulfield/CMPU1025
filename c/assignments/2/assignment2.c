#include <stdio.h>

#define NUM_LOTTO 6

// Function Prototypes
void bubbleSort(int *, int);
int arrayContains(int *, int, int);
void getLottoNumbers(int *);
void compareChosenNumbers(int *);
int getMenuSelection(void);

int main()
{

    int a[6] = {};

    getLottoNumbers(a);
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
void getLottoNumbers(int *array)
{

    int i, enteredNum, numInRange, numUsed;

    for (i = 0; i < NUM_LOTTO; i++)
    {

        do
        {

            printf("\nEnter #%d: ", i + 1);
            scanf(" %d", &enteredNum);
            while (getchar() != '\n')
                ; // Clear standard input buffer

            numInRange = enteredNum >= 1 && enteredNum <= 42;
            numUsed = arrayContains(array, NUM_LOTTO, enteredNum);

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
}

// Function to compare the entered numbers with the winning numbers
// and to display the appropriate message to the user
void compareChosenNumbers(int *array)
{

    int i, matched = 0;
    int winningNumbers[NUM_LOTTO] = {1, 3, 5, 7, 9, 11};

    for (i = 0; i < NUM_LOTTO; i++)
    {

        if (arrayContains(array, NUM_LOTTO, *(winningNumbers + i)))
        {
            matched++;
        }

    } // End for

    switch (matched)
    {
    case 3:
    {

        printf("Congratulations! You have won a CinCinema Passema Pass");

        break;
    }

    case 4:
    {

        printf("Congratulations! You have won a Weekend Away");

        break;
    }

    case 5:
    {

        printf("Congratulations! You have won a New Car");

        break;
    }

    case 6:
    {

        printf("Congratulations! You have won the Jackpot");

        break;
    }

    default:
    {

        printf("Better luck next time!\n");

        break;
    }
    } // End Switch
}

// Function to display a menu to user and return their selection
int getMenuSelection()
{

    int selection;

    do
    {
        printf("1. Select numbers for Lotto\n");
        printf("2. Show selected Lotto numbers\n");
        printf("3. Sort entered Lotto numbers\n");
        printf("4. \n");
        printf("5. \n");
        printf("6. End Program\n");

    } while (selection < 1 || selection > 5);
}