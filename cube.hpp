#ifndef CUBE_HPP
#define CUBE_HPP


#include "cube-defs.hpp"
#include "facelet.hpp"

#include <iostream>


namespace rc {


/// @brief Implementation of a real world rubik's cube object.
class Cube 
{
    private:
        FaceletLevel m_facelets;
        CubieLevel m_cubies; 
        Coord m_coord, m_moveTable[NB_FACE]; 
        Color m_scheme[NB_FACE];
    public:
        Cube(); 
        Color at(Face f, byte_t i, byte_t j) const;
        Cube& turn(Face f); 
        bool isSolved() const; 
};


} // namespace rc


std::ostream& operator << (std::ostream&, rc::Cube const&);


#endif