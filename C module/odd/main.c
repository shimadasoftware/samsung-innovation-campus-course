/*******************************************************************************
 * THE ODD NUMBER GAME.
 *
 * The program asks for a number, validates that it is within the range from
 * 3 to 21 and finally forms a diamond, according to the number entered.
 *
 * Author: Juana Valentina Mendoza Santamaría (juana.mendoza@usantoto.edu.co)
 * Copyright: Tunja, December 2021.
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Function:  requestData()
 * ------------------------
 * Request a number.
 *
 *  returns: the number.
 */
int requestData() {
    int num;
    printf("Please give me an odd number that is within the range (3 - 21): ");
    scanf("%d", &num);
    return num;
}

 /*
 * Function:  validateNumber()
 * ------------------------
 * Validate that the number is odd and is within the allowed range.
 *
 *  returns: the number.
 */
int validateNumber() {
    int number;
    do {
        number = requestData();

        if (number % 2 == 0) {
            printf("The number is even: %d\n", number);
        }
        else if (number < 3 || number > 21) {
            printf("The number is not between 3 to 21: %d\n", number);
        }
        else {
            printf("The number is correct: %d\n", number);
            break;
        }
    } while(1);
    return number;
}

 /*
 * Function:  diamond()
 * ------------------------
 * Draw the diamond according to the number provided.
 */
void diamond(int number, char sign) {
    int  space = (number - 1) / 2;
    char line[number + 1];

    // Clean the string
    for (int i = 0; i <= number; i++) {
        line[i] = ' ';
    }
    line[number + 1] = '\0';    // EOS: End of string

    line[0] = sign;
    // Draw the top area of the diamond.
    for (int i = 0; i < number / 2; i++) {
        printf("%*s", space, " ");
        printf("%s\n", line);
        line[i * 2 + 1] = sign;
        line[i * 2 + 2] = sign;
        space--;
    }

    printf("%s\n", line);   // Draw the middle area of the diamond.

    // Draw the lower area of the diamond.
    for (int i = number / 2 - 1; i >= 0; i--) {
        space++;
        line[i * 2 + 1] = ' ';
        line[i * 2 + 2] = ' ';
        printf("%*s", space, "");
        printf("%s\n", line);
    }
}

 /*
 * Function:  main()
 * ------------------------
 * The main function.
 *
 *  returns: 0.
 */
int main() {
    int validateNumber();
    void diamond(int, char);

    printf("Welcome to the odd number game! \n");
    int number = validateNumber();

    diamond(number, '*');

    return 0;
}
