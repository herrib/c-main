#include "pig_latin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VOWELS 5
#define RULES 7

char vowels[] = {'a', 'e', 'i', 'o', 'u'};
char suffix[] = "ay";
rules_t rules = {
    {2, "ch"},  {2, "st"},  {2, "qu"},  {2, "th"},
    {3, "squ"}, {3, "thr"}, {3, "sch"},
};

char *translate(const char *phrase) {

  char *tmp = calloc(sizeof(char), strlen(phrase));
  strcpy(tmp, phrase);
  const char *separators = " ";
  char *final_output = calloc(sizeof(char), strlen(phrase) * 2);
  char *strToken = strtok(tmp, separators);
  int count = 0;
  while (strToken != NULL) {
    count++;
    if (count > 1) {
      strcat(final_output, separators);
    }
    strcat(final_output, get_output(strToken));
    strToken = strtok(NULL, separators);
  }
  return final_output;
}

char *get_output(char *phrase) {
  char *output = calloc(sizeof(char), strlen(phrase) * 2);
  char c = phrase[0];
  if (is_rule4(phrase)) {
    int rank = 0;
    for (int i = 1; i < (int)strlen(phrase); i++) {
      if (phrase[i] == 'y') {
        rank = i;
        break;
      }
    }
    char *tmp = strchr(phrase, 'y');
    char *beg = calloc(sizeof(char), rank);
    strncpy(beg, phrase, rank);
    strcpy(output, tmp);
    strcat(output, beg);
    strcat(output, suffix);
    free(beg);
    return output;
  }
  if ((is_vowel(c)) || (is_rule1(phrase))) {
    strcat(output, phrase);
    strcat(output, suffix);
    return output;
  }
  if (is_rule(phrase, 3)) {
    set_output(output, phrase, 3);
    return output;
  }

  if (is_rule(phrase, 2)) {
    set_output(output, phrase, 2);
    return output;
  }
  set_output(output, phrase, 1);
  return output;
}

bool is_vowel(char c) {
  for (int i = 0; i < VOWELS; i++) {
    if (c == vowels[i]) {
      return true;
    }
  }
  return false;
}

bool is_rule1(const char *phrase) {
  char *tmp = calloc(sizeof(char), 2);
  strncpy(tmp, phrase, 2);
  if ((strcmp(tmp, "xr") == 0) || (strcmp(tmp, "yt") == 0)) {
    free(tmp);
    return true;
  }
  free(tmp);
  return false;
}

bool is_rule4(const char *phrase) {
  bool vow = false;
  bool in = false;
  for (int i = 1; i < (int)strlen(phrase); i++) {
    if ((phrase[i] != 'y') && (is_vowel(phrase[i]))) {
      vow = true;
      break;
    }
    if (phrase[i] == 'y') {
      in = true;
      break;
    }
  }
  if ((!in) || ((in) && (vow))) {
    return false;
  }
  return true;
}
bool is_rule(const char *phrase, int num) {
  char *tmp = calloc(sizeof(char), 4);
  char *ref = calloc(sizeof(char), num);

  strncpy(ref, phrase, num);
  for (int i = 0; i < RULES; i++) {
    if (rules[i].size == num) {
      strcpy(tmp, rules[i].rule);
      if (strcmp(tmp, ref) == 0) {
        free(tmp);
        free(ref);
        return true;
      }
    }
  }
  free(tmp);
  free(ref);
  return false;
}

void set_output(char *output, const char *phrase, int size) {
  strncpy(output, phrase + size, strlen(phrase));
  char *prov = calloc(sizeof(char), size);
  strncpy(prov, phrase, size);
  strcat(output, prov);
  strcat(output, suffix);
  free(prov);
}