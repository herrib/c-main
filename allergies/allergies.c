#include "allergies.h"
#include <stdlib.h>
#include <string.h>

bool is_allergic_to(allergen_t item, int score) {
  bool allergens[ALLERGEN_COUNT] = {false};
  set_allergens(allergens, score);
  return allergens[item];
}

allergen_list_t get_allergens(int score) {
  allergen_list_t list;
  list.count = 0;
  bool allergens[ALLERGEN_COUNT] = {false};
  set_allergens(allergens, score);
  for (int i = 0; i < ALLERGEN_COUNT; i++) {
    if (allergens[i]) list.count++;
  }
  memcpy(list.allergens, allergens, sizeof(allergens));
  return list;
}

void set_allergens(bool *allergens, int score) {
  for (; score > 255; score -= 256);
  if (score % 2 != 0) {
    allergens[0] = true;
    score--;
  }
  for (int i = 128, j = 7; i > 1 && score > 0; i /= 2, j--) {
    if (i <= score) {
      score -= i;
      allergens[j] = true;
    }
  }
}