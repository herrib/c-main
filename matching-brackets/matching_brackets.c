#include "matching_brackets.h"
#include <stdlib.h>
#include <string.h>

bool is_paired(const char *input) {

  if (!(int)strlen(input)) {
    return true;
  }
  char *expected = calloc(sizeof(char), strlen(input) /2 +1);
  int counter = 0;
  for (int i = 0; input[i]; i++) {
    char value = input[i];
    switch (value) {
    case '{':
      expected[counter++] = '}';
      break;
    case '[':
      expected[counter++] = ']';
      ;
      break;
    case '(':
      expected[counter++] = ')';
      break;
    case '}':
      counter--;
      if (!check(expected, value, counter)) {
        return false;
      }
      break;
    case ']':
      counter--;
      if (!check(expected, value, counter)) {
        return false;
      }
      break;
    case ')':
      counter--;
      if (!check(expected, value, counter)) {
        return false;
      }
      break;
    }
  }
  if (strlen(expected) > 0) {
    free(expected);
    return false;
  }
  free(expected);
  return true;
}

bool check(char *expected, char value, int counter) {
  if (counter < 0) {
    free(expected);
    return false;
  } else if (expected[counter] != value) {
    free(expected);
    return false;
  } else {
    expected[counter] = '\0';
  }
  return true;
}