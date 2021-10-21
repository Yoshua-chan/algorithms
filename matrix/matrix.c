#include <stdlib.h>
#include "matrix.h"

//TODO: Obliczanie wyznacznika macierzy z definicji
//TODO: Mnożenie macierzy
//TODO: Transpozycja macierzy
//TODO: Sumowanie macierzy

#define DET_DIMENSION_ERROR 1
#define MUL_DIMENSION_ERROR 2
#define ADD_DIMENSION_ERROR 3

Matrix matrix_mul(Matrix A, Matrix B, int* err) {
    Matrix C;
    return C;
}

matrix_t matrix_det(Matrix matrix, int* err) {
    if(matrix.columns == 2 && matrix.rows == 2)
        return matrix_det_2x2(matrix, err);
    else  if(matrix.columns == 3 && matrix.rows == 3) {
        return matrix_det_3x3(matrix, err);
    } else {
        //kurwa
    }
}

matrix_t matrix_det_3x3(Matrix matrix, int* err) {
	if(matrix.columns == 3 && matrix.rows == 3) {
        if(err != NULL)
            *err = 0;
        matrix_t* val = matrix.values;
		return   val[0] * val[4] * val[8]  
               + val[3] * val[7] * val[2] 
               + val[6] * val[1] * val[5]
               - val[2] * val[4] * val[6]
               - val[5] * val[7] * val[0]
               - val[8] * val[1] * val[3]; 
	}
    else 
        if(err != NULL)
            *err = 1;
}

matrix_t matrix_det_2x2(Matrix matrix, int* err) {
	if(matrix.columns == 2 && matrix.rows == 2) {
        if(err != NULL)
            *err = 0;
        matrix_t* val = matrix.values;
		return val[3] * val[0] - val[1] * val[2];
	}
    else 
        if(err != NULL)
            *err = 1;
}

Matrix matrix_add(Matrix A, Matrix B, int* err) {

    if(A.rows == B.rows && A.columns == B.columns) {
        Matrix C = create_matrix(A.rows, A.columns);
        for(int i = 0; i < A.rows * A.columns; i++)
            C.values[i] = A.values[i] + B.values[i];
        return C;
    }
}


Matrix create_matrix(int rows, int columns) {
    Matrix temp;
    temp.columns = columns;
    temp.rows = rows;
    temp.values = (matrix_t*)malloc(rows * columns * sizeof(matrix_t));
    return temp;
};

Matrix matrix_transpose(Matrix matrix);