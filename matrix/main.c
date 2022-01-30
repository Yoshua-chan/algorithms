#include <stdio.h>
#include "matrix.h"

int main() {
    matrix_t srcA[4] = {2, 1, 3, 7};
    matrix_t srcB[4] = {6, 9, 4, 2};


    Matrix A = create_matrix(2, 2, srcA);
    Matrix B = create_matrix(2, 2, srcB);
    Matrix C = matrix_add(A, B, NULL);
    
    matrix_t x = 2137;
    Matrix one = create_matrix(1, 1, &x);
    printf("det(one) = %lf\n", matrix_det(one, NULL));
    printmatrix(C);
}
