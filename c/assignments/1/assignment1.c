/*

    Program to show the user a maths quiz with options
    to do the quiz a number of times and to see the results

    Dylan Caulfield
    22/10/2019

    OS: Ubuntu
    Compiler: gcc

*/

#include <stdio.h>

short showMenu(int);

int main()
{
    int roundNum = 1;
    short menuSelection = 0;

    menuSelection = showMenu(roundNum);

    while (menuSelection != 4)
    {

        printf("\n\nProgram\n\nRunning\n\n");

        menuSelection = showMenu(++roundNum);
    }

    return 0;
}

short showMenu(int roundNum)
{

    short optionChosen = 0;

    do
    {
        printf("\nRound Number: %d\n\n", roundNum);
        printf("Please choose an option from below:\n\n");
        printf("1. \n");
        printf("2. \n");
        printf("3. \n");
        printf("4. Exit the program\n");

        scanf(" %hd", &optionChosen);

    } while (optionChosen < 1 || optionChosen > 4);

    return optionChosen;
}
