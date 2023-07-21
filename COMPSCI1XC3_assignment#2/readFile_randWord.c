#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "constants.h"
#include "readFile_randWord.h"

void readWords(char *filename, char **words[], int *numWords) {


    // Open the file for reading
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file '%s'\n", filename);
        exit;
    }

    char buffer[MAX_WORD_LENGTH];
    *numWords = 0;

    while (fscanf(file, "%s", buffer) == 1) {
        *words = (char**)realloc(*words, (*numWords + 1) * sizeof(char*));
        (*words)[*numWords] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy((*words)[*numWords], buffer);
        (*numWords)++;
    }

    // Close the file
    fclose(file);
}


// // Pick a random word with at least minLength characters from the array
char* getRandomWordWithMinLength(char **words, int numWords, int minLength) {

    // Seed the random number generator with current time
    srand(time(NULL));

    char *randomWord = NULL;
    while (randomWord == NULL) {
        int randomIndex = rand() % numWords;
        if (strlen(words[randomIndex]) >= minLength) {
            randomWord = words[randomIndex];
        }
    }
    return randomWord;
}




void freeWords(char **words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);
}