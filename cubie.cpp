#include "cubie.hpp"


namespace rc {

CubieLevel::CubieLevel(Coord &coord):
    m_coord(coord)
{}

 Cubie CubieLevel::at(Cubie const c) const
 {
    (void)c; 
    return Cubie(EDGE, 0, 0); 
 }

} // namespace rc