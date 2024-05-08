#include "reverse_string.h"
#include <stdlib.h>
#include <string.h>

char *reverse(const char *value) {
  int size = strlen(value);
  char *output = (char *)calloc(sizeof(char), size + 1);
  char *start = output;
  for (int i = size - 1; i >= 0; i--, output++) {
    *output = value[i];
  }
  *output = '\0';
  return start;
}