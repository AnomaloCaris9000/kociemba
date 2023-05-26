#include <stdlib.h>
#include <iostream>
#include <map>

#include "cube.hpp"


#define print(x) std::cout << x << std::endl;

using namespace rc;

void testCube(); 

int main(int argc, char **argv)
{
    testCube();
    print("Test ended!"); 
    exit(EXIT_SUCCESS); 
}

void testCube() {
    Cube c; 
    char m; 
    std::map<char, Face> moveMap;
    moveMap['f'] = F; 
    moveMap['r'] = R;
    moveMap['u'] = U;  
    moveMap['l'] = L;  
    moveMap['d'] = D;
    moveMap['b'] = B;   

    m = '\0';
    while(!c.isSolved())
    {
        print(c);  
        std::cin >> m;
        if(m == '!') break;
        else c.turn(moveMap.at(m)); 
    }
}