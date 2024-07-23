#ifndef FUNCTIONS_H
#define FUNCTIONS_H
// Do know change anything in this file. You will not submit this file
// Here we included the declaration of all functions you need


// This is the Objective function which the implementation is in OF.c
double Objective_function(int NUM_VARIABLES, double x[NUM_VARIABLES]);

// This function generate a random number with precision double between "min" and "max"
double generate_random(double min, double max);

// This function generates a random integer value
int generate_int();

// Initializing the population randomly between the the lower and upper bound
void generate_population(int POPULATION_SIZE, int NUM_VARIABLES, double population[POPULATION_SIZE][NUM_VARIABLES], double Lbound[NUM_VARIABLES], double Ubound[NUM_VARIABLES]);

// Calling Objective_function function to compute fitness[i] values of each individual in "population"
void compute_objective_function(int POPULATION_SIZE, int NUM_VARIABLES, double population[POPULATION_SIZE][NUM_VARIABLES], double fitness[POPULATION_SIZE]);

// crossover function
void crossover(int POPULATION_SIZE, int NUM_VARIABLES, double fitness[POPULATION_SIZE], double new_population[POPULATION_SIZE][NUM_VARIABLES], double population[POPULATION_SIZE][NUM_VARIABLES], double crossover_rate);

// mutation function
void mutate(int POPULATION_SIZE, int NUM_VARIABLES, double new_population[POPULATION_SIZE][NUM_VARIABLES], double population[POPULATION_SIZE][NUM_VARIABLES], double Lbound[NUM_VARIABLES], double Ubound[NUM_VARIABLES], double mutate_rate);

#endif
