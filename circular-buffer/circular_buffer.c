#include "circular_buffer.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/* deeply inspired by tugrul's solution
The solution is really a model for all students in C!
*/

circular_buffer_t *new_circular_buffer(size_t capacity) {

  circular_buffer_t *buffer =
      malloc(sizeof(*buffer) + sizeof(buffer_value_t) * capacity);
  buffer->capacity = capacity;
  buffer->size = 0;
  buffer->first = buffer->data;
  buffer->last = buffer->data;
  return buffer;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
  if (!buffer) {
    errno = ENODATA;
    return EXIT_FAILURE;
  }
  printf(" write: size %lu - tail %p - head %p - "
         "capacity %lu\n",
         buffer->size, (void *)buffer->first, (void *)buffer->last,
         buffer->capacity);

  if ((buffer->size - buffer->capacity) == 0) {
    errno = ENOBUFS;
    return EXIT_FAILURE;
  }
  return overwrite(buffer, value);
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
  if (!buffer) {
    errno = ENODATA;
    return EXIT_FAILURE;
  }
  if (buffer->size == buffer->capacity) {
    // we must remove the first in value (discard) 
    buffer_value_t discard;
    read(buffer, &discard);
  }
  // last in value: pointer last
  *(buffer->last) = value;
  // increment pointer last => will be the next available slot
  buffer->last++;
  if (buffer->last == buffer->data + buffer->capacity) {
    // higher position reached => the next available slot will be at the root
    buffer->last = buffer->data;
  }
  ++buffer->size;
  return EXIT_SUCCESS;
}

void delete_buffer(circular_buffer_t *buffer) {
  printf("delete\n");
  if (buffer) {
    printf("delete only an existing buffer: %p \n", (void *)buffer);
    free(buffer);
  }
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
  printf("read\n");
  printf("size %lu - first %p - last %p - capacity %lu\n", buffer->size,
         (void *) buffer->first,(void *) buffer->last, buffer->capacity);

  if (!buffer || !value || buffer->size == 0) {
    printf("exit on read - conditions not met \n");
    errno = ENODATA;
    return EXIT_FAILURE;
  }
  printf("read\n");
  printf("size %lu - first %p - last %p - capacity %lu\n", buffer->size,
         (void *) buffer->first,(void *) buffer->last, buffer->capacity);
  *value = *(buffer->first);
  buffer->first++;
  if (buffer->first == buffer->data + buffer->capacity) {
    buffer->first = buffer->data;
  }
  --buffer->size;
  return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer) {
  buffer->size = 0;
  buffer->first = buffer->data;
  buffer->last = buffer->data;
}