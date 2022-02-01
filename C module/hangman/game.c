/*******************************************************************************
 * THE HANGMAN GAME.
 *
 * This is the typical hangman game. The hangman game consists of guessing a
 *  secret word. On each turn of the game, a letter is entered. If the letter
 *  exists within the word, the game calculates its location(s) within the
 *  word. If the letter does not exist, one of a certain number of possible
 *  lives is subtracted. If all the letters in the word were entered, then the
 *  player wins the game. But, if the word was not guessed and the number of
 *  lives ran out, then the player loses the game. At the end the program
 *  stores the results in a file.
 *
 * Author: Juana Valentina Mendoza Santamaría (juana.mendoza@usantoto.edu.co)
 * Author: María Angélica Carvajal Caldas (mariangel9009@gmail.com)
 * Copyright: Tunja, December 2021.
 *
 ******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define NUM_WORDS   100		// Number of secret words.
#define LENGTH_WORD  30		// Maximum size of the word length.
#define LIVES         5		// Maximum lives counter.
#define NAME_LENGTH  10     // Maximum size of username length.

/*
 * Function:  select_word()
 * ------------------------
 * Randomly select a word to be guessed.
 *
 *  returns: A pointer to the randomly selected word.
 */
char *select_word() {
    static char secrets[NUM_WORDS][LENGTH_WORD];

    FILE *fp;
    if ((fp = fopen("hangman.txt", "r")) == NULL) {
       printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       exit(1);
    }

    char c;
    int line = 0;
    char buffer[LENGTH_WORD];
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {// Read the file.
    	if (c == 10) {		    // New line?
    	   buffer[i] = '\0';
    	   for (int j = 0; j <= i; j++) {
    	   	secrets[line][j] = buffer[j];
    	   }
    	   line++;

    	   for (int j = 0; j < LENGTH_WORD; j++) {
    	   	buffer[j] = ' ';
    	   }
    	   i = 0;
    	}
    	else {			    // Read the next character.
    	   buffer[i++] = c;
    	}
    }
    fclose(fp);

    srand(time(NULL));              // New random seed.
    int r = rand() % line;
    return secrets[r];
}

/*
 * Function:  get_name()
 * -----------------------
 * Get the player's name.
 *
 *  returns: The name.
 */
char *get_name() {
    static char name[NAME_LENGTH];

    printf("Please, give me your name: ");
    scanf("%s", name);
    while(getchar() != '\n');   // Clean the input buffer
    return name;
}

/*
 * Function:  get_letter()
 * -----------------------
 * Get the letter that the user choose.
 *
 *  returns: The letter.
 */
char get_letter() {
    char letter;

    printf("Choose a letter: ");
    letter = getchar();
    while(getchar() != '\n');   // Clean the input buffer.
    return letter;
}

/*
 * Function:  gallow()
 * -------------------
 * Draw the gallow.
 */
