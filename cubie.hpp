#ifndef CUBIE_HPP
#define CUBIE_HPP


#include "cube-defs.hpp"
#include "coord.hpp"


namespace rc {


struct Cubie {
    PieceType type; // corner, edges or center
    byte_t id; // piece id 
    byte_t o; // orientation 

    Cubie(PieceType p_type, byte_t p_id, byte_t p_o):
        type(p_type), 
        id(p_id),
        o(p_o)
    {}
};


/**
 * @brief Cube representation as a set of Cubie. Cubie represents differents piece type
 */
class CubieLevel
{
    private:
        Coord &m_coord;
    public:
        CubieLevel(Coord &);
        Cubie at(Cubie const) const; 
};

} // namespace rc 


#endif 