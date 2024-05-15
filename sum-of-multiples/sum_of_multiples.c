#include "sum_of_multiples.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
{

    int **list;
    list = calloc(sizeof(*list), number_of_factors);
    for (size_t i = 0; i < number_of_factors; i++)
    {
        list[i] = calloc(sizeof(unsigned int), (limit / factors[i]) + 1);
        size_t factor = factors[i];
        for (size_t j = 1; factor * j < limit; j++)
        {
            list[i][j - 1] = factor * j;
            printf("list[%ld][%ld] = %d\n", i, j - 1, list[i][j - 1]);
        }
    }

    return 0;
}