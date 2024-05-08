#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number) {
  unsigned int tot = 0;
  for (unsigned int i = 0; i <= number; i++) {
    tot += i * i;
  }
  return tot;
}
unsigned int square_of_sum(unsigned int number) {
  unsigned int tot = 0;
  for (unsigned int i = 0; i <= number; i++) {
    tot += i;
  }
  tot *= tot;
  return tot;
}
unsigned int difference_of_squares(unsigned int number) {
return square_of_sum(number) - sum_of_squares(number);
}