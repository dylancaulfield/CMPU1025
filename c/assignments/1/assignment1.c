/*

    Program to show the user a maths quiz with options
    to do the quiz a number of times and to see the results

    Dylan Caulfield
    22/10/2019

    OS: Ubuntu
    Compiler: gcc

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct Round
{
    char questions[5][50];
    double correctAnswers[5];
    double answersGiven[5];
    short numRounds;
};

struct Result
{
    struct Round round;
    bool correct[5];
};

short showMenu(int);
void showLastResult(struct Result);
struct Round newRound(short);

int main()
{
    // int roundNum = 1; // If this is 1 do not allow user to view results
    // short menuSelection = 0;
    // struct Round currentRound, lastRound;

    // while (menuSelection != 4)
    // {

    //     menuSelection = showMenu(roundNum);

    //     switch (menuSelection)
    //     {
    //     case 1:
    //         /* code */
    //         break;
    //     case 2:
    //         break;
    //     case 3:
    //         break;
    //     }

    //     printf("\n\nProgram\n\nRunning\n\n");
    // }

    struct Round r = newRound(5);

    for (int i = 0; i < r.numRounds; i++)
    {
        printf("%s: %lf\n", r.questions[i], r.correctAnswers[i]);
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
        printf("1. Set the number of rounds for the next quiz\n");
        printf("2. Start quiz\n");
        printf("3. Show results of last quiz\n");
        printf("4. Exit the program\n\n");

        scanf(" %hd", &optionChosen);

    } while (optionChosen < 1 || optionChosen > 4);

    return optionChosen;
}

void showLastResult(struct Result result)
{

    for (int i = 0; i < result.round.numRounds; i++)
    {
        /* code */
    }
}

struct Round newRound(short numRounds)
{

    int random;
    char tempQuestion[50];
    double tempAnswer;
    char questions[5][50] =
        {
            "1 + 1? :",
            "3 x 5? :",
            "50 x 2 + 4? :",
            "5 ÷ 2? :",
            "23 - 6? :"};

    double answers[5] = {2, 15, 104, 2.5, 17}; // Correspond with questions

    struct Round round = {}; // Create a new round
    round.numRounds = numRounds; // Set the number of rounds for the round

    // Set the seed for the random number generator to the current time
    srand(time(NULL));

    for (int i = 0; i < numRounds; i++)
    {
        // New random number between 0 and the number of rounds - i
        // Add i to offset against the questions already used at the beginning of the array due to swapping
        random = (rand() % (numRounds - i)) + i;

        // Add the random question to the new Round struct
        strcpy(round.questions[i], questions[random]);

        // Swap random question with question at i
        strcpy(tempQuestion, questions[i]);
        strcpy(questions[i], questions[random]);
        strcpy(questions[random], tempQuestion);

        // Add the random questions answer to rounds answers
        round.correctAnswers[i] = answers[random];

        // Swap random answers with answer at i
        tempAnswer = answers[i];
        answers[i] = answers[random];
        answers[random] = tempAnswer;
    }

    return round;
}