#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <array>
#include "cube-defs.hpp"


namespace rc
{

class Cube
{ 
    private:
        std::array<int, NB_STICKERS> m_data; 
    public:
        Cube();
        Color colorAt(Face, const char, const char) const;
        Cube& turn(Face); 
        bool isSolved() const;
};

};

std::ostream& operator << (std::ostream &flux, const rc::Cube &cube);

#endif