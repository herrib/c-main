#include "eliuds_eggs.h"

int egg_count(int input) {
  int count = 0;
  while (input  >= 1) {
    if (input % 2 == 1)   count++;
    input /=2;
  }
  return count;
}
