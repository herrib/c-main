#include "resistor_color_duo.h"


uint16_t color_code(resistor_band_t input[]) { return 10* input[0] + input[1]; }