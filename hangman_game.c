#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    srand(time(NULL));

    printf("   || HANGMAN GAME ||   ");

    char Words[][16] = {
        "program",
        "hangman",
        "array",
        "windows",
        "linux",
        "syntax"
    };

    int randomIndex = rand() % 6;

    int Lives = 5;
    int numCorrect = 0;
    int oldCorrect = 0;

    int wordLength = strlen(Words[randomIndex]);
    int guessedLetter[8] = { 0,0,0,0,0,0,0,0 };

    int quit = 0;

    int loopIndex = 0;

    char guess[16];
    char letterEntered;

    while ( numCorrect < wordLength ) {

        printf("\n\nHangman Word:");

        for( loopIndex = 0; loopIndex < wordLength; loopIndex++) {

            if(guessedLetter[loopIndex] == 1) {
                printf("%c",Words[randomIndex][loopIndex]);
            } else {
                printf("_");
            }

        }

        printf("\n");

        printf("Lives left:%d\n",Lives);
        printf("Enter a guess letter:");
        fgets(guess, 16, stdin);

        if( strncmp(guess, "quit", 4) == 0) {
            quit = 1;
            break;
        }

        letterEntered = guess[0];

        oldCorrect = numCorrect;

        for( loopIndex = 0; loopIndex < wordLength; loopIndex++) {

            if(guessedLetter[loopIndex] == 1) {
                continue;
            }

            if( letterEntered == Words[randomIndex][loopIndex] ) {
                guessedLetter[loopIndex] = 1;
                numCorrect++;
            }

        }

        if( oldCorrect == numCorrect) {
            Lives--;
            printf("\nSorry, worng guess :(\n");

            if (Lives == 0) {
                break;
            }
        } else {
            printf("\nCorrect guess :)\n");
        }

        switch(Lives){
              case 5:
                printf("________\n");
                printf("|       \n");
                printf("|       \n");
                printf("|       \n");
                printf("|       \n");
                printf("|       \n");
                break;
              case 4:
                printf("________\n");
                printf("|   |   \n");
                printf("|       \n");
                printf("|       \n");
                printf("|       \n");
                printf("|       \n");
                break;
              case 3:
                printf("________\n");
                printf("|   |   \n");
                printf("|   O   \n");
                printf("|       \n");
                printf("|       \n");
                printf("|       \n");
                break;
              case 2:
                printf("________\n");
                printf("|   |   \n");
                printf("|   O   \n");
                printf("|  / \\ \n");
                printf("|       \n");
                printf("|       \n");
                break;
              case 1:
                printf("________\n");
                printf("|   |   \n");
                printf("|   O   \n");
                printf("|  /|\\ \n");
                printf("|       \n");
                printf("|       \n");
                break;
            }

    }

    if(oldCorrect == numCorrect){
        switch(Lives){
              case 4:
                printf("________\n");
                printf("|   |    \n");
                printf("|       \n");
                printf("|       \n");
                printf("|       \n");
                printf("|       \n");
                break;
              case 3:
                printf("________\n");
                printf("|   |   \n");
                printf("|   O   \n");
                printf("|       \n");
                printf("|       \n");
                printf("|       \n");
                break;
              case 2:
                printf("________\n");
                printf("|   |   \n");
                printf("|   O   \n");
                printf("|  / \\ \n");
                printf("|       \n");
                printf("|       \n");
                break;
              case 1:
                printf("________\n");
                printf("|   |   \n");
                printf("|   O   \n");
                printf("|  /|\\ \n");
                printf("|       \n");
                printf("|       \n");
                break;
              case 0:
                printf("________\n");
                printf("|   |   \n");
                printf("|   O   \n");
                printf("|  /|\\ \n");
                printf("|  / \\ \n");
                printf("|       \n");
                break;
            }
    }

    if( quit == 1 ) {
        printf("\nThe user quit early!\n");
    } else if (Lives == 0) {
        printf("\nSorry you loss :(\nThe word is: %s\n", Words[randomIndex]);
    } else {
        printf("\nYOU WIN!! :)\nThe word is: %s\n", Words[randomIndex]);
    }

    return 0;
}

