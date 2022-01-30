#ifndef MATRIX
#define MATRIX

//#define val(m, r, c) *(m.values + columns * r + c)
typedef double matrix_t;

struct Matrix {
	unsigned int columns;
	unsigned int rows;
	matrix_t* values;
};

typedef struct Matrix Matrix;


matrix_t matrix_det(Matrix matrix, int* err);
matrix_t matrix_det_3x3(Matrix matrix, int* err);
matrix_t matrix_det_2x2(Matrix matrix, int* err);

Matrix create_matrix(int rows, int columns, matrix_t* source);
Matrix matrix_transpose(Matrix matrix);
Matrix matrix_mul(Matrix A, Matrix B, int* err);
Matrix matrix_add(Matrix A, Matrix B, int* err);
Matrix matrix_mul_by_num(Matrix matrix, matrix_t number, int* err);
void printmatrix(Matrix matrix);

#endif