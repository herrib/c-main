#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H

#include <stdint.h>

typedef enum {
  OHMS = (uint16_t)1,
  DECAOHMS = 1000,
  KILOOHMS = 1000,
  MEGAOHMS = 1000000,
  GIGAOHMS = 1000000000,
} resistor_t;

typedef enum {
  BLACK = (uint16_t) 0,
  BROWN = 1,
  RED = 2,
  ORANGE = 3,
  YELLOW = 4,
  GREEN = 5,
  BLUE = 6,
  VIOLET = 7,
  GREY = 8,
  WHITE = 9,
} resistor_band_t;

typedef struct {
  uint16_t value;
  resistor_t unit;
} resistor_value_t;


resistor_value_t color_code(resistor_band_t[]);

#endif