#include "binary.h"
#include <string.h>

int convert(const char *input) {
  int total = 0;
  for (int i = (int) strlen(input)-1, j= 0; i >=0; i--, j++) {
    if (input[i] == '1') {
      total += 1 << j;
    } else if (input[i] != '0') {
      return INVALID;
    }
  }
  return total;
}