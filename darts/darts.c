#include "darts.h"
#include <math.h>

uint8_t score(coordinate_t l) {
    float r_outer = 10.0;
    float r_middle = 5.0;
    float r_inner = 1.0;
    float dart = sqrt(l.x * l.x + l.y * l.y);

    if (dart <= r_inner) {
        return 10;
    } else if (dart <= r_middle) {
        return 5;
    } else if (dart <= r_outer) {
        return 1;
    }
    return 0;
}