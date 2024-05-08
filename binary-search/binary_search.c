#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
  int size = (int)length;
  if ((size < 1) || (value > arr[size-1]) ||(value < arr[0])) {
    return NULL;
  }

  int max = size;
  int min = 0;
  int cursor;
    while (min <= max) {
    cursor = (max + min) / 2;
    if (value < arr[cursor]) {
      max = cursor - 1;
    } else if (value > arr[cursor]) {
      min = cursor + 1;
    } else if (arr[cursor] == value) {
      return &arr[cursor];
    }
  }
  return NULL;
}