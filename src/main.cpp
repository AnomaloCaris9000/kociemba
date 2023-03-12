#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <array>


#include "inc/cube-defs.hpp"

#define println(x) std::cout << x << std::endl;


using namespace rc;

int main(int argc, char **argv)
{
    Color scheme[NB_FACES];
    scheme[F] = GREEN;
    scheme[B] = BLUE;
    scheme[R] = RED;
    scheme[L] = ORANGE;
    scheme[U] = WHITE;
    scheme[D] = YELLOW;

    println(scheme[edge_face(UB, GOOD)]);

    exit(EXIT_SUCCESS);
}