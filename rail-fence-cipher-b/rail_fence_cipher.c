#include "rail_fence_cipher.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *encode(char *text, size_t rails)
{
    char **ref = calloc(sizeof(char *), rails + 1);
    char *output = calloc(sizeof(char), strlen(text) + 1);
    for (size_t i = 0; i < rails; i++)
    {
        ref[i] = calloc(sizeof(char), strlen(text) + 1);
    }
    get_rails(text, rails, ref);
    size_t k = 0;
    for (size_t i = 0; i < rails; i++)
    {
        for (size_t j = 0; ref[i][j]; j++)
        {
            output[k++] = ref[i][j];
        }
    }
    for (size_t i = 0; i < rails; i++)
    {
        free(ref[i]);
    }
    free(ref);
    return output;
}

char *decode(char *ciphertext, size_t rails)
{
    char *output = calloc(sizeof(char), strlen(ciphertext) + 1);
    int *idx = get_size_rails(ciphertext, rails);
    int *ref_idx = calloc(sizeof(int), rails + 1);
    char **ref = calloc(sizeof(char *), rails + 1);
    for (size_t i = 0; i < rails; i++)
    {
        ref[i] = calloc(sizeof(char), idx[i] + 1);
    }
    int k = 0;
    for (int i = 0; i < (int)rails; i++)
    {
        for (int j = 0; j < idx[i]; j++)
        {
            ref[i][j] = ciphertext[k++];
        }
    }
    int inc = 1;
    int rail = 0;
    for (int i = 0; ciphertext[i]; i++)
    {
        output[i] = ref[rail][ref_idx[rail]];
        ref_idx[rail]++;
        if (rail == (int)rails - 1)
        {
            inc = -1;
        }
        if (rail == 0)
        {
            inc = 1;
        }
        rail += inc;
    }
    free(idx);
    free(ref_idx);
    for (int i = 0; i < (int)rails; i++)
    {
        free(ref[i]);
    }
    free(ref);
    return output;
}

void get_rails(char *text, size_t rails, char **ref)
{
    int *idx = calloc(sizeof(int), rails + 1);
    int inc = 1;
    int rail = 0;
    for (size_t i = 0; text[i]; i++)
    {
        ref[rail][idx[rail]] = text[i];
        idx[rail]++;
        if (rail == (int)rails - 1)
        {
            inc = -1;
        }
        if (rail == 0)
        {
            inc = 1;
        }

        rail += inc;
    }
    free(idx);
}

int *get_size_rails(char *text, size_t rails)
{
    int *idx = calloc(sizeof(int), rails + 1);
    int inc = 1;
    int rail = 0;

    for (size_t i = 0; text[i]; i++)
    {
        idx[rail]++;
        if (rail == (int)rails - 1)
        {
            inc = -1;
        }
        if (rail == 0)
        {
            inc = 1;
        }

        rail += inc;
    }
    return idx;
}
