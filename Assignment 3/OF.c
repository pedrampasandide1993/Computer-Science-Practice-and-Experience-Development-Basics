#include <math.h>
#include "functions.h"


double Objective_function(int NUM_VARIABLES, double x[NUM_VARIABLES])
{

    // // -----------------------------------------------------------
    // // griewank() 
    // double sum = 0.0;
    // double prod = 1.0;
    // double result;
    
    // for (int i = 0; i < NUM_VARIABLES; i++) {
    //     sum += (x[i] * x[i]) / 4000.0;
    //     prod *= cos(x[i] / sqrt((double)(i + 1)));
    // }
    
    // result = sum - prod + 1.0;
    // return result;

    // // -----------------------------------------------------------
    // // levy() 
    double w[NUM_VARIABLES];
    for (int i = 0; i < NUM_VARIABLES; i++) {
        w[i] = 1.0 + (x[i] - 1.0) / 4.0;
    }

    double term1 = pow(sin(M_PI * w[0]), 2);
    double term2 = 0.0;
    for (int i = 0; i < NUM_VARIABLES - 1; i++) {
        term2 += pow(w[i] - 1.0, 2) * (1 + 10 * pow(sin(M_PI * w[i] + 1.0), 2));
    }
    double term3 = pow(w[NUM_VARIABLES - 1] - 1.0, 2) * (1 + pow(sin(2 * M_PI * w[NUM_VARIABLES - 1]), 2));

    return term1 + term2 + term3;

    // // -----------------------------------------------------------
    // // rastrigin() {
    // double A = 10.0;
    // double sum = A * NUM_VARIABLES;

    // for (int i = 0; i < NUM_VARIABLES; i++) {
    //     sum += pow(x[i], 2) - A * cos(2 * M_PI * x[i]);
    // }

    // return sum;

    // // -----------------------------------------------------------
    // // schwefel() 
    // double sum = 0.0;

    // for (int i = 0; i < NUM_VARIABLES; i++) {
    //     sum += x[i] * sin(sqrt(fabs(x[i])));
    // }

    // return 418.9829 * NUM_VARIABLES - sum;

    // // -----------------------------------------------------------
    // // trid() 
    // double term1 = pow(x[0] - 1.0, 2);
    // double term2 = 0.0;
    // double term3 = 0.0;

    // for (int i = 1; i < NUM_VARIABLES; i++) {
    //     term2 += (x[i] - 1.0) * (x[i] - 1.0);
    //     term3 += (x[i] - x[i - 1]) * (x[i] - x[i - 1]);
    // }

    // return term1 + term2 + term3;

    // // -----------------------------------------------------------
    // // dixon_price() 
    // double term1 = pow(x[0] - 1.0, 2);
    // double term2 = 0.0;

    // for (int i = 1; i < NUM_VARIABLES; i++) {
    //     term2 += (i + 1) * pow(2 * x[i] * x[i] - x[i - 1], 2);
    // }

    // return term1 + term2;

    // // -----------------------------------------------------------
    // // rosenbrock() {
    // double sum = 0.0;

    // for (int i = 0; i < NUM_VARIABLES - 1; i++) {
    //     double term1 = x[i + 1] - x[i] * x[i];
    //     double term2 = x[i] - 1.0;
    //     sum += 100.0 * term1 * term1 + term2 * term2;
    // }

    // return sum;
    // // -----------------------------------------------------------
    // // michalewicz() {
    // double m = 10.0;
    // double sum = 0.0;

    // for (int i = 0; i < NUM_VARIABLES; i++) {
    //     sum += sin(x[i]) * pow(sin((i + 1) * x[i] * x[i] / M_PI), 2 * m);
    // }

    // return -sum;

    // // // -----------------------------------------------------------
    // // powell()
    // if (NUM_VARIABLES < 8) return -1.0;  // Powell function requires at least 8 variables

    // double term1 = pow(x[0] + 10.0 * x[1], 2) + 5.0 * pow(x[2] - x[3], 2);
    // double term2 = pow(x[4] - 2.0 * x[5], 4) + 10.0 * pow(x[6] - x[7], 4);
    
    // return term1 + term2;

    // // -----------------------------------------------------------
    // // styblinski_tang() 
    // double sum = 0.0;

    // for (int i = 0; i < NUM_VARIABLES; i++) {
    //     double xi = x[i];
    //     sum += pow(xi, 4) - 16 * pow(xi, 2) + 5 * xi;
    // }
    // return 0.5 * sum;
}