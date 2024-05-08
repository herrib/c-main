#include "series.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

slices_t slices(char *input_text, unsigned int substring_length) {

  slices_t s;
  if ((strlen(input_text) < substring_length) || (substring_length == 0)) {
    s.substring = NULL;
    s.substring_count = 0;
    return s;
  }
  int nb_slices = strlen(input_text) - (int)substring_length + 1;
  s.substring_count = nb_slices;
  s.substring = calloc(sizeof(char *), nb_slices);
  for (int i = 0; i < nb_slices; i++) {
    s.substring[i] = calloc(sizeof(char), substring_length);
  }

  /*for (int i = 0; i < nb_slices; i++) {
    for (int j = 0; j < (int)substring_length; j++) {
      s.substring[i][j] = input_text[i + j];
    }
  } */
  for (int i = 0; i < nb_slices; i++) {
    strncpy(s.substring[i], &input_text[i], substring_length);
  }

  return s;
}
