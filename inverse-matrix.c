#include <stdio.h>
#include <math.h>
#include <conio.h>

int readmatrix(float** mat, int rows, int cols);
float determinant(float** mat, int size);
void matInverse(float** mat, float** inv, int size);
void showmatrix(float** mat, int rows, int cols);
void transpose(float** mat, int rows, int cols, float** trans);
float diff(float a, float b);

int main(void) {
    int n, i, j;

    // ask for the size of the square matrix
    printf("Enter size of square matrix = "); scanf("%d", &n);

    // if the size is less than one, give up
    if (n<1) exit(1);

    // allocate memory for the matrix
    float** mat = malloc(n * sizeof(*mat));
    float** inv = malloc(n * sizeof(*inv));
    for (i=0; i<n; i++) {
        mat[i] = malloc(n * sizeof(*mat[i]));
        inv[i] = malloc(n * sizeof(*inv[i]));
    }

    // read the elements of the matrix
    printf("\nEnter the elements of array : \n"); readmatrix(mat, n, n);

    float det = determinant(mat, n);

    // print the determinant
    printf("\nDETERMINANT = %.2f  \n\n", det);

    if (det==0) {
        printf("The inverse of the given matrix DOESN'T EXIST! \n\n");
        getch(); exit(0);
    }

    // find the inverse of MAT and store it in INV
    matInverse(mat, inv, n);

    printf("INVERSE OF THE GIVEN MATRIX IS: \n");
    showmatrix(inv, n, n);

    getch();

    // free the allocated memory
    for (i=0; i<n; i++) { free(mat[i]); free(inv[i]); }
    free(mat);
    return 0;
}

int readmatrix(float** mat, int rows, int cols) {
    int i, j;
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            printf("     Enter element %d.%d = ", i+1, j+1);
            scanf("%f", *(mat+i)+j);
        }
    }
    return 1;
}

float determinant(float** mat, int size) {
    int i, j, k, m, n;

    // if the matrix is single matrix, return that single element
    if (size==1) return mat[0][0];

    //
    float det = 0;
    for (i=0; i<size; i++) {
        // allocate memory for the opposite matrix
        float** a = malloc((size-1) * sizeof(*a));
        for (j=0; j<(size-1); j++) a[j] = malloc((size-1)*sizeof(*a[j]));

        // fill the opposite matrix
        for(m=1; m<size; m++) {
            n = 0;
            for (j=0; j<size; j++) {
                if (j != i)
                    a[m-1][n++] = mat[m][j];
            }
        }

        // add or subtract alternatively
        if ((i%2)==0)  det += mat[0][i] * determinant(a, size-1);
        else           det -= mat[0][i] * determinant(a, size-1);

        // free the allocated memory
        for (j=0; j<(size-1); j++) free(a[j]); free(a);
    }
    return det;
}

void matInverse(float** mat, float** inv, int size) {
    float det = determinant(mat, size);
    int i, j, x, y, m, n;

    float** a = malloc((size-1) * sizeof(*a));
    for (i=0; i<(size-1); i++) a[i] = malloc((size-1)*sizeof(*a[i]));

    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            m = 0;
            for (x=0; x<size; x++) {
                if (x != i) {
                    n=0;
                    for (y=0; y<size; y++) {
                        if (y != j) {
                            a[m][n++] = mat[x][y];
                        }
                    }
                    m++;
                }
            }
            inv[i][j] = determinant(a, size-1) * pow(-1, i+j);
        }
    }

    // after finding the adjoint matrix, allocate a memory for its transpose
    float** t = malloc(size * sizeof(*t));
    for (i=0; i<size; i++) t[i] = malloc(size*sizeof(*t[i]));

    transpose(inv, size, size, t);

    for (i=0; i<size; i++)
        for (j=0; j<size; j++)
            inv[i][j] = t[i][j] / det;

    // free the allocated memory
    for (i=0; i<(size-1); i++) free(a[i]); free(a);
    for (i=0; i<size; i++) free(t[i]); free(t);
}

void showmatrix(float** mat, int rows, int cols) {
    int i, j;
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            int integer = (int) mat[i][j];
            if (diff(mat[i][j], integer) < 0.001)
                printf("%7.0f", mat[i][j]);
            else
                printf("%7.1f", mat[i][j]);
        }
        printf("\n\n");
    }
}

float diff(float a, float b) {
    float difference = a-b;
    if (difference < 0) return difference*(-1);
    else return difference;
}

void transpose(float** mat, int rows, int cols, float** trans) {
    int i, j;
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }
}
