#include "roman_numerals.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3999
#define NB_NUMERALS 27
struct numeral numerals[] = {
    {1, "I"},    {2, "II"},    {3, "III"},  {4, "IV"},    {5, "V"},
    {6, "VI"},   {7, "VII"},   {8, "VIII"}, {9, "IX"},    {10, "X"},
    {20, "XX"},  {30, "XXX"},  {40, "XL"},  {50, "L"},    {60, "LX"},
    {70, "LXX"}, {80, "LXXX"}, {90, "XC"},  {100, "C"},   {400, "CD"},
    {500, "D"},  {500, "D"},   {600, "DC"}, {700, "DCC"}, {800, "DCCC"},
    {900, "CM"}, {1000, "M"},
};

char *to_roman_numeral(unsigned int number) {

  if (number > MAX) {
    char *output = calloc(sizeof(char), 1);
    return output;
  }
  int size = get_size_number(number);
  char *output = calloc(sizeof(char), MAX_SIZE * 4);

  if (number >= 1000) {
    for (int i = 0; i < (int)number / 1000; i++) {
      set_output(output, 1000);
    }
    number %= 1000;
  }
  if (number >= 900) {
    set_output(output, 900);
    number %= 100;
  }
  if (number >= 500) {
    set_output(output, (number / 100) * 100);
    number %= 100;
  }
  if (number >= 400) {
    set_output(output, 400);
    number %= 100;
  }
  if (number >= 100) {
    for (int i = 0; i < (int)number / 100; i++) {
      set_output(output, 100);
    }
    number %= 100;
  }
  if (number >= 10) {
    set_output(output, (number / 10) * 10);
    number %= 10;
  }
  if (number > 0) {
    set_output(output, number);
  }
  return output;
}

int get_size_number(int input) {
  int size = 0;
  while (input > 0) {
    input /= 10;
    size++;
  }
  return size;
}

char *get_roman_numeral(int number) {

  for (int i = 0; i < NB_NUMERALS; i++) {
    if (number == numerals[i].value) {
      return numerals[i].roman;
    }
  }
  return NULL;
}

void set_output(char *output, int number) {
  char *r = get_roman_numeral(number);
  strcat(output, r);
}