#include "largest_series_product.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int64_t largest_series_product(char *digits, size_t span)
{

    size_t size = strlen(digits);
    if ((span < 1) || (span > size))
        return -1;

    int *buf = calloc(sizeof(int), span + 1);
    int64_t total, tmp;
    total = 0;
    for (size_t i = 0; i <= size - span ; i++)
    {
        if (!isdigit(digits[i]))
        {
            free(buf);
            return -1;
        }
        tmp = 1;
        for (size_t j = 0; j < span; j++)
        {
            buf[j] = digits[i + j] - '0';
            tmp *= buf[j];
        }
        if (tmp > total)
            total = tmp;     
    }
    free(buf);
    return total;
}