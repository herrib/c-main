#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h> 

typedef int buffer_value_t;
typedef struct {
  size_t capacity;
  size_t size;
  buffer_value_t *first;
  buffer_value_t *last;
  buffer_value_t data[];
} circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t);
int16_t write(circular_buffer_t *, buffer_value_t);
int16_t overwrite(circular_buffer_t *, buffer_value_t);
int16_t read(circular_buffer_t *, buffer_value_t *);
void delete_buffer(circular_buffer_t *);
void clear_buffer(circular_buffer_t *);
#endif
