//  A program that inputs the elements of 2 matrices of variable
//  sizes (M*N and P*Q respectively) and calculates the matrix product
//  of these two matrices.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void readmatrix(float** mat, int rows, int cols); // reads the data from user into the given matrix
void mat_multiply(float** A, int m, int n, float** B, int p, int q, float** C); // multiplies A and B, and store in C
void showmatrix(float** A, int rows, int cols);   // displays the given matrix

int main(void) {
    int m, n, p, q, i, j;
/**
    printf("Number of rows in matrix A = "); scanf("%d", &m);
    printf("Number of cols in matrix A = "); scanf("%d", &n);
    printf("Number of rows in matrix B = "); scanf("%d", &p);
    printf("Number of cols in matrix B = "); scanf("%d", &q);
**/
    m = n = p = q = 4;
    // If the matrices can't be multiplied, exit
    if (n != p) {
        printf("\nERROR - Not valid matrices for multiplication!\n");
        getch(); exit(1);
    }

    // Allocate memory for the 3 matrices (A, B, and M) where M = A.B
    float** A = malloc(m * sizeof(*A));
        for (i=0; i<m; i++) A[i] = malloc(n * sizeof(*(A[i])));
    float** B = malloc(p * sizeof(*B));
        for (i=0; i<p; i++) B[i] = malloc(q * sizeof(*(B[i])));
    float** M = malloc(m * sizeof(*M));
        for (i=0; i<m; i++) M[i] = malloc(q * sizeof(*(M[i])));

    // Fill A and B from user
    printf("\nEnter data of matrix A : \n");
    readmatrix(A, m, n);
    printf("\nEnter data of matrix B : \n");
    readmatrix(B, p, q);

    mat_multiply(A, m, n, B, p, q, M);

    printf("\nThe product of A and B is: \n");
    showmatrix(M, m, q);

    // Free the allocated memory
    for (i=0; i<p; i++) free(B[i]);
    for (i=0; i<m; i++) { free(A[i]); free(M[i]); }
    free(A); free(B); free(M);
    getch();
    return 0;
}

void showmatrix(float** mat, int rows, int cols) {
    int i, j;
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            if (mat[i][j] == (int) mat[i][j])
                printf("%7.0f", mat[i][j]);
            else
                printf("%7.1f", mat[i][j]);
        }
        printf("\n\n");
    }
}

void mat_multiply(float** A, int m, int n, float** B, int p, int q, float** C) {
    int i, j, k;
    for (i=0; i<m; ++i) {
        for (j=0; j<q; ++j) {
            C[i][j] = 0;
            for (k=0; k<n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

void readmatrix(float** mat, int rows, int cols) {
    int i, j;
    for (i=0; i<rows; i++)
        for (j=0; j<cols; j++) {
            printf("   Enter element %d.%d = ", i+1, j+1);
            scanf("%f", *(mat+i)+j);
        }
}