void gallow() {
    printf("=================\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf("================\n");
}

/*
 * Function:  head()
 * -----------------
 * Draw the head.
 */
void head() {
    printf("=================\n");
    printf(" |      \n");
    printf(" |    -----\n");
    printf(" |   | o o |\n");
    printf(" |   |  -  |\n");
    printf(" |    -----\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf("================\n");
}

/*
 * Function:  arms()
 * -----------------
 * Draw the arms.
 */
void arms() {
    printf("=================\n");
    printf(" |      \n");
    printf(" |    -----\n");
    printf(" |   | o o |\n");
    printf(" |   |  =  |\n");
    printf(" |  _ ----- _\n");
    printf(" | | |     | |\n");
    printf(" | |_|     |_|\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf("================\n");
}

/*
 * Function:  stomach()
 * -----------------
 * Draw the stomach.
 */
void stomach() {
    printf("=================\n");
    printf(" |      \n");
    printf(" |    -----\n");
    printf(" |   | o o |\n");
    printf(" |   |  o  |\n");
    printf(" |  _ ----- _\n");
    printf(" | | |     | |\n");
    printf(" | |_|_____|_|\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf("================\n");
}

/*
 * Function:  legs()
 * -----------------
 * Draw the legs.
 */
void legs() {
    printf("=================\n");
    printf(" |      \n");
    printf(" |    -----\n");
    printf(" |   | o o |\n");
    printf(" |   |  o  |\n");
    printf(" |  _ ----- _\n");
    printf(" | | |     | |\n");
    printf(" | |_|_____|_|\n");
    printf(" |   |  |  |\n");
    printf(" |   |__|__|\n");
    printf(" |\n");
    printf("================\n");
}

/*
 * Function:  hanged()
 * -------------------
 * Draw the hanged.
 */
void hanged() {
    printf("\n");
    printf("=You are hanged!=\n");
    printf("\n");
    printf(" |      ||\n");
    printf(" |    -----\n");
    printf(" |   | o o |\n");
    printf(" |   |  x  |\n");
    printf(" |  _ --=-- _\n");
    printf(" | | |     | |\n");
    printf(" | |_|_____|_|\n");
    printf(" |   |  |  |\n");
    printf(" |   |__|__|\n");
    printf(" |\n");
    printf("====Try again!===\n");
}

/*
 * Function:  winner()
 * -------------------
 * Draw the winner.
 */
void winner() {
    printf("\n");
    printf("=Congratulation!\n");
    printf("\n");
    printf("    _ -----\n");
    printf("   | | o o |\n");
    printf("   | |  W  |\n");
    printf("   |_ ----- _\n");
    printf("     |     | |\n");
    printf("     |_____|_|\n");
    printf("     |  |  |\n");
    printf("     |__|__|\n");
    printf("\n");
    printf("=You win!=======\n");
}

/*
 * Function:  show()
 * -------------------
 *
 * dash (char): The dashed string.
 * lives (int): The number of lives.
 *
 * Show the drawing according the number of lives.
 */
void show(char dash[], int lives) {
    switch (lives) {
        case 5: gallow();  break;
        case 4: head();    break;
        case 3: arms();    break;
        case 2: stomach(); break;
        case 1: legs();    break;
    }

    printf("%s\n", dash);
}

/*
 * Function:  play()
 * -----------------
 *
 * secret (char): The secret word.
 *
 * Play the game.
 */
void play(char secret[], char name[]) {
    void show(char[], int);     // Function prototypes.
    char get_letter();
    void gallow();
    void head();
    void arms();
    void stomach();
    void legs();
    void hanged();
    void winner();
    void save(char[], int, char[], int);

    char dash[LENGTH_WORD];

    for (int i = 0; i < strlen(secret); i++) {
        dash[i] = '-';
    }
    dash[strlen(secret)] = '\0';

    char letter;
    int lives = LIVES;
    while (lives > 0) {
        show(dash, lives);
        letter = get_letter();

        char *p = strchr(dash, letter);
        if (p == NULL) {
            int has = 0;
            for (int i = 0; i < strlen(secret); i++) {
                if (secret[i] == letter) {
                    dash[i] = letter;
                    has = 1;
                }
            }

            if (has == 0) {
                lives--;
            }
        }
        else {
            printf("%s\n", "This letter has already been chosen!");
        }

        if (strcmp(secret, dash) == 0) {    // Are you a winner?
            break;
        }
    }

    if (lives == 0) {
        hanged();
    }
    else {
        winner();
    }
    printf("The word was %s\n", secret);
    save(name, lives, secret, lives);
}

/*
 * Function:  save()
 * ------------------------
 * Store the game information in a file.
 *
 *  returns: A pointer to the randomly selected word.
 */
void save(char name[], int lives, char secret[], int result) {
    FILE *fp;
    fp = fopen("results.txt", "a");

    if (result == 0) {
        fprintf(fp, "%s, %d, %s, Lose\n", name, 5 - lives, secret);
    }
    else {
        fprintf(fp, "%s, %d, %s, Win\n", name, 5 - lives, secret);
    }

    fclose(fp);
}


/*
 * Function:  main()
 * -----------------
 *
 * The main function.
 */
int main() {
    char *select_word();    	    // Function prototypes.
    char *get_name();
    void play(char[], char[]);

    char *secret_word;
    char secret[LENGTH_WORD + 2];

    secret_word = select_word();    // Convert pointer to char[].
    for (int i = 0; i < LENGTH_WORD; i++) {
        if (*(secret_word + i) == '\0') {
            secret[i] = '\0';
            break;
        }
        secret[i] = *(secret_word + i);
    }

    char *namep = get_name();
    char name[NAME_LENGTH];         // Convert pointer to char[].
    for (int i = 0; i < NAME_LENGTH; i++) {
       if (*(namep + i) == '\0') {
            name[i] = '\0';
            break;
        }
        name[i] = *(namep + i);
    }
    play(secret, name);		   // Play the game.
}
