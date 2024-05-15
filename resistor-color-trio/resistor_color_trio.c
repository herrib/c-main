#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t input[])
{

    uint64_t value = (input[0] * 10 + input[1]);
    for (uint16_t i = 0; i < input[2]; i++) {
        value *= 10;
    }
    resistor_unit_t unit = OHMS;

    if (value < KILOOHMS)
    {
        unit = OHMS;
    }
    else if (value < MEGAOHMS)
    {
        unit = KILOOHMS;
    }
    else if (value < GIGAOHMS)
    {
        unit = MEGAOHMS;
    }
    else
    {
        unit = GIGAOHMS;
    }

    value /= unit;

    return (resistor_value_t){
        .value = value,
        .unit = unit,
    };
}