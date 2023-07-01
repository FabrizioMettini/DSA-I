#include "matrix.h"

#include <assert.h>
#include <stdio.h>

struct Matrix_ {
  double **elems;
  size_t nrows;
  size_t ncols;
};

Matrix* matrix_create(size_t nrows, size_t ncols) {
  assert(ncols > 0 && nrows > 0);

  Matrix *matrix = malloc(sizeof(Matrix));
  assert(matrix != NULL);

  matrix->elems = malloc(sizeof(double *) * nrows); 
  assert(matrix->elems);
  for (size_t i = 0; i < nrows; i++) {
    matrix->elems[i] = malloc(sizeof(double) * ncols); 
    assert(matrix->elems[i]);

    for (size_t j = 0; j < ncols; j++) {
      matrix->elems[i][j] = 0.0;
    }
  }

  matrix->nrows = nrows;
  matrix->ncols = ncols;

  return matrix;
}

void matrix_destroy(Matrix* matrix) {
  for (size_t i = 0; i < matrix->nrows; i++) {
    free(matrix->elems[i]);
  }
  free(matrix->elems);
  free(matrix);
}

double matrix_read(Matrix* matrix, size_t row, size_t col) {
  return matrix->elems[row][col];
}

void matrix_write(Matrix* matrix, size_t row, size_t col, double val) {
  matrix->elems[row][col] = val;
}

size_t matrix_num_rows(Matrix* matrix) {
  return matrix->nrows;
}

size_t matrix_num_columns(Matrix* matrix) {
  return matrix->ncols;
}

void matrix_print(Matrix *matrix) {
  for (size_t i = 0; i < matrix->nrows; i++) {
    for (size_t j = 0; j < matrix->ncols; j++) {
      printf("%lf ", matrix->elems[i][j]);
    }
    printf("\n");
  }
}

void matrix_swap_rows(Matrix *matrix, size_t row1, size_t row2) {
  double *temp;
  temp = matrix->elems[row1];
  matrix->elems[row1] = matrix->elems[row2];
  matrix->elems[row2] = temp;
}

void matrix_insert_row(Matrix *matrix, size_t row) {
  size_t rows = matrix_num_rows(matrix) + 1;
  size_t columnas = matrix_num_columns(matrix);
  matrix->elems = realloc(matrix->elems, sizeof(double *) * rows);
  assert(matrix->elems != NULL);
  matrix->nrows++;
  if (row < rows - 1) {
    for (size_t i = rows - 1; row < i; i--) {
      matrix->elems[i] = matrix->elems[i - 1];
    }
  } else {
    row = rows - 1;
  }
  matrix->elems[row] = malloc(sizeof(double) * columnas);
  assert(matrix->elems[row] != NULL);
  for (size_t i = 0; i < columnas; i++) {
    matrix_write(matrix, row, i, 0.0);
  }
}