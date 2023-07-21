#ifndef READFILE_RANDWORD_H
#define READFILE_RANDWORD_H



// Function prototypes

void readWords(char *filename, char **words[], int *numWords);
void freeWords(char **words, int numWords);
char* getRandomWordWithMinLength(char **words, int numWords, int minLength);


#endif
