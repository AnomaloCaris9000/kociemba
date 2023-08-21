#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <map>

#include "app.hpp"
#include "cube.hpp"


#define print(x) std::cout << x << std::endl;

using namespace rc;

void testCube();

int main()
{
    App app = App();
    app.launchLoop();
    // delete app
    return 0;
}

void testCube()
{
    Cube c; 
    print(c); 

    char moves[] = "FRULBD"; 
    std::map<char, Face> moveMap;
    moveMap['F'] = F; 
    moveMap['R'] = R;
    moveMap['U'] = U;  
    moveMap['L'] = L; 
    moveMap['B'] = D;
    moveMap['D'] = B; 
    
    int i = 0;
    while(i < 0)
    {
        print("Move" << moves[i])
        c.turn(moveMap.at(moves[i]));
        print(c);
        i++;
    }
}