

#include "sum_of_multiples.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)

{
  unsigned int total = 0;
  if (factors[0] == 0) {
    return total;
  }
  int max = number_of_factors * (limit / factors[0]);
  unsigned int *tmp = calloc(sizeof(unsigned int), max);

  unsigned int count = 0;
  for (unsigned int i = 0; i < number_of_factors; i++) {
    if (factors[i] == 0) {
      continue;
    }
    for (unsigned int j = 1; factors[i] * j < limit; j++) {
      tmp[count++] = factors[i] * j;
    }
  }
  int i, j, k;
  unsigned c = 0;
  for (i = 1; i < max; i++) {
    if (tmp[i] < tmp[i - 1]) {
      j = 0;
      while (tmp[j] < tmp[i])
        j++;
      c = tmp[i];
      for (k = i - 1; k >= j; k--)
        tmp[k + 1] = tmp[k];
      tmp[j] = c;
    }
  }
  for (int i = 0; i < max; i++) {
     if (tmp[i] != tmp[i+1]) {
      total += tmp[i];
    }
  }
  free(tmp);
  return total;
}