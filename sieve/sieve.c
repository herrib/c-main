#include "sieve.h"
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {

  bool ref[limit + 1];
  memset(ref, true, limit + 1);
  uint32_t count = 0;
  for (uint32_t idx = 2; idx <= limit && count < max_primes; idx++) {
    if (ref[idx]) {
      count++;
      *primes++ = idx;
      for (uint32_t idy = idx * idx; idy <= limit; idy += idx) {
        ref[idy] = false;
      }
    }
  }

  return count;
}