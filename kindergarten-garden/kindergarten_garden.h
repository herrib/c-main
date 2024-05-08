#ifndef KINDERGARTEN_GARDEN_H
#define KINDERGARTEN_GARDEN_H

#include <stddef.h>

typedef enum { CLOVER = 0, GRASS = 1, RADISHES = 2, VIOLETS = 3, UNKNOWN = 4 } plant_t;

typedef struct {
   plant_t plants[4];
} plants_t;

plants_t plants(const char *diagram, const char *student);
size_t get_rank_student(const char * student) ;
plant_t get_code_plant(char c);
void get_sequence(char *diagrams, size_t rank, char *sequence);
#endif
