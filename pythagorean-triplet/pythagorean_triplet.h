#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

#include <stdint.h>

typedef  struct {
int a;
int b;
int c;
} triplet_t;
typedef struct {
    uint16_t count;
    triplet_t *triplets; 
} triplets_t;

triplets_t * triplets_with_sum(uint16_t);
void free_triplets(triplets_t *);
#endif
