#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <array>

#include "cube-defs.hpp"
#include "coord.hpp"
#include "stickers.hpp"


namespace rc
{

class Cube
{
    private:
        Coord m_coord;
        Stickers m_stickers;
    
    public:
        Cube&  turn         (Face const face);
        Color  colorAt      (Face const face, int row, int col) const;
        Color  centerColorAt(Face const face); 
        Color  edgeColorAt  (Face const face); 
        bool   isSolved()   const;
        Coord  coord()      const;
        Stickers scheme()     const; 
};

};

///@brief for printing 
std::ostream& operator << (std::ostream &flux, const rc::Cube& cube);


#endif