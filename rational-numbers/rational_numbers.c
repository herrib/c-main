#include "rational_numbers.h"
#include <math.h>
#include <stdlib.h>

rational_t add(rational_t a, rational_t b) {

  rational_t result = {
      a.numerator * b.denominator + a.denominator * b.numerator,
      a.denominator * b.denominator,
  };
  return reduce(result);
}

rational_t subtract(rational_t a, rational_t b) {

  rational_t result = {
      a.numerator * b.denominator - a.denominator * b.numerator,
      a.denominator * b.denominator,
  };
  return reduce(result);
}
rational_t multiply(rational_t a, rational_t b) {
  rational_t result = {
      a.numerator * b.numerator,
      a.denominator * b.denominator,
  };
  return reduce(result);
}
rational_t divide(rational_t a, rational_t b) {
  rational_t result = {
      a.numerator * b.denominator,
      a.denominator * b.numerator,
  };
  return reduce(result);
}

rational_t absolute(rational_t a) {

  rational_t result = {
      abs(a.numerator),
      abs(a.denominator),
  };
  return reduce(result);
}
rational_t exp_rational(rational_t a, int16_t n) {

  int m = abs(n);
  int numerator = (int)pow(a.numerator, m);
  int denominator = (int)pow(a.denominator, m);
  if (n < 0) {
    int prov = numerator;
    numerator = denominator;
    denominator = prov;
    if (n % 2 != 0) {
      numerator *= -1;
      denominator *= -1;
    }
  }
  rational_t result = {
      numerator,
      denominator,
  };
  return reduce(result);
}
float exp_real(int16_t n, rational_t a) {
  float p = pow(n, a.numerator);
  return pow(p, 1.0 / a.denominator);
}

rational_t reduce(rational_t a) {

  int numerator = a.numerator;
  int denominator = a.denominator;

  if (numerator == 0) {
    denominator = 1;
  } else {
    for (int i = 2; i <= abs(numerator); i++) {
      while ((numerator % i == 0) && (denominator % i == 0)) {
        denominator /= i;
        numerator /= i;
      };
    }
  }
  if (((denominator < 0) && (numerator < 0)) ||
      ((denominator < 0) && (numerator > 0))) {
    numerator *= -1;
    denominator *= -1;
  }

  rational_t result = {numerator, denominator};
  return result;
}
