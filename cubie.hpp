#ifndef CUBIE_HPP
#define CUBIE_HPP


#include "cube-defs.hpp"


namespace rc {


struct Coord; // opaque decl of coord


struct Cubie {
    PieceType type; // corner, edges or center
    byte_t id; // piece id 
    byte_t o; // orientation 
};


/**
 * @brief Cube representation as a set of Cubie. Cubie represents differents piece type
 *  
 */
class CubieLevel
{
    private:
        Coord m_coord;
    public:

};

} // namespace rc 


#endif 