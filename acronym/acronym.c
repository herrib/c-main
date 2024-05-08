#include "acronym.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *abbreviate(const char *phrase) {

  if ((!phrase) || (strlen(phrase)==0)) {
    return NULL;
  }
  size_t max_size =1;
  for (size_t i=0; i < strlen(phrase); i++) {
    if (!isalpha(phrase[i])) max_size++;
  }
  char *output = calloc(sizeof(char), max_size+1);

  if (isalpha(phrase[0]))
    output[0] = toupper(phrase[0]);

  for (size_t i = 1, j = 1; i < strlen(phrase); i++) {
    if (phrase[i - 1] == '\'') continue;
    if ((!isalpha(phrase[i - 1]))  && (isalpha(phrase[i]))) {
      output[j++] = toupper(phrase[i]);
    }
  }
  return output;
}