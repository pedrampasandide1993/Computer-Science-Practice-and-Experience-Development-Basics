// Include everything necessary here 
#include <time.h>

int main(int argc, char *argv[])
{   
    // ###################################################################################
    // YOUR CODE: Handle the possible errors in input data given by the user and say how to execute the code

    // YOUR CODE: Assign all inputs given by the user argv[i] like:
    // POPULATION_SIZE, MAX_GENERATIONS, crossover_rate, mutate_rate, stop_criteria

    // ###################################################################################
    /* YOUR CODE: You must change this part based on the lower and upper bounds
    1. based on what function is going to be minimized (let's say Levy)
    2. given bound in https://www.sfu.ca/~ssurjano/optimization.html for each function.*/ 

    // the number of variables (d)
    int NUM_VARIABLES = 2;
    // the lower bounds of variables (x_1, x_2, ..., x_d) where d=NUM_VARIABLES
    double Lbound[] = {-5.0, -5.0};
    // the upper bounds of variable
    double Ubound[] = {5.0, 5.0};

    /*For example: in Levy function x_i ∈ [-10, 10], for all i = 1, …, d. This means:
    lower bound = -10 for all x_i
    upper bound = +10 for all x_i
    if d =10 (or NUM_VARIABLES = 10) then:
    double Lbound[] = {-5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0};
    double Ubound[] = {+5.0, +5.0, +5.0, +5.0, +5.0, +5.0, +5.0, +5.0, +5.0, +5.0};

    Another example: in Griewank() if NUM_VARIABLES = 7, then:
    // double Lbound[] = {-600.0, -600.0, -600.0, -600.0, -600.0, -600.0, -600.0};
    // double Ubound[] = {+600.0, +600.0, +600.0, +600.0, +600.0, +600.0, +600.0};
    */ 
    
    // ###################################################################################

    // YOUR CODE: Here make all the initial print outs

    clock_t start_time, end_time;
    double cpu_time_used;
    start_time = clock();

    // <YOUR CODE: Declare all the arrays you need here>


    // <YOUR CODE: Call generate_population function to initialize the "population"> like:
    // generate_population(POPULATION_SIZE, NUM_VARIABLES, population, Lbound, Ubound);

    // iteration starts here. The loop continues until MAX_GENERATIONS is reached
    // Or stopping criteria is met
    for (int generation = 0; generation < MAX_GENERATIONS; generation++)
    {
        // <YOUR CODE: Compute the fitness values using objective function for
        // each row in "population" (each set of variables)> like:
        // compute_objective_function(POPULATION_SIZE, NUM_VARIABLES, population, fitness);

        // <YOUR CODE: Here implement the logic of finding best solution with minimum fitness value
        // and the stopping criteria>

        // <YOUR CODE: Here call the crossover function>

        // <YOUR CODE: Here call the mutation function>

        // Now you have the a new population, and it goes to the beginning of loop to re-compute all again
    }

    // ###################################################################################
    // You dont need to change anything here
    // Here we print the CPU time taken for your code
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("CPU time: %f seconds\n", cpu_time_used);
    // ###################################################################################

    // <Your CODE: Here print out the best solution and objective function value for the best solution like the format>

    return 0;
}
