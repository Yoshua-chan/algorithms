#include <stdio.h>
#include "matrix.h"

int main() {
    matrix_t tab[9] = {2, 1, 3, 7, 6, 9, 4, 2, 0};
    Matrix mat = create_matrix(3, 3);
    for(int i = 0; i < 9; i++)
        mat.values[i] = tab[i];
    int err;
    printf("%lf\n", matrix_det_3x3(mat, &err));

    if(err) {
        printf("Błąd w obliczaniu macierzy :c\n");
    }
}
