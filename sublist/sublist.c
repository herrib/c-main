#include "sublist.h"
#include <stdio.h>

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) {

 if (base_list_element_count == 0) {
    if (list_to_compare_element_count == 0) {
      return EQUAL;
    } else {
      return SUPERLIST;
    }
  }
  if (list_to_compare_element_count == 0) {
    return SUBLIST;
  } 
  comparison_result_t result ;
  if (list_to_compare_element_count <= base_list_element_count) {
    result = comparison(list_to_compare, base_list, list_to_compare_element_count,
                      base_list_element_count);
  } else {
    result = comparison(base_list,list_to_compare,
                      base_list_element_count,  list_to_compare_element_count);
    if (result == SUBLIST) {
      result = SUPERLIST;
    }
  }
  return result;
}

comparison_result_t comparison(int *lower_list, int *larger_list,
                               size_t lower_list_size,
                               size_t larger_list_size) {

  size_t j = 0;
  size_t i = 0;
  comparison_result_t result;

  while (j < larger_list_size) {
    if (lower_list[i] == larger_list[j]) {
      while (i < lower_list_size && (j + i) < larger_list_size) {
        if (lower_list[i] == larger_list[j + i]) {
          i++;
        } else {
          break;
        }
      }
    }
    if (i == lower_list_size) {
      break;
    } else {
      i = 0;
      j++;
    }
  }
  if (i == lower_list_size) {
    if (i == larger_list_size) {
      result = EQUAL;
    } else {
      result = SUBLIST;
    }
  } else {
    result = UNEQUAL;
  }
  return result;
}