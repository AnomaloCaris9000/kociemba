#include <stdlib.h>
#include <iostream>

#include "coord.hpp"


#define print(x) std::cout << x << std::endl;


int main(int argc, char **argv)
{
    print("Hello World!");
    for(int i = 0; i < argc; i++)
    {
        print(argv[i]);
    }

    rc::Coord c;
    c *= c;

    for(int i = 0; i < 10; i++)
    {
        print(c.m_cornerO[i]);
    }

    exit(EXIT_SUCCESS); 
}