#include "resistor_color.h"
#include <stdlib.h>

resistor_band_t *colors() {
  int count;
  for (resistor_band_t i = BLACK; i <= WHITE; i++, count++);
  resistor_band_t *colors =
      (resistor_band_t *)malloc(sizeof(resistor_band_t) * count);
  resistor_band_t *start = colors;
  for (resistor_band_t i = BLACK; i <= WHITE; i++) {
    *(colors++) = i;
  }
  return start;
}
resistor_band_t color_code(resistor_band_t color) { return color; }