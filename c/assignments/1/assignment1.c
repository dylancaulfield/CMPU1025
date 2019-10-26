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
#include <string.h>
#include <time.h>
#include <float.h>

#define MAX_NUM_QS 5
#define Q_LENGTH 20
#define NUM_AVAILABLE_QS 10

// Struct to hold the questions, correct answers, user answers
// and the number of questions to be asked for each round of the quiz
typedef struct Quiz
{
    char questions[MAX_NUM_QS][Q_LENGTH];
    double correctAnswers[MAX_NUM_QS];
    double answersGiven[MAX_NUM_QS];
    short numQs;
} Quiz;

// Function Declarations
short showMenu(short, short);
void showQuiz(Quiz, int);
Quiz newQuiz();
Quiz playQuiz(Quiz);
Quiz setNumQuizQs(Quiz);
void clearStdin();

int main()
{
    int roundNum = 1; // If this is 1 do not allow user to view results
    short menuSelection = 0;
    Quiz currentQuiz, lastQuiz;

    // Set first quiz
    currentQuiz = newQuiz();

    // Clear the screen
    system("clear");

    while (menuSelection != 4)
    {

        menuSelection = showMenu(roundNum, currentQuiz.numQs);

        switch (menuSelection)
        {
        case 1: // Set number of rounds for quiz

            currentQuiz = setNumQuizQs(currentQuiz);

            break;
        case 2: // Start Quiz

            currentQuiz = playQuiz(currentQuiz);

            // Save quiz as last quiz
            lastQuiz = currentQuiz;

            // Create a new quiz round
            currentQuiz = newQuiz(5);

            // Increment the round number
            roundNum++;

            break;
        case 3: // Show results of last quiz

            if (roundNum == 1)
            {

                system("clear");

                printf("You have not played a round yet!\n\n");
                break;
            }

            showQuiz(lastQuiz, roundNum - 1);

            break;
        case 4:
            // Do nothing and let program exit
            break;
        default:
            printf("\nInvalid input, select an option between 1 and 4\n");
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
        printf("1. Set the number of questions for the next round of the quiz[%hd]\n", numRounds);
        printf("2. Start quiz\n");
        printf("3. Show results of last quiz\n");
        printf("4. Exit the program\n\n");

        scanf(" %hd", &optionChosen);
        clearStdin();

        system("clear");

        if (optionChosen < 1 || optionChosen > 4)
        {
            printf("Invalid input. Enter a number between 1-4\n\n");
        }

    } while (optionChosen < 1 || optionChosen > 4);

    return optionChosen;
}

// Function to show the result of the previous round
void showQuiz(Quiz quiz, int roundNum)
{

    short correct = 0, incorrect = 0;

    system("clear");

    printf("Results For Round #%d:\n\n", roundNum);

    // Loop to count the number of questions answered correctly
    for (short i = 0; i < quiz.numQs; i++)
    {

        //quiz.answersGiven[i] == quiz.correctAnswers[i] ? correct++ : incorrect++;

        // If the answer given equals the correct answer
        if (quiz.answersGiven[i] == quiz.correctAnswers[i])
        {
            correct++;
        }
        else
        {
            incorrect++;
        }
    }

    // Use ternary operator to make question(s) singular if the user gets 1 correct or incorrect
    printf("(i)  You answered %d question%s correctly\n", correct, (correct == 1 ? "" : "s"));
    printf("(ii) You answered %d question%s incorrectly\n\n", incorrect, (incorrect == 1 ? "" : "s"));

    return;
}

// Function to create a new quiz with random questions
Quiz newQuiz()
{

    int random;
    char tempQuestion[Q_LENGTH];
    double tempAnswer;
    char questions[NUM_AVAILABLE_QS][Q_LENGTH] =
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

    double answers[NUM_AVAILABLE_QS] = {17, 15, 104, 2.5, 17, -13, 40, 5, -8, 8}; // Correspond with questions

    Quiz quiz = {};          // Create a new round
    quiz.numQs = MAX_NUM_QS; // Set the number of questions for the round

    // Set the seed for the random number generator to the current time
    srand(time(NULL));

    // Add 5 questions and answers to the quiz
    for (short i = 0; i < MAX_NUM_QS; i++)
    {
        // New random number between 0 and the number of rounds - i
        // Add i to offset against the questions already used at the beginning of the array due to swapping
        random = (rand() % (NUM_AVAILABLE_QS - i)) + i;

        // Add the random question to the new Quiz struct
        strcpy(quiz.questions[i], questions[random]);

        // Swap random question with question at i
        strcpy(tempQuestion, questions[i]);
        strcpy(questions[i], questions[random]);
        strcpy(questions[random], tempQuestion);

        // Add the random questions answer to rounds answers
        quiz.correctAnswers[i] = answers[random];

        // Swap random answers with answer at i
        tempAnswer = answers[i];
        answers[i] = answers[random];
        answers[random] = tempAnswer;

    } // End Question and Answer for loop

    return quiz;
}

// Function to let the user go through each question in the quiz
Quiz playQuiz(Quiz quiz)
{

    system("clear");

    // Show the user each question and get their answer
    for (int i = 0; i < quiz.numQs; i++)
    {

        // Loop accepting the answer until the user enters a valid number
        do
        {
            // Print question with the maths in yellow for clarity
            printf("Question #%d (\x1b[33m%s = ?\x1b[0m): ", i + 1, quiz.questions[i]);

            scanf(" %lf", &quiz.answersGiven[i]);
            clearStdin();

            // Check if the answer given is outside of the range of a double
            if (quiz.answersGiven[i] < DBL_MIN || quiz.answersGiven[i] > DBL_MAX)
            {
                printf("Please enter a valid number!\n\n");
            }

        } while (quiz.answersGiven[i] < DBL_MIN || quiz.answersGiven[i] > DBL_MAX);

        // Print the valid answer the users entered
        printf("\nYou entered %.1lf which is ", quiz.answersGiven[i]);

        // End the message differently if the answer given was correct or incorrect
        if (quiz.answersGiven[i] == quiz.correctAnswers[i])
        {
            printf("correct!\n\n");
        }
        else
        {
            printf("incorrect. The correct answer is %.1lf\n\n", quiz.correctAnswers[i]);
        }
    }

    return quiz;
}

// Function to set the numbers of questions to be asked
// in the next round of the quiz
Quiz setNumQuizQs(Quiz quiz)
{

    short numQs = 0;

    system("clear");

    // Loop asking for the number of questions to be set until the user enters an answer between 1 and 5
    do
    {

        printf("How many questions should the next round of the quiz have? (1-%d): ", MAX_NUM_QS);

        scanf(" %hd", &numQs);
        clearStdin();

        system("clear");

        printf("Invalid input! Enter a number between 1-%d\n\n", MAX_NUM_QS);

    } while (numQs < 1 || numQs > MAX_NUM_QS); // End do while

    quiz.numQs = numQs;

    system("clear");

    return quiz;
}

// Function to clear standard input if a character
// is entered instead of a number which prevents an endless loop
void clearStdin()
{

    // Read every character from standard input until a newline is found
    // to clear the standard input buffer
    while (fgetc(stdin) != '\n')
    {
    }

    return;
} // Found at https://stackoverflow.com/questions/5087062/how-to-get-int-from-stdio-in-c