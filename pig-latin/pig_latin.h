#ifndef PIG_LATIN_H
#define PIG_LATIN_H
#include <stdbool.h>
#define RULE_SIZE 3
typedef struct {
  int size;
  char rule[RULE_SIZE];
} rule_t;
typedef rule_t rules_t[];
char *translate(const char *phrase);
char *get_output(char *phrase);
bool is_vowel(char c);
bool is_rule1(const char *phrase);
bool is_rule4(const char *phrase);
bool is_rule(const char *phrase, int num);
void set_output(char *output, const char *phrase, int size);
#endif
