/*******************************************************************************
 * THE RANDOM NUMBER GAME.
 *
 * The program generates a random number between 1 and 100, displays the number
 *  of attempts the player made on the screen, and asks the player if they want
 *  to play again.

 * Author: Juana Valentina Mendoza Santamaría (juana.mendoza@usantoto.edu.co)
 * Copyright: Tunja, December 2021.
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/*
 * Function:  randomNumber()
 * ------------------------
 * Generate an random number between two values.
 *
 *  returns: A random number.
 */
int randomNumber(int lower, int upper) {
    srand(time(NULL));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

/*
 * Function:  requestData()
 * ------------------------
 * Request a number to guess.
 *
 *  returns: the number to guess.
 */
int requestData() {
    int num;
    printf("Please, give me a number (1 - 100): ");
    scanf("%d", &num);
    return num;
}

/*
 * Function:  compareNumbers()
 * ------------------------
 * Compare the number entered by the user
 * and the randomly generated number.
 *
 *  @returns: 0 (guess), 1 (>), -1 (<).
 */
int compareNumbers(int randomNum, int number) {
    if (randomNum > number) {
        printf("The number is greater than the one you provided.\n");
        return 1;
    }
    else if (randomNum < number) {
        printf("The number is less than the one you provided.\n");
        return -1;
    }
    else {
        printf("Congratulations, you guessed the number!\n");
        return 0;
    }
}

/*
 * Function:  answer()
 * ------------------------
 * Request an answer to continue the game.
 *
 *  @returns: a character.
 */
char answer() {
    char ans;
    printf("Do you want to continue playing? (Y / N): ");
    while ((getchar()) != '\n');
    ans = toupper(getchar());
    return ans;
}

 /*
 * Function:  main()
 * ------------------------
 * Program start.
 *
 *  @returns: 0.
 */
int main() {
    int randomNumber(int, int); // Function prototypes.
    int requestData();
    int compareNumbers(int, int);

    char ans;
    int attempt = 0;

    printf("Welcome to the program to guess a number between 1 to 100.\n");

    do {
        int randomNum = randomNumber(1, 100);
        //printf("%d\n", randomNum);
        int compare;
        do {
            int number = requestData();
            printf("The number provided is: %d\n", number);
            compare = compareNumbers(randomNum, number);
            attempt++;
        } while (compare != 0);
        printf("Your number of attempts was: %d\n", attempt);
        ans = answer();
    } while (ans == 'Y');
    return 0;
}
