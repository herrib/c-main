#include "list_ops.h"
#include <stdio.h>
#include <string.h>

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]) {
  list_t *list =
      (list_t *)malloc(sizeof(size_t) + sizeof(list_element_t) * length);
  list->length = length;
  // for (size_t i = 0; i < length; i++) {
  //   list->elements[i] = elements[i];
  // }
  if (elements)
    memcpy(list->elements, elements, sizeof(*elements) * length);
  return list;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {
  /*size_t length = list1->length + list2->length;
  list_element_t *p = malloc(sizeof(list_element_t) * length);
  list_element_t *start = p;
  size_t i = 0;
  for (i = 0; i < list1->length; i++) {
    *p++ = list1->elements[i];
  }
  for (size_t j = 0; j < list2->length; j++) {
    *p++ = list2->elements[j];
  }
  return new_list(length, start);
  */
  if (!list1 || !list2)
    return NULL;
  list_t *list = new_list(list1->length + list2->length, NULL);
  if (!list)
    return NULL;
  memcpy(list->elements, list1->elements,
         sizeof(list_element_t) * list1->length);
  memcpy(list->elements + list1->length, list2->elements,
         sizeof(list_element_t) * list2->length);
  return list;
}

// returns the length of the list
size_t length_list(list_t *list) {
  if (list) {
    return list->length;
  }
  return 0;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {

  size_t count = 0;
  for (size_t i = 0; i < list->length; i++) {
    if (filter(list->elements[i])) {
      count++;
    }
  }
  list_element_t *p = malloc(sizeof(list_element_t) * count);
  list_element_t *start = p;
  size_t i = 0;
  for (i = 0; i < list->length; i++) {
    if (filter(list->elements[i])) {
      *p++ = list->elements[i];
    }
  }
  return new_list(count, start);
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
  list_element_t *p = malloc(sizeof(list_element_t) * list->length);
  list_element_t *start = p;
  for (size_t i = 0; i < list->length; i++) {
    *p++ = map(list->elements[i]);
  }
  return new_list(list->length, start);
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
  for (size_t i = 0; i < list->length; i++) {
    initial = foldl(initial, list->elements[i]);
  }
  return initial;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
  for (int i = (int)list->length - 1; i >= 0; i--) {
    initial = foldr(list->elements[i], initial);
  }
  return initial;
}

list_t *reverse_list(list_t *list) {

  if (list->length == 0) {
    return new_list(0, list->elements);
  }
  list_element_t *p = malloc(sizeof(list_element_t) * list->length);
  list_element_t *start = p;
  for (int i = (int)list->length - 1; i >= 0; i--) {
    *p++ = list->elements[i];
  }
  return new_list(list->length, start);
}

// destroy the entire list
void delete_list(list_t *list) { free(list); }
