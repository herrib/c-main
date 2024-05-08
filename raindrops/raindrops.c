#include "raindrops.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void convert(char result[], int drops) {

  int idx = 0;
  char p3[] = "Pling";
  char p5[] = "Plang";
  char p7[] = "Plong";
  char *str = calloc(sizeof(char), BUFFER_LENGTH );
  snprintf(str, BUFFER_LENGTH , "%d", drops);
  bool flag = true;

  if (drops % 3== 0) {
    for (size_t  i = 0; i < strlen(p3); i++) {
      result[idx++] = p3[i];
    }
    flag = false;
  }
  if (drops % 5 == 0) {
    for (size_t  i = 0; i < strlen(p5); i++) {
      result[idx++] = p5[i];
    }
    flag = false;
  }
  if (drops % 7== 0) {
    for (size_t  i = 0; i < strlen(p7); i++) {
      result[idx++] = p7[i];
    }
    flag = false;
  }
  if (flag) {
    for (int i =0; i < BUFFER_LENGTH; i++){
      result[idx++] = str[i];
    }
  }
  free(str);
}
/*
#include "raindrops.h"
#include <stdio.h>
#include <string.h>
char *convert(char result[], int nr) {
    strcpy(result, "");
    if (nr % 3 == 0)
        strcat(result, "Pling");
    if (nr % 5 == 0)
        strcat(result, "Plang");
    if (nr % 7 == 0)
        strcat(result, "Plong");
    if (!strcmp(result, ""))
        sprintf(result, "%d", nr);
    return result;
}
*/