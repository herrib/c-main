#include "space_age.h"
#include <stdio.h>
#define SECONDS 31557600.0
#define DAYS 365.25

float age(planet_t planet, int64_t seconds) {

  if (((int)planet < 0) || (seconds < 0)) {
    return -1.0;
  }
  float periods[] = {0.2408467, 0.61519726, 1.0,       1.8808158,
                     11.862615, 29.447498,  84.016846, 164.79132};
  return (seconds / SECONDS) / periods[planet];
}
