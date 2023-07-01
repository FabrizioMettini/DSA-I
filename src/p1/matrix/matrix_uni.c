#include "matrix.h"

#include <assert.h>
#include <stdio.h>

struct Matrix_ {
  double *elems;
  size_t nrows;
  size_t ncols;
};

Matrix* matrix_create(size_t nrows, size_t ncols) {
  assert(nrows > 0 && ncols > 0);

  Matrix *matrix = malloc(sizeof(Matrix));
  assert(matrix != NULL);

  matrix->elems = malloc(sizeof(double) * nrows * ncols);
  assert(matrix->elems != NULL);

  matrix->nrows = nrows;
  matrix->ncols = ncols;

  for (size_t i = 0; i < nrows * ncols; i++) {
    matrix->elems[i] = 0.0;
  }

  return matrix;
}

void matrix_destroy(Matrix* matrix) {
  free(matrix->elems);
  free(matrix);
}

double matrix_read(Matrix* matrix, size_t row, size_t col) {
  assert(row < matrix->nrows && col < matrix->ncols);
  return matrix->elems[row * matrix->ncols + col];
}

void matrix_write(Matrix* matrix, size_t row, size_t col, double val) {
  assert(row < matrix->nrows && col < matrix->ncols);
  matrix->elems[row * matrix->ncols + col] = val;
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
      printf("%lf ", matrix->elems[i * matrix->ncols + j]);
    }
    printf("\n");
  }
}

void matrix_swap_rows(Matrix *matrix, size_t fil1, size_t fil2) {
  size_t m = matrix->nrows;
  assert((size_t) fil1 < m && (size_t) fil2 < m);
  size_t n = matrix->ncols;
  for (size_t i = 0; i < n; i++) {
    double temp = matrix_read(matrix, fil1, i);
    matrix_write(matrix, fil1, i, matrix_read(matrix, fil2, i));
    matrix_write(matrix, fil1, i, temp);
  }
}

void matrix_insert_row(Matrix *matrix, size_t pos) {
  size_t m = matrix->nrows;
  size_t n = matrix->ncols;
  matrix->elems = realloc(matrix->elems, sizeof(double) * (m + 1) * n);
  matrix->nrows += 1;
  for (size_t i = m - 1; i >= (size_t) pos; i--) {
    for (size_t j = 0; j < n; j++) {
      matrix_write(matrix, i + 1, j, matrix_read(matrix, i, j));
    }
  }
  for (size_t i = 0; i < n; i++) {
    matrix_write(matrix, pos, i, 0.0);
  }
}