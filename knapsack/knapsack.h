#ifndef KNAPSACK_H
#define KNAPSACK_H
#include <stddef.h>

typedef struct {
   unsigned int weight;
   unsigned int value;
} item_t;

int maximum_value(unsigned int maximum_weight,item_t items[], size_t item_count);

int **  init_bitmap(size_t size,size_t n );
void free_bitmap(int **bitmap, size_t nb_lines) ;
#endif
