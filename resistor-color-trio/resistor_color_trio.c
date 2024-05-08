#include "resistor_color_trio.h"
#include <math.h>
#include <stdio.h>

resistor_value_t color_code(resistor_band_t input[]) {

  uint32_t coeff = 1;
  for (uint16_t i = 0; i < input[2]; i++) {
    coeff *= 10;
  }
  int unit = 1;
  switch (input[2]) {
  case BLACK:
  case BROWN:
   unit = OHMS;
    break;
     case RED:
    unit = DECAOHMS;
    break;
   case ORANGE:
  case YELLOW:
  case GREEN:
    unit = KILOOHMS;
    break;
  case BLUE:
  case VIOLET:
  case GREY:
    unit = MEGAOHMS;
    break;
  case WHITE:
    unit = GIGAOHMS;
    break;
  default:
    unit = 0;
    break;
  }
  printf("coeff %d / unit %d = %d || %d \n", coeff, unit, coeff / unit,
        (10 * input[0] + input[1])*(coeff / unit));
  return (resistor_value_t){
      .value = (10 * input[0] + input[1]) * (coeff / unit),
      .unit = unit,
  };
}