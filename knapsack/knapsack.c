#include "knapsack.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX USHRT_MAX / 2
#define LIMIT 15

int maximum_value(unsigned int maximum_weight, item_t items[],
                  size_t item_count) {

  size_t base = item_count;
  unsigned short int nb_comb = 1;
  for (size_t i = 0; i < base; i++) {
    if (nb_comb > MAX) {
      return (EXIT_FAILURE);
    }
    nb_comb *= 2;
  }
  nb_comb--;
  int **bitmap = init_bitmap(nb_comb, base);

  int max_value = 0;
  for (size_t i = 0; i < nb_comb; i++) {
    size_t tot_value = 0;
    size_t tot_weight = 0;
    for (size_t j = 0; j < base; j++) {
      if (bitmap[i][j]) {
        tot_value += items[j].value;
        tot_weight += items[j].weight;
      }
    }
    if ((tot_weight <= maximum_weight) && ((int)tot_value >= max_value))
      max_value = (int)tot_value;
  }
  free_bitmap(bitmap, nb_comb);
  return max_value;
}

int **init_bitmap(size_t nb_lines, size_t base) {

  int **bitmap = calloc(sizeof(int *), nb_lines);
  for (size_t i = 0; i < nb_lines; i++) {
    bitmap[i] = calloc(sizeof(int), base);
    memset(bitmap[i], 0, base);
  }

  for (size_t i = 0; i < nb_lines; i++) {
    int cursor = i + 1;
    size_t j = 0;
    while ((cursor != 1) && (j < base)) {
      bitmap[i][j] = cursor % 2;
      j++;
      cursor /= 2;
    }
    bitmap[i][j] = cursor;
  }
  return bitmap;
}
void free_bitmap(int **bitmap, size_t nb_lines) {
  for (size_t i = 0; i < nb_lines; i++) {
    free(bitmap[i]);
  }
  free(bitmap);
}