#include "rotational_cipher.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key) {
  size_t size = strlen(text);
  char *chain = (char *)calloc(sizeof(chain), size + 1);
  for (int idx_text = 0, idx_chain = 0; text[idx_text]; idx_text++) {
    int tmp = text[idx_text] + shift_key;
    if (isupper(text[idx_text])) {
      chain[idx_chain++] = (tmp > 'Z') ? 'A' + (tmp - 'Z') - 1 : tmp;
    } else if (islower(text[idx_text])) {
      chain[idx_chain++] = (tmp > 'z') ? 'a' + (tmp - 'z') - 1 : tmp;
    } else {
      chain[idx_chain++] = text[idx_text];
    }
  }
  return chain;
}