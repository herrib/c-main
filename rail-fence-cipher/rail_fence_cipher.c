#include "rail_fence_cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encode(char *text, size_t rails) {

  int size = strlen(text);
  char **ref = calloc(sizeof(char *), rails + 1);
  for (size_t i = 0; i < rails; i++) {
    ref[i] = calloc(sizeof(char), size + 1);
  }
  int *idx = calloc(sizeof(int), rails + 1);
  char *output = calloc(sizeof(char), size + 1);
  int inc = 1;
  int rail = -1;

  for (int i = 0; text[i]; i++) {
    if (rail == (int)rails - 1) {
      inc = -1;
    }
    if (rail == 0) {
      inc = 1;
    }
    rail += inc;
    ref[rail][idx[rail]] = text[i];
    idx[rail]++;
  }
  int k = 0;
  for (size_t i = 0; i < rails; i++) {
    for (size_t j = 0; ref[i][j]; j++) {
      output[k++] = ref[i][j];
    }
  }
  free(idx);
  for (size_t i = 0; i < rails; i++) {
    free(ref[i]);
  }
  free(ref);
  return output;
}

char *decode(char *ciphertext, size_t rails) {
  printf("%s -rails %ld\n", ciphertext, rails);
  int unit = (int)strlen(ciphertext) / (2 * ((int)rails - 1));
  int pad = (int)strlen(ciphertext) % unit;
  int size = (int)strlen(ciphertext);
  if (pad != 0) {
    size += (2 * ((int)rails - 1) - pad);
    unit++;
  }
  printf("=> size %d - init %ld - unit %d\n", size, strlen(ciphertext), unit);

  int *idx = calloc(sizeof(int), rails + 1);
  char *output = calloc(sizeof(char), size);
  char **ref = calloc(sizeof(char *), rails + 1);
  for (size_t i = 0; i < rails; i++) {
    if ((i == 0) || (i == rails - 1)) {
      ref[i] = calloc(sizeof(char), unit + 1);
    } else {
      ref[i] = calloc(sizeof(char), (2 * unit) + 1);
    }
  }

  int rail = 0;
  int nb_units = 0;

  for (size_t i = 0; ciphertext[i]; i++) {
    nb_units = i / unit;
    if (nb_units == 0) {
      ref[rail][idx[rail]] = ciphertext[i];
      printf("ref[%d][%d] = %c\n", rail, idx[rail], ref[rail][idx[rail]]);
      idx[rail]++;
      continue;
    }
    if (pad) {
      if (((nb_units - 1) % 2 == 0) && (i % unit == 0) &&
          ((int)i < size - unit - 1)) {
        printf("bingo %d\n", nb_units);
        rail++;
      }
      if ((int)i == size - unit - 1) {
        rail++;
      }
    } else {
      if (((nb_units - 1) % 2 == 0) && (i % unit == 0) &&
          ((int)i < size - unit)) {
        rail++;
      }
      if ((int)i == size - unit) {
        rail++;
      }
    }
    ref[rail][idx[rail]] = ciphertext[i];
    printf("i: %ld- ref[%d][%d] = %c\n", i, rail, idx[rail],
           ref[rail][idx[rail]]);
    idx[rail]++;
  }

  return output;
}
