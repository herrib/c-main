#include "pythagorean_triplet.h"
#include <stdlib.h>
triplets_t *triplets_with_sum(uint16_t sum) {
  triplets_t *triplets = (triplets_t *)malloc(sizeof(triplets_t));
  uint16_t count = 0;
  triplet_t *triplet = malloc(sizeof(triplet_t));
  for (int a = 1; a < sum / 3; a++) {
    for (int b = a + 1; b <= (sum - a) / 2; b++) {
      int c = sum - a - b;
      if (a * a + b * b == c * c) {
        count++;
        if (count > 1) {
          triplet = realloc(triplet, sizeof(triplet_t) * count);
        }
        triplet[count - 1] = (triplet_t){a, b, c};
      }
    }
  }
  triplets->count = count;
  triplets->triplets = triplet;
  return triplets;
}

void free_triplets(triplets_t *triplets) { free(triplets); }