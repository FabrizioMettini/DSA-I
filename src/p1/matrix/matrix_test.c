#include "matrix.h"

#include <assert.h>
#include <stdio.h>

#define NROWS 3
#define NCOLS 3

int main() {
  Matrix *matrix = matrix_create(NROWS, NCOLS);
  for (int i = 0; i < NROWS; i++) {
    matrix_write(matrix, i, i, 1);
  }
  matrix_print(matrix);
  matrix_swap_rows(matrix, 0, 2);

  printf("Exchanging rows 0 and 2\n");
  matrix_print(matrix);

  printf("Insert row (position 1)\n");
  matrix_insert_row(matrix, 1);
  matrix_print(matrix);

  matrix_destroy(matrix);
  return 0;
}