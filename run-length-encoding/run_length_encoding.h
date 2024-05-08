#ifndef RUN_LENGTH_ENCODING_H
#define RUN_LENGTH_ENCODING_H
#include <stddef.h>

char *encode(const char *text);
char *decode(const char *data);
size_t add_int(char *encoded, size_t index, int count) ;
int get_int(char *buffer);
int get_size(const char *data);
#endif
