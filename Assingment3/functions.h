#ifndef FUNCTIONS_H
#define FUNCTIONS_H
// DO NOT change anything here. You will not submit this file.
// Function prototypes
void generateMatrix(int rows, int cols, double matrix[rows][cols]);
void printMatrix(int rows, int cols, double matrix[rows][cols]);
void addMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1]);
void subtractMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1]);
void multiplyMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M2]);
void solveLinearSystem(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double x[N1][M2]);

#endif /* FUNCTIONS_H */
