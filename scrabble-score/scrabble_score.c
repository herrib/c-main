#include "scrabble_score.h"
#include <ctype.h>
#include <stddef.h>

unsigned int score(const char *word) {
  unsigned int count = 0;
  for (size_t i = 0; word[i]; i++) {
    count += letter_score(word[i]);
  }
  return count;
}
unsigned int letter_score(char c)
 {
  if (!isalpha(c))
    return 0;
  int ref[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
               1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  c = toupper(c);
  return ref[c - 'A'];
}