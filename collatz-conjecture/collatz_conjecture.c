#include "collatz_conjecture.h"

int steps(int start) {
  int tour = 0;
  if (start <= 0) {
    return -1;
  }
  while (start !=1) {
    start = (start % 2 == 0) ? start / 2 : 3 * start + 1;
    tour++;
  }
  return tour;
}
