#include "atbash_cipher.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char *atbash_encode(const char *input)
{

    char *output = calloc(sizeof(char), strlen(input) + 1);

    if (!input)
    {
        return output;
    }
    char alphabet[SIZE_ALPHABET];

    for (char idx = 'a'; idx <= 'z'; idx++)
    {
        alphabet[-(int)(idx - 'z')] = idx;
    }
    int count_word = 0;
    for (size_t i = 0, j = 0; i < strlen(input); i++)
    {
        if (isalnum(input[i]))
        {
            if (count_word % 5 ==0 && count_word !=0)
            {
                output[j++] = ' ';
            }
            if isalpha (input[i])
            {
                output[j++] = alphabet[tolower(input[i]) - 'a'];
            }
            else
            {
                output[j++] = input[i];
            }
            count_word++;
        }
    }
    return output;
}

char *atbash_decode(const char *input)
{

    char *output = calloc(sizeof(char), strlen(input) + 1);
    return output;
}