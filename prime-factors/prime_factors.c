#include "prime_factors.h"

size_t find_factors(uint64_t value, uint64_t buf[MAXFACTORS]) {
  size_t count = 0, div = 2;
  while (value > 1) {
    if (value % div)
      div += 1;
    else {
      buf[count++] = div;
      value /= div;
    }
  }
  return count;
}