#ifndef CUBE_HPP
#define CUBE_HPP

#include "coord.hpp"

#include <iostream>


namespace rc {


/// @brief Implementation of a real world rubik's cube object.
class Cube 
{
    private:
        Coord m_coord;
        Face m_moveTable[NB_FACE]; 
        Color m_scheme[NB_FACE];
        Coord m_coordTable[NB_FACE];
    public:

        Cube(); 


        Color at(Face f, byte_t i, byte_t j) const;
        Cube& turn(Face f); 
        bool isSolved() const; 
};


} // namespace rc


std::ostream& operator << (std::ostream&, rc::Cube const&);


#endif