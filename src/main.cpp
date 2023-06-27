#include <stdlib.h>
#include <iostream>
#include <map>

#include "cube.hpp"


#define print(x) std::cout << x << std::endl;

using namespace rc;

void testCube(); 

int main(int argc, char **argv)
{
    Facelet f = Facelet(U, 0, 0);
    Cubie c = Cubie(f);
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
    
    char *i = &moves[0];
    while(*(i++) != '/0')
    {
        c.turn(moveMap.at(*i)); 
    }
}
