#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H
#define MAX_SIZE 5

struct numeral {
  int value;
  char roman[MAX_SIZE];
};

char *to_roman_numeral(unsigned int number);
int get_size_number(int input);
char *get_roman_numeral(int number);
void set_output(char *output, int number);
#endif
