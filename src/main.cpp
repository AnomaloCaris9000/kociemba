#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <array>


#include "cube.hpp"


using namespace rc;

int main(int argc, char **argv)
{
    char c;
    Face f; 
    Cube cube; 
    while(c != '!')
    {
        std::cout << cube << std::endl;
        std::cin >> c; 
        switch(c)
        {
            case 'F':
                f = F;
                break; 
            case 'U':
                f = U; 
                break;
            case 'R':
                f = R;
                break;
            case 'D':
                f = D;
                break;
            case 'B':
                f = B; 
                break;
            case 'L':
                f = L; 
                break; 
            default:
                break; 
        }
        cube.turn(f);
    } 

    exit(EXIT_SUCCESS);
}