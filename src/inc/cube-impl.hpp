#ifndef CUBE_IMPL_HPP
#define CUBE_IMPL_HPP

#include "cube.hpp"
#include <stdlib.h>

using namespace rc; 

typedef struct s_Facelet
{
    const char i, j;
    Face face;
} Facelet;

size_t to_index(Face f, const char i, const char j)
{
        return f*NB_FACES+3*i+3*j;
}

Color to_color(Face f)
{
    switch(f)
    {
        case F:
            return GREEN;
            break;
        case R:
            return RED;
            break;
        case L:
            return ORANGE;
            break;
        case B:
            return BLUE;
            break;
        case U:
            return WHITE;
            break;
        case D:
            return YELLOW;
            break;
        default:
            break;

    }
}

#endif