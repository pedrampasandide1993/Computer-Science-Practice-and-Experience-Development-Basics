#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **allocate_2D_double_array(int rows, int cols)
{
    double **array = (double **)malloc(rows * sizeof(double *));
    if (array == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++)
    {
        array[i] = malloc(cols * sizeof(double));
        if (array[i] == NULL)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    return array;
}

void print_2D_double_array(double **arr, int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0.2lf ", arr[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiplication(double **A, double **B, double **C, int rowA, int colA, int rowB, int colB)
{
    if (colA != rowB)
    {
        printf("Error in dimensions.\n");
        return;
    }
    for (int i = 0; i < rowA; i++)
    {
        for (int k = 0; k < rowB; k++)
        {
            for (int j = 0; j < colB; j++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void freeMatrix(double **matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main(int argc, char *argv[])
{

    if (argc != 5)
    {
        printf("Invalid input format.\n");
        printf("The input format: <rowA> <colA> <rowB> <colB>\n");
        return 1;
    }

    int N1 = atoi(argv[1]);
    int M1 = atoi(argv[2]);
    int N2 = atoi(argv[3]);
    int M2 = atoi(argv[4]);

    double **A = allocate_2D_double_array(N1, M1);
    double **B = allocate_2D_double_array(N2, M2);
    double **C = allocate_2D_double_array(N1, M2);

    // Initialize matrix A
    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < M1; j++)
        {
            A[i][j] = i + j;
        }
    }

    // Initialize matrix B
    for (int i = 0; i < N2; i++)
    {
        for (int j = 0; j < M2; j++)
        {
            B[i][j] = i - j;
        }
    }

    // printf("A =\n");
    // print_2D_double_array(A,N1,M1);

    // printf("B =\n");
    // print_2D_double_array(B,N2,M2);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // Call the matrix multiplication function
    matrixMultiplication(A, B, C, N1, M1, N2, M2);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printf("C =\n");
    // print_2D_double_array(C,N1,M2);

    printf("CPU Time: %f seconds\n", cpu_time_used);

    freeMatrix(A, N1);
    freeMatrix(B, N2);
    freeMatrix(C, N1);

    return 0;
}