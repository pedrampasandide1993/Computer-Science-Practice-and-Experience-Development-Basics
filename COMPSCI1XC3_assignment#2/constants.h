#ifndef CONSTANT_H
#define CONSTANT_H

// this one is used in readFile_randWord.c when reading the text file line by line
// the array will have a size of [number of words in text]X[maximum length of string with char]
#define MAX_WORD_LENGTH 50 

// You need to used this in functions.c for maximum allow attempts in the game
#define MAX_ATTEMPTS 5

// this is the length of random word chosen from array `words` 
// so it means randomWord will have atleast 6 letters
#define MIN_RAND_WORD_LENGTH 6

#endif // CONSTANT_H
