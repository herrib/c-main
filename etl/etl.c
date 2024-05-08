#include "etl.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(const legacy_map *input, const size_t input_len, new_map **output) {

  size_t size = 0;

  for (size_t i = 0; i < input_len; i++) {
    size += strlen(input[i].keys);
  }
  *output = malloc(sizeof(new_map) * size);

  for (size_t i = 0, k = 0; i < input_len; i++) {
    for (size_t j = 0; j < strlen(input[i].keys); j++) {
      (* output)[k].key = tolower(input[i].keys[j]);
      (* output)[k].value = input[i].value;
      k++;
    };
  }
  qsort(*output, size, sizeof(new_map), comparator);
  return size;
}

int comparator ( const void * first, const void * second ) {
    char firstC = ((new_map *) first)->key;
    char secondC = ((new_map *) second)->key;
    return firstC > secondC;
}
