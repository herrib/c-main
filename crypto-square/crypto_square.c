#include "crypto_square.h"
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char *ciphertext(const char *input) {
  size_t size_input = strlen(input);
  char *chain = calloc(sizeof(char), size_input + 1);
  char *p_chain = chain;
  if (strlen(input) == 0)
    return chain;
  for (size_t i = 0, j = 0; i < size_input + 1; i++) {
    if (isalnum(input[i]))
      chain[j++] = tolower(input[i]);
  }
  size_t row, column, size_output;
  size_output = strlen(chain);
  row = (size_t)round(sqrt(size_output));
  column = (row * row < size_output) ? row + 1 : row;
  char **output;
  output = calloc(sizeof(*output), row);
  for (size_t i = 0; i < row; i++) {
    output[i] = calloc(sizeof(**output), column);
    for (size_t j = 0; j < column; j++) {
      if (!*chain) {
        output[i][j] = ' ';
      } else {
        output[i][j] = *chain;
      }
      chain++;
    }
  }
  char *final = calloc(sizeof(char *), (row * column));
  char *s = final;
  for (size_t idx_column = 0; idx_column < column; idx_column++) {
    for (size_t idx_row = 0; idx_row < row; idx_row++) {
      *final++ = output[idx_row][idx_column];
    }
    if (idx_column < column - 1) {
      *final++ = ' ';
    }
  }
  for (size_t i = 0; i < row; i++) {
    free(output[i]);
  }
  free(p_chain);
  free(output);
  return s;
}
