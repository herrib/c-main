#include "luhn.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool luhn(const char *num) {

  char *chain = calloc(sizeof(char), (strlen(num) * sizeof(char)) + 1);
  for (int i = 0, j = 0; i < (int)strlen(num); i++) {
    if (isdigit(num[i])) {
      chain[j++] = num[i];
    } else if (num[i] != ' ') {
      free(chain);
      return false;
    }
  }
  int size = strlen(chain);
  if (size < 2) {
    free(chain);
    return false;
  }

  int key = 0;
  int tmp = 0;
  if (((chain[0] == '0') && ((size % 3 == 0))) || (size == 3)) {
    bool tmp = sin_luhn(chain);
    free(chain);
    return tmp;
  }

  for (int i = 0; chain[i]; i++) {
    tmp = chain[i] - '0';
    if (i % 2 == 0) {
      tmp *= 2;
      tmp = (tmp > 9) ? tmp - 9 : tmp;
    }
    key += tmp;
  }
  free(chain);
  return !(key % 10);
}

bool sin_luhn(char *chain) {
  int key = 0;
  int tmp = 0;
  for (int i = 0; chain[i]; i++) {
    tmp = chain[i] - '0';
    if (i % 2 == 1) {
      tmp *= 2;
      tmp = (tmp > 9) ? tmp - 9 : tmp;
    }
    key += tmp;
  }
  return !(key % 10);
}