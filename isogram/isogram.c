#include "isogram.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

bool is_isogram(const char phrase[]){

  if (!phrase) {
        return false;
   }
 
    int size, count;
    size = strlen(phrase);

    if ( size == 0) {
      return true;
    }
    
    for (int i =0; i < size; i++) {
        char c = tolower(phrase[i]);
        if (( c < 97 || c > 122) && (c != 45) && (c != 32)) {
               return false;
        }
         if ((c == 32) || (c == 45)) {
            continue;
        }
        count = 0;
        for (int j= 0; j < size; j++) {
           
            if (c == tolower(phrase[j])) {
                count++;
            }
        }
        if (count > 1) {
            return false;
        }
    }
    return true;
}