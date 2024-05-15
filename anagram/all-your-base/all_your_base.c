#include "all_your_base.h"
#include <math.h>
#include <stdlib.h>

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length)
{
    int32_t total = 0;
    if (((input_length) <= 0) || (input_base <= 1) || (output_base <= 1))
        return 0;
    for (int i = (int)input_length - 1, j = 0; i >= 0; i--)
    {
        if ((digits[i] < 0) || (digits[i] >= input_base))
            return 0;
        total += digits[i] * (int32_t)pow(input_base, j++);
        digits[i] = 0;
    }
    int8_t *tmp = calloc(sizeof(int8_t), DIGITS_ARRAY_SIZE + 1);
    int count = 0;
    while (total / output_base >= 1)
    {
        tmp[count++] = total % output_base;
        printf("%d\n", tmp[count - 1]);
        total /= output_base;
    }
    tmp[count] = total % output_base;
    for (int i = count, j = 0; i >= 0; i--, j++)
    {
        digits[j] = tmp[i];
    }
    free(tmp);
    return count + 1;
}