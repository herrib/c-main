#include "bob.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

answers_t answers = {
    {"Sure."},
    {"Whoa, chill out!"},
    {"Calm down, I know what I'm doing!"},
    {"Fine. Be that way!"},
    {"Whatever."},
};

char *hey_bob(char *greeting) {
  int size = (int)strlen(greeting);
  char *cp = calloc(sizeof(char), size);
  strcpy(cp, greeting);
  char *answer = calloc(sizeof(char), ANSWER);
  if (isspace(cp[size - 1])) {
    int i = size - 1;
    while (isspace(cp[i]) && i >= 0) {
      cp[i] = '\0';
      i--;
    }
  }
  if (strlen(cp) == 0) {
    strcpy(answer, answers[3].answer);
    free(cp);
    return answer;
  }
  char end = cp[strlen(cp) - 1];
  char *tmp = calloc(sizeof(char), strlen(cp));
  if (full_num(cp)) {
    if (end == '?') {
      strcpy(answer, answers[0].answer);
    } else {
      strcpy(answer, answers[4].answer);
    }
    free(cp);
    free(tmp);
    return answer;
  }
  for (int i = 0; i < (int)strlen(cp); i++)
    tmp[i] = toupper(cp[i]);
  if (strcmp(cp, tmp) == 0) {
    if (end == '?') {
      strcpy(answer, answers[2].answer);
    } else {
      strcpy(answer, answers[1].answer);
    }
    free(cp);
    free(tmp);
    return answer;
  }
  if (end == '?') {
    strcpy(answer, answers[0].answer);
    free(cp);
    free(tmp);
    return answer;
  }
  strcpy(answer, answers[4].answer);
  free(cp);
  free(tmp);
  return answer;
}

bool full_num(char *input) {
  int count_alp = 0;
  int count_num = 0;
  for (size_t i = 0; i < strlen(input); i++) {
    if (!isalnum(input[i])) {
      continue;
    }
    if (isdigit(input[i])) {
      count_num++;
    }
    count_alp++;
  }
  return (count_num == count_alp);
}