#include "nth_prime.h"
#include <stdbool.h>


uint32_t nth(uint32_t n)
{
    if (!n) {
        return 0;
    }
    uint32_t cpt = 0;
    uint32_t i = 0;
    for (i = 2; cpt != n; i++)
    {
        if (is_prime(i))
            cpt++;
    }
    return (i-1);
}

bool is_prime(uint32_t n)
{
    uint32_t idx = 2;
    uint32_t cpt = 0;
    while (n > 1)
    {
        if (n % idx)
        {
            idx++;
        }
        else
        {
            n /= idx;
            cpt++;
        }
    }
    return (cpt == 1);
}