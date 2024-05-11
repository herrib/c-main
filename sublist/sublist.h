#ifndef SUBLIST_H
#define SUBLIST_H

#include <stddef.h>

typedef enum { EQUAL, UNEQUAL, SUBLIST, SUPERLIST } comparison_result_t;

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count);

comparison_result_t comparison (int *lower_list, int *larger_list,
                                size_t lower_list_size,
                                size_t larger_list_size);

#endif
