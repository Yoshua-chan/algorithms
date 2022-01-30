#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

//TODO: Obliczanie wyznacznika macierzy z definicji rekurencyjnie
//TODO: Mnożenie macierzy przez liczbę
//TODO: Transpozycja macierzy

#define DET_DIMENSION_ERROR 1
#define MUL_DIMENSION_ERROR 2
#define ADD_DIMENSION_ERROR 3

Matrix matrix_mul(Matrix A, Matrix B, int* err) {
    
    if(A.columns == B.rows) {
        Matrix C = create_matrix(A.rows, B.columns, NULL);

        for(int row = 0; row < C.rows; row++) {
            for(int col = 0; col < C.columns; col++) {
                for(int i = 0; i < A.columns; i++) {
                    *(C.values + C.columns * row + col) += *(A.values + A.columns * row + i) * *(B.values + B.columns * i + col);
                    }
                }
        }

        return C;
    } else {
        *err = MUL_DIMENSION_ERROR;
    }
}

char* err_message(int err) {
    switch(err) {
        case DET_DIMENSION_ERROR:
            return "Could not calculate matrix determinant: matrix not square";
        break;
        case MUL_DIMENSION_ERROR:
            return "Could not multiply matrices: invalid dimensions";
        break;
        case ADD_DIMENSION_ERROR:
            return "Could not add matrices: matrices have different dimensions";
        break;
    }
}

Matrix matrix_mul_by_num(Matrix matrix, matrix_t number, int* err) {
    Matrix temp = create_matrix(matrix.rows, matrix.columns, NULL);
    for(int i = 0; i < matrix.rows * matrix.columns; i++)
        temp.values[i] = matrix.values[i];
    return temp;
}

matrix_t matrix_det(Matrix matrix, int* err) {
    if(matrix.columns == 1 && matrix.rows == 1)
        return *(matrix.values);
    if(matrix.columns == 2 && matrix.rows == 2)
        return matrix_det_2x2(matrix, err);
    else  if(matrix.columns == 3 && matrix.rows == 3) {
        return matrix_det_3x3(matrix, err);
    } else {
        return -2137;
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
        Matrix C = create_matrix(A.rows, A.columns, NULL);
        for(int i = 0; i < A.rows * A.columns; i++)
            C.values[i] = A.values[i] + B.values[i];
        return C;
    }
    else {
        *err = ADD_DIMENSION_ERROR;
    }
}


Matrix create_matrix(int rows, int columns, matrix_t* source) {
    Matrix temp;
    temp.columns = columns;
    temp.rows = rows;
    temp.values = (matrix_t*)malloc(rows * columns * sizeof(matrix_t));
    memset((void*)temp.values, 0, columns * rows);
    if(source != NULL) {
        for(int i = 0; i < columns * rows; i++) {
            temp.values[i] = source[i];
        }
    }
    return temp;
}

void printmatrix(Matrix matrix) {
    for(int row = 0; row < matrix.rows; row++) {
        printf("| ");
        for(int col = 0; col < matrix.columns; col++) {
            printf("%2.0f ", *(matrix.values + matrix.columns * row + col));
        }
        printf("|\n");
    }
}


Matrix matrix_transpose(Matrix matrix) {
    Matrix temp = create_matrix(matrix.columns, matrix.rows, NULL);
    //for(int row = 0; row < )
}