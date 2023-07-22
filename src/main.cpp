#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <map>

#include "cube.hpp"


#define print(x) std::cout << x << std::endl;

using namespace rc;

void testCube();

int main(int argc, char **argv)
{
    Coord coord;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 3; j++) 
        {
            for(int k = 0; k < 3; k++)
            {
                Facelet f((Face)i, j, k);
                Cubie c(f); 
                if(c.type() == EDGE) std::cout << c << " -> " << coord.at(c) << std::endl;
            }
        }
    }
    testCube();
}

void testCube()
{
    Cube c; 
    char moves[] = "FRULBD"; 
    std::map<char, Face> moveMap;
    moveMap['F'] = F; 
    moveMap['R'] = R;
    moveMap['U'] = U;  
    moveMap['L'] = L; 
    moveMap['B'] = D;
    moveMap['D'] = B; 
    
    int i = 0;
    while(i < 6)
    {
        print(c);
        c.turn(moveMap.at(moves[i]));
        i++;
    }
}