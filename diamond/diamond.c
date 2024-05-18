#include "diamond.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **make_diamond(const char letter) {

  int rows = (2 * (int)(letter - 'A') + 1);
  char **output = calloc(sizeof(char *), rows+1);
  for (int i = 0; i < rows; i++) {
    output[i] = calloc(sizeof(char), rows);
    memset(output[i], ' ', rows);
  }
  int row = 0;
  for (char a = 'A'; a <= letter; a++) {
    int col = rows / 2; 
    output[row][col-row] = a;
    output[row][col+row] = a;
    row++;
  }
  int mid = row-2;
    for (char a = letter-1; a >= 'A'; a--, row++, mid--) {
    memcpy(output[row],output[mid], rows+1);
  }
  return output;
}

void free_diamond(char **diamond) {

    for (int i = 0; diamond[i]; i++) {
        free(diamond[i]);
    }
    free(diamond);
}