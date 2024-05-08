#include "yacht.h"
#include <stdbool.h>
#include <stdio.h>

int score(dice_t dice, category_t category) {

  int map[6] = {0};
  int count = 0;
  bool count_3 = false;
  bool count_2 = false;

  for (int i = 0; i < 5; i++) {
    map[dice.faces[i] - 1] += 1;
  }

  switch (category) {
  case ONES:
    return map[ONES];
  case TWOS:
    return map[TWOS] * 2;
  case THREES:
    return map[THREES] * 3;
  case FOURS:
    return map[FOURS] * 4;
  case FIVES:
    return map[FIVES] * 5;
  case SIXES:
    for (int i = 0; i < 6; i++) {
      if (map[i] > 1) {
        return 0;
      }
      count += +map[i];
    }
    if (count == 5) {
      return 6;
    }
    break;
  case FULL_HOUSE:
    for (int i = 0; i < 6; i++) {
      if (map[i] == 3) {
        count_3 = true;
        count += 3 * (i + 1);
      }
      if (map[i] == 2) {
        count_2 = true;
        count += 2 * (i + 1);
      }
    }
    if (count_2 && count_3) {
      return count;
    }
    break;
  case FOUR_OF_A_KIND:
    for (int i = 0; i < 6; i++) {
      if (map[i] >= 4) {
        return (i + 1) * 4;
      }
    }
    break;
  case YACHT:
    for (int i = 0; i < 6; i++) {
      if (map[i] == 5)
        return 50;
    }
    break;
    ;
  case LITTLE_STRAIGHT:
    for (int i = 0; i < 6; i++) {
      count += map[i];
      if (map[i] > 1) {
        return 0;
      }
    }
    if ((count == 5) && ((map[5] == 0))) {
      return 30;
    }
    break;

  case BIG_STRAIGHT:
    for (int i = 0; i < 6; i++) {
      count += map[i];
      if (map[i] > 1) {
        return 0;
      }
    }
    if ((count == 5) && (map[0] == 0)) {
      return 30;
    }
    break;
  case CHOICE:
    for (int i = 0; i < 6; i++) {
      count += map[i] * (i + 1);
    }
    return count;
  default:
    break;
  }
  return 0;
}
