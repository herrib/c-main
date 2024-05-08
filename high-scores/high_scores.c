#include "high_scores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
  return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
  int32_t cursor = 0;
  for (size_t i = 0; i < scores_len; i++) {
    if (scores[i] > cursor)
      cursor = scores[i];
  }
  return cursor;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {

  int32_t *list = calloc(sizeof(int32_t), scores_len);
  memcpy(list, scores, scores_len * sizeof(int32_t));
  int tot;
  tot = (scores_len >= 3) ? 3 : scores_len;
  qsort(list, scores_len, sizeof(int32_t), comparator);
  for (int i = 0; i < tot; i++)
    output[i] = list[i];
  free(list);
  return tot;
}

int comparator(const void *first, const void *second) {
  int firstInt = *(const int *)first;
  int secondInt = *(const int *)second;
  return secondInt - firstInt;
}