#include "armstrong_numbers.h"
#include <math.h>
#include <stdio.h>

bool is_armstrong_number(int candidate) {
  if (candidate == 0) {
    return true;
  }
  int size = get_size(candidate);
  return (candidate == calculate(candidate, size));
}

int get_size(int candidate) {
  int size, count;
  for (size = 1, count = 0; (candidate / size) >= 1; size *= 10, count += 1) ;
  return count;
}

int calculate(int candidate, int size) {
  int tmp, result = 0;
  for (int i = size; i > 0; i--) {
    tmp = (int)(candidate / pow(10, i - 1)) % 10;
    result += tmp * pow(tmp, size - 1);
  }
  return result;
}