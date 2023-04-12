#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <array>

#include "cube-defs.hpp"


namespace rc
{

class Cube
{ 
    public:
        Cube();
        Color colorAt(Face, char, char) const;
        Cube& turn(Face); 
        bool isSolved() const;
};

};

///@brief for printing 
std::ostream& operator << (std::ostream &flux, const rc::Cube& cube);


#endif