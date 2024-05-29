#include "palindrome_products.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

product_t *get_palindrome_product(int from, int to) {

  product_t *output = calloc(sizeof(product_t), 1);
   if (from > to) {
    sprintf(output->error, "invalid input: min is %d and max is %d", from, to);
    return output;
  }
  int size_reference = 0;
  int *ref = get_reference(from, to, &size_reference);
  int current = 0;
  bool first = true;
  for (int i = 0; i < size_reference - 1; i++) {
    for (int j = i; j < size_reference; j++) {
      current = ref[i] * ref[j];
      if (is_palindrom(ref[i], ref[j])) {
        if (first) {
          output->factors_sm = create_product(ref[i], ref[j]);
          first = false;
          output->smallest = current;
          output->largest = current;
          continue;
        }
        if (current < output->smallest) {
          output->smallest = current;
          delete_product(output->factors_sm);
          output->factors_lg = create_product(ref[i], ref[j]);

        } else if (current == output->smallest) {
          output->factors_sm->next = create_product(ref[i], ref[j]);

        } else if (current > output->largest) {
          output->largest = current;
          if (output->factors_lg) {
            delete_product(output->factors_lg);
          }
          output->factors_lg = create_product(ref[i], ref[j]);
        } else {
          output->factors_lg->next = create_product(ref[i], ref[j]);
        }
      }
    }
  }
  if (!output->factors_sm) {
    sprintf(output->error, "no palindrome with factors in the range %d to %d", from, to);
  }
  free(ref);
  return output;
}

void free_product(product_t *pr) {
  if (pr->factors_sm) {
    delete_product(pr->factors_sm);
    if (pr->factors_lg) {
      delete_product(pr->factors_lg);
    }
  }
  free(pr);
}

int get_size_palindrom(int i, int j) {
  int n = 1;
  int product = i * j;
  while (product / 10 > 0) {
    n++;
    product /= 10;
  }
  return n;
}

int *get_reference(int from, int to, int *size) {
  *size = (to - from) + 1;
  int *ref = calloc(sizeof(int), *size);
  for (int i = from, j = 0; i <= to; i++) {
    ref[j++] = i;
  }
  return ref;
}

bool is_palindrom(int i, int j) {
  int p = i * j;
  int size = get_size_palindrom(i, j);
  char *product = calloc(sizeof(char), size);
  int k = 0;
  while (p >= 1) {
    product[k] = (p % 10) + '0';
    p /= 10;
    k++;
  }
  for (int l = 0; l < size / 2; l++) {
    if (product[l] != product[size - l - 1]) {
      free(product);
      return false;
      }
  }
  free(product);
  return true;
}

factor_t *create_product(int i, int j) {
  factor_t *p = calloc(sizeof(factor_t), 1);
  p->factor_a = i;
  p->factor_b = j;
  return p;
}

void delete_product(factor_t *p) {
  factor_t *seq = p->next;
  factor_t *tmp = p;
  while (seq) {
    tmp = seq->next;
    free(seq);
    seq = tmp;
  }
  free(p);
}