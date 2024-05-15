#include "triangle.h"

bool is_equilateral(triangle_t s)
{

    if (!is_triangle(s))
        return false;
    return ((s.a == s.b) && (s.b == s.c));
}

bool is_isosceles(triangle_t s)
{
    if (!is_triangle(s))
        return false;
    return ((s.a == s.b) || (s.a == s.c) || (s.b == s.c));
}

bool is_scalene(triangle_t s)
{
    if (!is_triangle(s))
    {
        return false;
    }
    return (!is_isosceles(s));
}

bool is_triangle(triangle_t s)
{
    return ((s.a + s.b >= s.c) && (s.b + s.c >= s.a) && (s.a + s.c >= s.b) && ((s.a*s.b*s.c) !=0));
}