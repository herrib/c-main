#include "pascals_triangle.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

uint8_t **create_triangle(size_t rows)
{
    bool empty = false;

    if (rows == 0)
    {
        empty = true;
        rows = 1;
    }
    uint8_t **ptr;

    ptr = calloc(sizeof(*ptr), rows);

    if (!ptr)
    {
        exit(-1);
    }

    for (size_t i = 0; i < rows; i++)
    {
        ptr[i] = calloc(sizeof(**ptr), rows);
        if (!ptr[i])
        {
            for (size_t j = 0; j < i; j++)
            {
                free(ptr[i]);
            }
            free(ptr);
            exit(-1);
        }
        if (empty)
            ptr[i][0] = 0;
        else
            ptr[i][0] = 1;

        for (size_t t = 1; t < rows; t++)
        {
            ptr[i][t] = 0;
        }
    }
    for (size_t i = 0; i < rows - 1; i++)
    {
        for (size_t j = 0; j < rows - 1; j++)
        {
            ptr[i + 1][j + 1] = ptr[i][j] + ptr[i][j + 1];
        }
    }
    return ptr;
}

void free_triangle(uint8_t **triangle, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        free(triangle[i]);
    }
    free(triangle);
}