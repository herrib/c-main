#include "word_count.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int count_words(const char *sentence, word_count_word_t *words) {

  int size = (int)strlen(sentence);
  memset(words, 0, sizeof(word_count_word_t) * 20);
  char *str = (char *)calloc(sizeof(char), size);
  strcpy(str, sentence);
  int start, end;
  start = end = 0;
  bool in = false;
  for (int idx = 0; idx < size; idx++) {
    if ((isalnum(str[idx])) || (str[idx] == '\'')) {
      if (!in) { // start of a word
        start = idx;
        in = true;
      }
      if ((in) && (idx == size - 1)) {
        if (idx - start > MAX_WORD_LENGTH) {
          return EXCESSIVE_LENGTH_WORD;
        }
        char *tmp = get_sub_string(str, start, idx + 1);
        update_words(words, tmp);
      }
    } else {
      if (in) { // end of a word
        end = idx;
        if (idx - start > MAX_WORD_LENGTH) {
          return EXCESSIVE_LENGTH_WORD;
        }
        char *tmp = get_sub_string(str, start, end);
        update_words(words, tmp);
        in = false;
      }
    }
  }
  free(str);
   return count_w(words);
}

char *get_sub_string(char *str, int start, int end) {
  char *tmp = calloc(sizeof(char), end - start);
  for (int i = start, j = 0; i < end; i++, j++)  tmp[j] = tolower(str[i]);
  return tmp;
}

void update_words(word_count_word_t *words, char *p_word) {
  char *word = trim(p_word, '\'');
  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(words[i].text, word) == 0) {
      words[i].count++;
      break;
    }
    if (words[i].count == 0) {
      words[i].count++;
      strcpy(words[i].text, word);
      break;
    }
  }
  free (p_word);
}

int count_w(word_count_word_t *words) {
  int count = 0;
  for (int i = 0; i < MAX_WORDS; i++) {
    if (words[i].count != 0)    count++;
  }
  return count;
}

char *trim(char *word, char car) {
  int size = strlen(word);
  int start, end, count, i;
  start = end =count = i= 0;
  while ((word[i++]) == car) {
    count++;
  }
  start = i-1;
  i = size ;
  while ((word[i--]) == car)   count++;
  end = i;
  if (count == 0) {
    return word;
  }
  char *p = get_sub_string(word, start, end);
  return p;
}