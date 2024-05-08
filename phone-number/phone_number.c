#include "phone_number.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *phone_number_clean(const char *input) {
  int size = strlen(input);
  char *tmp = (char *)calloc(size + 1, sizeof(char));
  char *p_tmp = tmp;
  char *output = (char *)calloc(sizeof(char), 10);
  char *p_output = output;
  memset(output, '0', 10);
  int count_tmp = 0;
  while (*input) {
    if (isdigit(*input)) {
      if ((count_tmp == 0) && (*input == '1')) {
        input++;
        continue;
      } else {
        *p_tmp++ = *input;
        count_tmp++;
      }
    }
    input++;
  }

  if (count_tmp != 10) {
    return output;
  }
  if ((tmp[0] < '2') || (tmp[3] < '2')) {
    return output;
  }
  while ((*output++ = *tmp++)) ;
  return p_output;
}