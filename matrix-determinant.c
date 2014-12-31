#include <stdio.h>
#include <conio.h>
int readmatrix(float** mat, int size);
float determinant(float** mat, int size);

int main(void) {
    int n, i, j;

    // ask for the size of the square matrix
    printf("Enter size of matrix = "); scanf("%d", &n);

    // if the size is less than one, give up
    if (n<1) { printf("\nINVALID MATRIX SIZE\n"); getch(); exit(1); }

    // allocate memory for the matrix
    float** mat = malloc(n * sizeof(*mat));
    for (i=0; i<n; i++) mat[i] = malloc(n * sizeof(*mat[i]));

    // read the elements of the matrix
    printf("\nEnter the elements of array : \n"); readmatrix(mat, n);

    // print the determinant
    printf("\nDETERMINANT = %.2f", determinant(mat, n));

    getch();
    // free the allocated memory
    for (i=0; i<n; i++) free(mat[i]); free(mat);
    return 0;
}

int readmatrix(float** mat, int size) {
    int i, j;
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            printf("     Enter element %d.%d = ", i+1, j+1);
            scanf("%f", *(mat+i)+j);
        }
    }
    return 0;
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


