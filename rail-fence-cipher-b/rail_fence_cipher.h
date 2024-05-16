#ifndef RAIL_FENCE_CIPHER_H
#define RAIL_FENCE_CIPHER_H

#include <stddef.h>

char *encode(char *text, size_t rails);

char *decode(char *ciphertext, size_t rails);

void get_rails(char *text, size_t rails, char **ref);

int *get_size_rails(char *text, size_t rails);

#endif
