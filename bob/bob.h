#ifndef BOB_H
#define BOB_H
#include <stdbool.h>
#define ANSWER 40

typedef struct {
  char answer[ANSWER];
} answer_t;

typedef answer_t answers_t[];

char *hey_bob(char *greeting);
bool full_num(char *input);

#endif
