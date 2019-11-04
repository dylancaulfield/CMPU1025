/*

    Program to show the user a maths round with options
    to do the round a number of times and to see the results

    Dylan Caulfield
    22/10/2019

    OS: Ubuntu
    Compiler: gcc

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <float.h>

#define MAX_NUM_QS 5
#define Q_LENGTH 20
#define NUM_AVAIL_QS 10

// Struct to hold the questions, correct answers, user answers
// and the number of questions to be asked for a single round of the round
struct Round
{
    char questions[MAX_NUM_QS][Q_LENGTH];
    double correctAnswers[MAX_NUM_QS];
    double answersGiven[MAX_NUM_QS];
    short numQs;
};

typedef struct Round Round;


// Function Declarations
short showMenu(short, short);
void showRoundResults(Round, int);
Round newRound();
Round playRound(Round);
Round setRoundNumQs(Round);


int main()
{
    int roundNum = 1; // If this is 1 do not allow user to view results
    short menuSelection = 0;
    Round currentRound, lastRound;

    // Set first round
    currentRound = newRound();

    // Clear the screen
    system("clear");

    while (menuSelection != 4)
    {

        // Show the menu and pass the current round number and the number of
        // questions to be played on the next round. This returns an integer
        // between 1 and 4.
        //
        menuSelection = showMenu(roundNum, currentRound.numQs);

        switch (menuSelection)
        {
        case 1: // Set number of rounds for round chosen

            currentRound = setRoundNumQs(currentRound);

            break;
        case 2: // Start Round chosen

            currentRound = playRound(currentRound);

            // Save round as last round
            lastRound = currentRound;

            // Create a new round round
            currentRound = newRound(5);

            // Increment the round number
            roundNum++;

            break;
        case 3: // Show results of last round chosen

            if (roundNum == 1)
            {

                system("clear");

                printf("You have not played a round yet!\n\n");
                break;
            }

            showRoundResults(lastRound, roundNum - 1);

            break;
        case 4: // Exit program chosen

            // Do nothing and let program exit
            break;
        }
    }

    return 0;
}

// Function to show the main menu of the application
short showMenu(short roundNum, short numRounds)
{

    short optionChosen = 0;
    char tmp[Q_LENGTH];

    // Present the options to the user until they select a valid one
    do
    {
        printf("Round #%d\n\n", roundNum);
        printf("Please enter an option from below:\n\n");
        printf("1. Set the number of questions for the next round of the round[%hd]\n", numRounds);
        printf("2. Start the next round of the round\n");
        printf("3. Show the results from the last round of the round\n");
        printf("4. Exit the program\n\n");

        scanf(" %hd", &optionChosen);

        // Clear standard input of any characters or numbers
        while (getchar() != '\n')
            ;

        system("clear");

        if (optionChosen < 1 || optionChosen > 4)
        {
            printf("Invalid input. Enter a number between 1-4\n\n");
        }

    } while (optionChosen < 1 || optionChosen > 4);

    return optionChosen;
}

// Function to show the result of the previous round
void showRoundResults(Round round, int roundNum)
{

    short correct = 0, incorrect = 0;

    system("clear");

    printf("Results For Round #%d:\n\n", roundNum);

    // Loop to count the number of questions answered correctly
    for (short i = 0; i < round.numQs; i++)
    {

        // If the answer given equals the correct answer
        if (round.answersGiven[i] == round.correctAnswers[i])
        {
            correct++; // Add 1 to correct counter
        }
        else
        {
            incorrect++; // Add 1 to incorrect counter
        }
    }

    // Use ternary operator to make question(s) singular if the user gets 1 correct or incorrect
    printf("(i)  You answered %d question%s correctly\n", correct, (correct == 1 ? "" : "s"));
    printf("(ii) You answered %d question%s incorrectly\n\n", incorrect, (incorrect == 1 ? "" : "s"));

    return;
}

// Function to create a new round with random questions
Round newRound()
{

    int random, i;
    char tempQuestion[Q_LENGTH];
    double tempAnswer;
    char questions[NUM_AVAIL_QS][Q_LENGTH] =
        {
            "1 + 7 + 9",
            "3 x 5",
            "50 x 2 + 4",
            "5 / 2",
            "23 - 6",
            "40 - 20 x 3 + 7",
            "27 + 13",
            "30 ÷ 6",
            "34 - 42",
            "2 * 2 * 2"};

    double answers[NUM_AVAIL_QS] = {17, 15, 104, 2.5, 17, -13, 40, 5, -8, 8}; // Answers that correspond with questions

    Round round = {};         // Create a new round
    round.numQs = MAX_NUM_QS; // Set the number of questions for the round

    // Set the seed for the random number generator to the current time
    srand(time(NULL));

    // Loop to add 5 random questions and their answers to the Round
    for (i = 0; i < MAX_NUM_QS; i++)
    {
        // New random number between 0 and the number of rounds - i
        // Add i to offset against the questions already used at the beginning of the array due to swapping
        random = (rand() % (NUM_AVAIL_QS - i)) + i;

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

    } // End Question and Answer for loop

    return round;
}

// Function to let the user go through each question in the round
Round playRound(Round round)
{

    int i;

    system("clear");

    // Show the user each question and get their answer
    for (i = 0; i < round.numQs; i++)
    {

        // Loop accepting the answer until the user enters a valid number
        do
        {
            // Print question with the maths in yellow for clarity
            printf("Question #%d (\x1b[33m%s = ?\x1b[0m): ", i + 1, round.questions[i]);

            scanf(" %lf", &round.answersGiven[i]);

            // Clear standard input of any characters or numbers
            while (getchar() != '\n')
                ;

            // Check if the answer given is outside of the range of a double
            if (round.answersGiven[i] < DBL_MIN || round.answersGiven[i] > DBL_MAX)
            {
                printf("Please enter a valid number!\n\n");
            }

        } while (round.answersGiven[i] < DBL_MIN || round.answersGiven[i] > DBL_MAX);

        // Print the valid answer the user entered
        printf("\nYou entered %.1lf which is ", round.answersGiven[i]);

        // End the message differently if the answer given was correct or incorrect
        if (round.answersGiven[i] == round.correctAnswers[i])
        {
            printf("correct!\n\n");
        }
        else
        {
            printf("incorrect. The correct answer is %.1lf\n\n", round.correctAnswers[i]);
        }
    }

    return round;
}

// Function that takes a Round and allows the user to change
// the number of questions that will be asked on that round.
// It returns the updated Round
Round setRoundNumQs(Round round)
{

    short numQs = 0;

    system("clear");

    // Loop asking for the number of questions to be set until the user enters an answer between 1 and 5
    do
    {

        printf("How many questions should the next round of the round have? (1-%d): ", MAX_NUM_QS);

        scanf(" %hd", &numQs);

        // Clear standard input of any characters or numbers
        while (getchar() != '\n')
            ;

        system("clear");

        printf("Invalid input! Enter a number between 1-%d\n\n", MAX_NUM_QS);

    } while (numQs < 1 || numQs > MAX_NUM_QS); // End do while

    round.numQs = numQs;

    system("clear");

    return round;
}