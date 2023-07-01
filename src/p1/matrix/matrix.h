#ifndef __MATRIZ_H__
#define __MATRIZ_H__

#include <stdlib.h>

typedef struct Matrix_ Matrix;

Matrix* matrix_create(size_t nrows, size_t ncols);

void matrix_destroy(Matrix* matrix);

double matrix_read(Matrix* matrix, size_t row, size_t col);

void matrix_write(Matrix* matrix, size_t row, size_t col, double val);

size_t matrix_num_rows(Matrix* matrix);

size_t matrix_num_columns(Matrix* matrix);

void matrix_print(Matrix *matrix);

void matrix_swap_rows(Matrix *matrix, size_t fil1, size_t fil2);

void matrix_insert_row(Matrix *matrix, size_t pos);

#endif /* __MATRIZ_H__ */
