#include "anagram.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_anagrams(const char *subject, struct candidates *candidates) {

  char *ref = calloc(sizeof(char), strlen(subject) + 1);
  strcpy(ref, subject);
  for (size_t i = 0; i < candidates->count; i++) {
  char *candidate =
        calloc(sizeof(char), strlen(candidates->candidate[i].word) + 1);
    strcpy(candidate, candidates->candidate[i].word); 
    candidates->candidate[i].is_anagram =
        (is_anagram(ref, candidate)) ? IS_ANAGRAM : NOT_ANAGRAM;
  free(candidate);
  }
  free(ref);
}

bool is_anagram(char *ref, char *candidate) {

  if (strlen(ref) != strlen(candidate)) {
    return false;
  }
 if (is_equal(ref, candidate)) {
    return false;
  }
  char *tmp = calloc(sizeof(char), strlen(ref) + 1);
  strcpy(tmp, ref);
  for (size_t i = 0; candidate[i]; i++) {
        bool in = false;
    for (size_t j = 0; tmp[j]; j++) {
      if (tolower(candidate[i]) == tolower(tmp[j])) {
        in = true;
        tmp[j] = '*';
        break;
      }
    }
    if (!in) {
      free(tmp);
      return false;
    }
  }
  free(tmp);
  return true;
}

bool is_equal(char *ref, char *candidate) {
  for (size_t i = 0; i < strlen(ref); i++)
    if (tolower(ref[i]) != tolower(candidate[i])) {
      return false;
    }
  return true;
}