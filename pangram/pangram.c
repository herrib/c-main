#include "pangram.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define SIZE_ALPHABET 26

bool is_pangram(const char *sentence)
{
if (! sentence) {
    return false;
}
    bool alpha[SIZE_ALPHABET] = {false};
    int size = strlen(sentence);
    for (int i = 0; i < size; i++)
    {
       if (isalpha(sentence[i])) alpha[toupper(sentence[i]) - 'A'] = true;
    }
    for (int i = 0; i < SIZE_ALPHABET; i++)
    {
        if (!alpha[i])
            return false;
    }
    return true;
}