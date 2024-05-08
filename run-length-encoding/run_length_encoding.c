#include "run_length_encoding.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_INT 5

char *encode(const char *text) {

  size_t size = strlen(text);

  char *encoded = calloc(sizeof(char), strlen(text) + 1);
  if (size == 0) {
    return encoded;
  }
  int count = 0;
  int cursor = 0;
  for (size_t i = 0; i <= size - 1; i++) {
    if (text[i] == text[i + 1]) {
      count++;
      if (i == size - 1) {
        cursor = add_int(encoded, cursor, count + 1);
        encoded[cursor] = text[i];
        break;
      }
    } else {
      if (i == size - 1) {
        if (count > 0) {
          cursor = add_int(encoded, cursor, count + 1);
        }
        encoded[cursor++] = text[i];
        encoded[cursor] = text[i + 1];
      } else {
        if (count > 0) {
          cursor = add_int(encoded, cursor, count + 1);
        }
        encoded[cursor++] = text[i];
        count = 0;
      }
    }
  }
  return encoded;
}
char *decode(const char *data) {

  char *decoded = calloc(sizeof(char), get_size(data)+1);
  char *buffer = calloc(sizeof(char), MAX_SIZE_INT);
  int idx_b = 0;
  int idx_d = 0;
  int count = 0;
  bool digit = false;

  for (size_t i = 0; i < strlen(data); i++) {

    if (isdigit(data[i])) {
      digit = true;
      buffer[idx_b++] = data[i];
    } else {
      if (digit) {
        count += get_int(buffer);
        for (int j = 0; j < count; j++) {
          decoded[idx_d++] = data[i];
        }
        idx_b = 0;
        digit = false;
        count = 0;
      } else {
        decoded[idx_d++] = data[i];
      }
    }
  }
  free(buffer);
  return decoded;
}

size_t add_int(char *encoded, size_t index, int count) {
  char *buffer = calloc(sizeof(char), MAX_SIZE_INT);
  sprintf(buffer, "%d", count);
  for (size_t j = 0; buffer[j]; j++) {
    encoded[index++] = buffer[j];
  }
  free(buffer);
  return index;
}

int get_int(char *buffer) {
  int total = 0;
  for (int i = strlen(buffer) - 1, j = 1; i >= 0; i--, j *= 10) {
    total += (int)(buffer[i] - '0') * j;
    buffer[i] = '\0';
  }
  return total;
}

int get_size(const char *data) {
  char *buffer = calloc(sizeof(char), MAX_SIZE_INT);
  int idx = 0;
  int count = 0;
  bool digit = false;
  for (size_t i = 0; i < strlen(data); i++) {
    if (isdigit(data[i])) {
      digit = true;
      buffer[idx++] = data[i];
    } else {
      if (digit) {
        count += get_int(buffer);
        idx = 0;
        digit = false;
      }
    }
  }
  free(buffer);
  return strlen(data) + count;
}